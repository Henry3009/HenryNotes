#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QMouseEvent>
#include <QTextBrowser>
#include <QTextEdit>

//----------------
//Background作为界面的各种背景板
//用QTextBrowser代替QTextEdit作为父类避免了鼠标变成光标的尴尬情况
//----------------
class Background : public QTextBrowser
{
public:
    Background(QWidget *parent = nullptr);

    void setBackGroundColor(const QColor color);
};

#endif // BACKGROUND_H
