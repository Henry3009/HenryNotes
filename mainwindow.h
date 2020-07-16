#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUi();

private:
    Ui::MainWindow *ui;
    QSplitter *m_mainSplitter;
    QFrame *m_leftBg;
    QFrame *m_rightBg;
};

#endif // MAINWINDOW_H
