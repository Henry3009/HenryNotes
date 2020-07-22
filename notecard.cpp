#include "notecard.h"

NoteCard::NoteCard(QString headline, QString cTime, QString fTime, NoteEditWidget *noteWidget, QWidget *parent)
    :QTextBrowser(parent),m_noteWidget(noteWidget),m_noteName(headline),m_createDate(cTime),m_fixDate(fTime)
{
    //作为笔记卡片背景板，只读，设置笔记卡片背景颜色
    this->setReadOnly(true);
    this->setFixedHeight(WIDTH_OF_NOTECARDLISTBG);

    //UI布局和数据初始化
    setUI();

    //数据初始化
    initData(m_noteName,m_createDate,m_fixDate);

    this->installEventFilter(this);
}

//----------------
//数据初始化
//----------------
void NoteCard::initData(QString headline, QString cTime, QString fTime)
{
    if(cTime.isEmpty()||fTime.isEmpty())
    {
        m_noteName = "New Note";
        m_createDate = QDateTime::currentDateTime().toString("创建时间：yyyy年MM月dd日 HH:mm:ss");
        m_fixDate = QDateTime::currentDateTime().toString("修改时间：yyyy年MM月dd日 HH:mm:ss");
    }
    m_noteNameLabel->setText(m_noteName);
    m_createDateLabel->setText(m_createDate);
    m_fixDateLabel->setText(m_fixDate);

    this->setProperty("NoteCard",true);
}

void NoteCard::slotchangeHeadLine(const QString &headline)
{
    m_noteName = headline;
    m_noteNameLabel->setText(headline);

    if("" == headline)
    {
       m_noteNameLabel->setText("空标题");
    }
}

QString NoteCard::getFixDate() const
{
    return m_fixDate;
}

void NoteCard::setFixDate(const QString &fixDate)
{
    m_fixDate = fixDate;
}

QString NoteCard::getCreateDate() const
{
    return m_createDate;
}

void NoteCard::setCreateDate(const QString &createDate)
{
    m_createDate = createDate;
}

//----------------
//鼠标点击切换事件
//----------------
bool NoteCard::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if(mouseEvent->button() == Qt::LeftButton)
        {
            emit changeCardAndNoteEdit(this);
            return true;
        }
        QTextBrowser::mousePressEvent(mouseEvent);
    }

    return QTextBrowser::eventFilter(watched,event);
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

//    this->setPalette(p);
}
