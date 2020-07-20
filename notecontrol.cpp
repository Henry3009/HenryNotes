#include "notecontrol.h"

NoteControl::NoteControl(QObject *parent) : QObject(parent)
{
    m_curCard = nullptr;
}

//----------------
//设置笔记本Model数据
//----------------
void NoteControl::setData(QString headline, QString cTime, QString fTime, QString content)
{
    m_noteModel.setHeadline(headline);
    m_noteModel.setCreateTime(cTime);
    m_noteModel.setFixTime(fTime);
    m_noteModel.setContent(content);
}

//----------------
//保存所有笔记
//----------------
void NoteControl::saveAll()
{
//    setData()
}
