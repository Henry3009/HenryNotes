#include "memorymanagercontrol.h"

MemoryManagerControl::MemoryManagerControl(QObject *parent) : QObject(parent)
{
    m_widgetManager.clear();
}

//----------------
//释放所有未释放的widget内存
//----------------
void MemoryManagerControl::clear()
{
    foreach(QWidget *widget, m_widgetManager)
    {
        if(nullptr != widget)
        {
            delete widget;
            widget = nullptr;
        }
    }
}
