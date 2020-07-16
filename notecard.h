#ifndef NOTECARD_H
#define NOTECARD_H

#include <QLabel>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QDateTime>
#include <QDebug>

#define WIDTH_OF_NOTECARDLISTBG 100     //添加笔记卡片背景的宽度

class NoteCard : public QTextBrowser
{
public:
    NoteCard(QWidget *parent=nullptr);
    void setBackGroundColor(const QColor color);        //背景色设置，接受QColor的RGB颜色

private:
    void setUI();                                       //UI布局
    void initData();                                    //数据初始化

private:
    QString m_noteName;         //笔记标题名称
    QString m_createDate;       //笔记创建时间
    QString m_fixDate;          //笔记修改时间
    QVBoxLayout *m_layout;      //布局Layout
    QLabel *m_noteNameLabel;    //标题Label
    QLabel *m_createDateLabel;  //创建时间Label
    QLabel *m_fixDateLabel;     //修改时间Label
};

#endif // NOTECARD_H
