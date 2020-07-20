#ifndef MEMORYMANAGERCONTROL_H
#define MEMORYMANAGERCONTROL_H

#include <QLayout>
#include <QObject>

class MemoryManagerControl : public QObject
{
    Q_OBJECT
public:
    explicit MemoryManagerControl(QObject *parent = nullptr);

    void appendWidget(QWidget *widget){m_widgetManager.append(widget);}

    void clear();       //释放所有未释放的widget内存

signals:

public slots:

private:
    QList<QWidget *> m_widgetManager;   //控件集合
};

#endif // MEMORYMANAGERCONTROL_H
