#include "mainwin.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

void setStyle(const char* filePath)
{
    QFile qss(filePath);
    if(qss.open(QIODevice::ReadOnly))
    {
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
    else
    {
        QMessageBox::warning(nullptr,"警告","加载qss失败！");
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    setStyle("c1.qss");

    MainWin m;
    m.show();
    return a.exec();
}
