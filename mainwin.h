#ifndef MAINWIN_H
#define MAINWIN_H

#include "background.h"
#include "notecard.h"
#include "notecontrol.h"
#include "noteeditwidget.h"
#include "serchlineedit.h"

#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

#define WIDTH_OF_ADDNOTEBTNBG 100   //添加笔记按钮背景的宽度
#define SIZE_OF_ICON 50             //图标的大小

class MainWin : public QSplitter
{
    Q_OBJECT
public:
    MainWin();

    ~MainWin();

private:
    void setUi();                                           //UI布局

    void addNewCardAndNote(QString headline = "New Note", QString cTime = "", QString fTime = "", QString content = "");    //添加新的笔记和卡片

    void readData();                                        //读取数据

    void addNote(QString headline = "New Note", QString cTime = "", QString fTime = "", QString content = "");              //添加笔记（非空白笔记）

private slots:
    void slotAddBtnClicked();                               //添加笔记（空白）

    void slotChangeNoteShow(NoteCard *card);

protected:
    void closeEvent(QCloseEvent *event);                    //关闭事件，关闭时保存所有笔记

private:
    Background *m_leftBg;                       //主窗口左侧背景板
    Background *m_rightBg;                      //主窗口右侧背景板
    QVBoxLayout *m_lBgLayout;                   //左背景板布局
    QVBoxLayout *m_rBgLayout;                   //右背景板布局
    SerchLineEdit *m_serchEdit;                 //笔记列表搜索框
    Background *m_addNoteBtnBg;                 //添加笔记按钮背景
    QPushButton *m_addNoteBtn;                  //添加笔记按钮
    QVBoxLayout *m_noteCardListLayout;          //笔记卡片列表布局Layout
    NoteControl m_noteControl;                 //卡片和笔记管理
    MemoryManagerControl m_memoryManager;       //组件内存管理

};

#endif // MAINWIN_H
