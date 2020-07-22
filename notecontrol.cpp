#include "notecontrol.h"

#include <QCoreApplication>
#include <QDateTime>
#include <QDir>

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
    for(int i=0; i<m_noteCardList.count(); ++i)
    {
        setData(m_noteCardList.at(i)->getName(),m_noteCardList.at(i)->getCreateDate(),
                m_noteCardList.at(i)->getFixDate().split("：").at(0) + QDateTime::currentDateTime().toString("：yyyy年MM月dd日 HH:mm:ss"),
                m_noteCardList.at(i)->getNoteEdit()->getContent());

        QMap<QString,QString>::Iterator iterator = m_name_cTimeList.find(m_noteModel.createTime());
        QFile f;
        if(iterator != m_name_cTimeList.end())
        {
            QString filesName = iterator.value();
            f.setFileName(QCoreApplication::applicationDirPath() + "\\" + filesName);
        }
        else
        {
            f.setFileName(QCoreApplication::applicationDirPath() + "\\" +QString::number(QDateTime::currentDateTime().time().msec())+".bin");
        }
        if(!f.open(QIODevice::WriteOnly))
        {
            qDebug()<<"创建保存文件失败";
        }

        QDataStream out(&f);

        out<<QString(m_noteModel.headline());
        out<<QString(m_noteModel.createTime());
        out<<QString(m_noteModel.fixTime());
        out<<QString(m_noteModel.content());
    }
}

QList<QStringList> NoteControl::readData()
{
    QDir d(QCoreApplication::applicationDirPath());
    QStringList filFiliter;
    filFiliter<<"*.bin";
    QStringList files = d.entryList(filFiliter,QDir::Files,QDir::Name);

    QList<QStringList> data;
    for(int i=0; i<files.count(); ++i)
    {
        QFile f(QCoreApplication::applicationDirPath()+"\\"+files.at(i));
        if(!f.open(QIODevice::ReadOnly))
        {
            qDebug()<<"打开"<<files.at(i)<<"文件失败";
        }

        QDataStream out(&f);
        QString headline;
        QString cTime;
        QString fTime;
        QString content;
        out>>headline;
        out>>cTime;
        out>>fTime;
        out>>content;
        QStringList list;
        list<<headline<<cTime<<fTime<<content;
        data.append(list);

        m_name_cTimeList.insert(cTime,files.at(i));
    }

    return data;
}
