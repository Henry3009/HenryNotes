#ifndef NOTECARD_H
#define NOTECARD_H

#include "noteeditwidget.h"

#include <QLabel>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QDateTime>
#include <QDebug>

#define WIDTH_OF_NOTECARDLISTBG 100     //添加笔记卡片背景的宽度

class NoteCard : public QTextBrowser
{
    Q_OBJECT
public:
    NoteCard(QString headline, QString cTime, QString fTime, NoteEditWidget *noteWidget,QWidget *parent=nullptr);

    void setBackGroundColor(const QColor color);        //背景色设置，接受QColor的RGB颜色

    void setName(QString noteName){m_noteName = noteName;}

    QString getName(){return m_noteName;}

    NoteEditWidget *getNoteEdit(){return m_noteWidget;}

    QString getCreateDate() const;
    void setCreateDate(const QString &createDate);

    QString getFixDate() const;
    void setFixDate(const QString &fixDate);

private:
    void setUI();                                       //UI布局

    void initData(QString headline,QString cTime,QString fTime);                                    //数据初始化

signals:
    void changeCardAndNoteEdit(NoteCard *card);

public slots:
    void slotchangeHeadLine(const QString &headline);

private:
    QString m_noteName;             //笔记标题名称
    QString m_createDate;           //笔记创建时间
    QString m_fixDate;              //笔记修改时间
    QVBoxLayout *m_layout;          //布局Layout
    QLabel *m_noteNameLabel;        //标题Label
    QLabel *m_createDateLabel;      //创建时间Label
    QLabel *m_fixDateLabel;         //修改时间Label
    NoteEditWidget *m_noteWidget;   //卡片对应的笔记本编辑区域

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);

};

#endif // NOTECARD_H
