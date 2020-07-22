#ifndef NOTEEDITWIDGET_H
#define NOTEEDITWIDGET_H

#include "memorymanagercontrol.h"

#include <QMouseEvent>
#include <QTextEdit>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <qDebug>
#include <QStatusBar>

#define WIDTH_OF_TITLE 500          //标题栏宽度
#define HEIGHT_OF_TITLE 50          //标题栏高度
#define SIZE_OF_ICON 50             //图标的大小

class NoteEditWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NoteEditWidget(QString headline, QString content, QWidget *parent = nullptr);

    QLineEdit *getHeadLineEdit(){return m_headlineEdit;}

    QString getContent(){return m_contentEdit->toPlainText();}

    ~NoteEditWidget();

private:
    void setUI();

    void setData(QString headline, QString content);

signals:

public slots:


private:
    QVBoxLayout *m_layout;                  //主Layout
    QLineEdit *m_headlineEdit;              //标题栏输入框
    QTextEdit *m_contentEdit;               //内容输入框
    QStatusBar *m_statusBar;                //笔记状态显示栏

    MemoryManagerControl m_memoryManager;   //内存管理
};

#endif // NOTEEDITWIDGET_H
