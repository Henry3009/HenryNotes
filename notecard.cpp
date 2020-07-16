#include "notecard.h"

NoteCard::NoteCard(QWidget *parent):QTextBrowser(parent)
{
    //用于设置笔记卡片背景颜色的画板。
    QPalette p;
    p.setColor(QPalette::Base,Qt::white);

    //作为笔记卡片背景板，只读，设置笔记卡片背景颜色
    this->setReadOnly(true);
    this->setPalette(p);
    this->setFixedHeight(WIDTH_OF_NOTECARDLISTBG);

    //UI布局和数据初始化
    setUI();

    //数据初始化
    initData();
}

//----------------
//数据初始化
//----------------
void NoteCard::initData()
{
    m_noteName = "New Note";
    m_createDate = QDateTime::currentDateTime().toString("创建时间：yyyy年MM月dd日 HH:mm:ss");
    m_fixDate = QDateTime::currentDateTime().toString("修改时间：yyyy年MM月dd日 HH:mm:ss");
    m_noteNameLabel->setText(m_noteName);
    m_createDateLabel->setText(m_createDate);
    m_fixDateLabel->setText(m_fixDate);
}

//----------------
//UI布局
//----------------
void NoteCard::setUI()
{
    m_noteNameLabel = new QLabel;
    m_createDateLabel = new QLabel;
    m_fixDateLabel = new QLabel;

    m_layout = new QVBoxLayout(this);
    m_layout->setAlignment(Qt::AlignLeft);
    m_layout->addWidget(m_noteNameLabel);
    m_layout->addWidget(m_createDateLabel);
    m_layout->addWidget(m_fixDateLabel);
}

//----------------
//背景色设置，接受QColor的RGB颜色
//----------------
void NoteCard::setBackGroundColor(const QColor color)
{
    QPalette p;
    p.setColor(QPalette::Base,color);

    this->setPalette(p);
}
