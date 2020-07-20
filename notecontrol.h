#ifndef NOTECONTROL_H
#define NOTECONTROL_H

#include "notecard.h"
#include "notemodel.h"

#include <QObject>

//----------------
//用于管理卡片和笔记
//----------------
class NoteControl : public QObject
{
    Q_OBJECT
public:
    explicit NoteControl(QObject *parent = nullptr);

    void appendCard(NoteCard *card){m_noteCardList.append(card); setCurCard(card);} //添加卡片

    NoteCard *getCurCard(){return m_curCard;}                                       //获得当前卡片

    NoteEditWidget *getCurNoteEdit(){return m_curCard->getNoteEdit();}              //获得当前卡片对应的笔记编辑区域

    int getCardCount(){return m_noteCardList.count();}                              //获得已管理卡片个数

    void setCurCard(NoteCard *card){m_curCard = card;}                              //设置当前活动卡片

private:
    void saveAll();                                                                 //保存所有笔记

    void setData(QString headline, QString cTime, QString fTime, QString content);  //设置笔记本Model数据

signals:

public slots:

private:
    QList<NoteCard *> m_noteCardList;           //笔记卡片列表
    NoteCard *m_curCard;                        //当前卡片
    NoteModel m_noteModel;                      //笔记本model
};

#endif // NOTECONTROL_H
