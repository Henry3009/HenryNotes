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
    m_rightBg = new Background(this);

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
    m_noteCardListLayout = new QVBoxLayout(m_leftBg);
    m_lBgLayout->addSpacing(10);
    m_lBgLayout->addLayout(m_noteCardListLayout);

    /*信号与槽*/
    connect(m_addNoteBtn,SIGNAL(clicked()),this,SLOT(slotAddBtnClicked()));
}

void MainWin::addNewToNoteList()
{
    NoteCard *newNoteCard = new NoteCard(this->m_leftBg);
    newNoteCard->setBackGroundColor(QColor(255,178,115));
    m_noteCardList.append(newNoteCard);
    updateNoteCardListShow(newNoteCard);
}

//----------------
//更新笔记列表显示
//----------------
void MainWin::updateNoteCardListShow(NoteCard *newNoteCard)
{
    m_noteCardListLayout->insertWidget(0,newNoteCard);
}

//----------------
//添加新的笔记
//----------------
void MainWin::slotAddBtnClicked()
{
    //在笔记列表中添加新的一项
    addNewToNoteList();

    //打开新的笔记
}
