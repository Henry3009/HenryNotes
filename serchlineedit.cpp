#include "serchlineedit.h"

SerchLineEdit::SerchLineEdit(QWidget *parent):QLineEdit(parent)
{
    m_initContent = "搜索笔记列表...";
    this->setText(m_initContent);
    this->setFixedHeight(50);
}

//----------------
//用焦点进入退出事件实现hint和清空图标的动态变化
//----------------
void SerchLineEdit::focusInEvent(QFocusEvent *event)
{
    if(m_initContent == this->text())
    {
        this->setText("");
        this->setClearButtonEnabled(true);   //添加清空图标
    }
}

void SerchLineEdit::focusOutEvent(QFocusEvent *event)
{
    if("" == this->text())
    {
        this->setText(m_initContent);
        this->setClearButtonEnabled(false);   //去除清空图标
    }
}
