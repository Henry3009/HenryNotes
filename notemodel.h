#ifndef NOTEMODEL_H
#define NOTEMODEL_H

#include <QObject>

class NoteModel : public QObject
{
    Q_OBJECT
public:
    explicit NoteModel(QObject *parent = nullptr);

    QString content() const;
    void setContent(const QString &content);

    QString headline() const;
    void setHeadline(const QString &headline);

    QString createTime() const;
    void setCreateTime(const QString &createTime);

    QString fixTime() const;
    void setFixTime(const QString &fixTime);

signals:

public slots:

private:
    QString m_headline;
    QString m_createTime;
    QString m_fixTime;
    QString m_content;
};

#endif // NOTEMODEL_H
