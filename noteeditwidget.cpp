#include "noteeditwidget.h"

NoteEditWidget::NoteEditWidget(QWidget *parent) : QWidget(parent)
{
    QPalette p;
    p.setColor(QPalette::Background,Qt::white);
    setAutoFillBackground(true);
    setPalette(p);

    setUI();
    setData();
}

NoteEditWidget::~NoteEditWidget()
{
    m_memoryManager.clear();
}

//----------------
//UI布局
//----------------
void NoteEditWidget::setUI()
{
    //设置笔记编辑区域的主Layout
    m_layout = new QVBoxLayout();
    this->setLayout(m_layout);
    m_layout->setAlignment(Qt::AlignLeft);

    //标题输入框
    QHBoxLayout *m_headLayout = new QHBoxLayout();                          //标题栏Layout
    m_headLayout->setAlignment(Qt::AlignLeft);
    m_headlineEdit = new QLineEdit(this);                                   //标题输入栏
    m_headlineEdit->setFixedSize(QSize(WIDTH_OF_TITLE,HEIGHT_OF_TITLE));
    m_headLayout->addWidget(m_headlineEdit);
    QHBoxLayout *m_headBtnLayout = new QHBoxLayout();                       //标题按钮Layout
    m_headBtnLayout->setAlignment(Qt::AlignRight);

    //状态栏
    m_statusBar = new QStatusBar(this);
    m_statusBar->showMessage("New Note", 2000);
    m_headLayout->addWidget(m_statusBar);
    QPalette p;
    p.setColor(QPalette::WindowText,Qt::gray);
    m_statusBar->setPalette(p);                                             //设置状态栏文字颜色

    //删除按钮 操作按钮
    QPushButton *delBtn = new QPushButton;                                  //删除笔记按钮
    delBtn->setIcon(QIcon("DeleteNote.png"));
    delBtn->setIconSize(QSize(SIZE_OF_ICON,SIZE_OF_ICON));
    delBtn->setFlat(true);
    QPushButton *settingBtn = new QPushButton("...");                       //删除笔记按钮
    settingBtn->setFlat(true);
    m_headBtnLayout->addWidget(delBtn);
    m_headBtnLayout->addWidget(settingBtn);
    m_headLayout->addLayout(m_headBtnLayout);
    m_layout->addLayout(m_headLayout);

    //文本编辑区
    m_contentEdit = new QTextEdit(this);
    m_layout->addWidget(m_contentEdit);

    //管理控件
    m_memoryManager.appendWidget(delBtn);
    m_memoryManager.appendWidget(settingBtn);

    //信号与信号槽
}

void NoteEditWidget::setData()
{
    m_headlineEdit->setText("New Note");
}


