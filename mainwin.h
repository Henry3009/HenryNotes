#ifndef MAINWIN_H
#define MAINWIN_H

#include "background.h"
#include "notecard.h"
#include "serchlineedit.h"

#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

#define WIDTH_OF_ADDNOTEBTNBG 100   //添加笔记按钮背景的宽度
#define SIZE_OF_ICON 50             //图标的大小

class MainWin : public QSplitter
{
    Q_OBJECT
public:
    MainWin();
    ~MainWin();

private:
    void setUi();                   //UI布局
    void addNewToNoteList();        //在笔记列表中添加新的一项
    void updateNoteCardListShow(NoteCard *newNoteCard);  //更新笔记列表显示

private slots:
    void slotAddBtnClicked();

private:
    Background *m_leftBg;               //主窗口左侧背景板
    Background *m_rightBg;              //主窗口右侧背景板
    QVBoxLayout *m_lBgLayout;           //左背景板布局
    SerchLineEdit *m_serchEdit;         //笔记列表搜索框
    Background *m_addNoteBtnBg;         //添加笔记按钮背景
    QPushButton *m_addNoteBtn;          //添加笔记按钮
    QVBoxLayout *m_noteCardListLayout;  //笔记卡片列表布局Layout
    QList<NoteCard *> m_noteCardList;   //笔记列表
};

#endif // MAINWIN_H
