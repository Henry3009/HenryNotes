#include "notemodel.h"

NoteModel::NoteModel(QObject *parent) : QObject(parent)
{

}

QString NoteModel::content() const
{
    return m_content;
}

void NoteModel::setContent(const QString &content)
{
    m_content = content;
}

QString NoteModel::headline() const
{
    return m_headline;
}

void NoteModel::setHeadline(const QString &headline)
{
    m_headline = headline;
}

QString NoteModel::createTime() const
{
    return m_createTime;
}

void NoteModel::setCreateTime(const QString &createTime)
{
    m_createTime = createTime;
}

QString NoteModel::fixTime() const
{
    return m_fixTime;
}

void NoteModel::setFixTime(const QString &fixTime)
{
    m_fixTime = fixTime;
}
