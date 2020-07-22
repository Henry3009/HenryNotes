#include "mainwin.h"

MainWin::MainWin()
{
    //继承QSplitter的主窗口设置
    this->setOrientation(Qt::Horizontal);   //设置分割方向
    this->setFixedSize(QSize(1200,1000));   //默认窗口大小

    //设置最大化和窗口按钮
    this->showMaximized();
    setWindowFlags(Qt::Dialog|Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    //设置UI布局
    setUi();
//    m_noteControl = NoteControl();

    readData();
}

MainWin::~MainWin()
{
}

//----------------
//UI布局
//----------------
void MainWin::setUi()
{
    /*背景板和分割线布局*/
    //左右背景板设置
    m_leftBg = new Background(this);
    m_leftBg->setObjectName("LeftBackground");
    m_rightBg = new Background(this);
    m_rightBg->setObjectName("RightBackground");

    //设置分割线比例为1：4
    this->setStretchFactor(0,1);
    this->setStretchFactor(1,3);

    /*搜索框布局*/
    //设置搜索框的布局
    m_lBgLayout = new QVBoxLayout(m_leftBg);
    m_leftBg->setLayout(m_lBgLayout);
    m_lBgLayout->setAlignment(Qt::AlignTop);
    m_serchEdit = new SerchLineEdit();
    m_lBgLayout->addWidget(m_serchEdit);

    //搜索框和添加笔记按钮之间 加大距离
    m_lBgLayout->addSpacing(10);

    /*添加笔记按钮布局*/
    //添加笔记按钮背景布局
    m_addNoteBtnBg = new Background(m_leftBg);
    m_addNoteBtnBg->setFixedHeight(WIDTH_OF_ADDNOTEBTNBG);
//    m_addNoteBtn->setFixedSize(QSize(m_addNoteBtnBg->width(),m_addNoteBtnBg->height()));
    m_addNoteBtnBg->setBackGroundColor(Qt::gray);
    m_lBgLayout->addWidget(m_addNoteBtnBg);

    //按钮背景Layout，添加按钮
    m_addNoteBtnBg->setLayout(new QVBoxLayout());
    QIcon delIcon;
    delIcon.addFile("AddNote.png");
    m_addNoteBtn = new QPushButton(m_addNoteBtnBg);
    m_addNoteBtn->setIcon(delIcon);
    m_addNoteBtn->setFixedSize(QSize(SIZE_OF_ICON,SIZE_OF_ICON));
    m_addNoteBtn->setFlat(true);                                    //设置按钮背景透明
    m_addNoteBtn->setIconSize(QSize(SIZE_OF_ICON,SIZE_OF_ICON));    //设置按钮图标大小
    m_addNoteBtnBg->layout()->addWidget(m_addNoteBtn);
    m_addNoteBtnBg->layout()->setAlignment(Qt::AlignCenter);

    /*添加笔记列表布局*/
    m_noteCardListLayout = new QVBoxLayout();
    m_lBgLayout->addSpacing(10);
    m_lBgLayout->addLayout(m_noteCardListLayout);

    /*信号与槽*/
    connect(m_addNoteBtn,SIGNAL(clicked()),this,SLOT(slotAddBtnClicked()));

    //右背景板layout
    m_rBgLayout = new QVBoxLayout(m_rightBg);
    m_rBgLayout->setAlignment(Qt::AlignTop);
}

//----------------
//添加新的笔记和卡片
//----------------
void MainWin::addNewCardAndNote(QString headline,QString cTime,QString fTime,QString content)
{
    //添加笔记
    NoteEditWidget *w = new NoteEditWidget(headline,content,m_rightBg);

    //添加卡片
    NoteCard *newNoteCard = new NoteCard(headline,cTime,fTime,w,this->m_leftBg);
    newNoteCard->setBackGroundColor(QColor(255,178,115));


    if(0 != m_noteControl.getCardCount())
    {
        //隐藏界面上旧的编辑区域
        m_noteControl.getCurNoteEdit()->hide();
    }
    //管理卡片，更新编辑区域
    m_noteControl.appendCard(newNoteCard);

    //添加新的编辑区域
    m_rBgLayout->addWidget(m_noteControl.getCurNoteEdit());

    //给卡片和编辑区域添加布局,添加笔记和卡片的顺序不能颠倒，先笔记再卡片
    m_noteCardListLayout->insertWidget(0,m_noteControl.getCurCard());

    //信号与槽
    //笔记标题与对应卡片标题的信号槽交互
    connect(w->getHeadLineEdit(),&QLineEdit::textChanged,
            newNoteCard,&NoteCard::slotchangeHeadLine);
    //卡片和卡片管理
    connect(newNoteCard,&NoteCard::changeCardAndNoteEdit,
            this,&MainWin::slotChangeNoteShow);
}

//----------------
//读数据
//----------------
void MainWin::readData()
{
    QList<QStringList> data = m_noteControl.readData();

    for(int i=0; i<data.count(); ++i)
    {
        QString headline;
        QString cTime;
        QString fTime;
        QString content;
        headline = data.at(i).at(0);
        cTime = data.at(i).at(1);
        fTime = data.at(i).at(2);
        content = data.at(i).at(3);

        if(headline.isEmpty()||cTime.isEmpty()||fTime.isEmpty())
        {
            continue;
        }

        addNote(headline,cTime,fTime,content);
    }
}

//----------------
//添加笔记（非空白笔记）
//----------------
void MainWin::addNote(QString headline, QString cTime, QString fTime, QString content)
{
    addNewCardAndNote(headline,cTime,fTime,content);
}

//----------------
//添加新的笔记
//----------------
void MainWin::slotAddBtnClicked()
{
    addNewCardAndNote();
}

//----------------
//切换笔记和卡片
//----------------
void MainWin::slotChangeNoteShow(NoteCard *card)
{
    if(card == m_noteControl.getCurCard())
    {
        return;
    }

    m_noteControl.getCurNoteEdit()->hide();//隐藏界面上旧的编辑区域

    m_noteControl.setCurCard(card);//管理卡片，更新编辑区域

    m_noteControl.getCurNoteEdit()->show();//显示当前编辑区域
}

void MainWin::closeEvent(QCloseEvent *event)
{
    m_noteControl.saveAll();
}
