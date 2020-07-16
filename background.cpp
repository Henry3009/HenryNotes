#include "background.h"
#include <QtDebug>
Background::Background(QWidget *parent):QTextBrowser(parent)
{

    //用于设置背景板背景颜色的画板。
    QPalette p;
    p.setColor(QPalette::Base,Qt::white);

    //作为背景板，只读，设置背景颜色
    this->setReadOnly(true);
    this->setPalette(p);
}

void Background::setBackGroundColor(const QColor color)
{
    QPalette p;
    p.setColor(QPalette::Base,color);

    this->setPalette(p);
}
