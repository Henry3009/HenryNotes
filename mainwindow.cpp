#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUi()
{

//    m_mainSplitter = new QSplitter(Qt::Horizontal,0);
////    m_mainSplitter->insertWidget(0,m_leftBg);
////    m_mainSplitter->insertWidget(1,m_rightBg);

//    QPalette p;
//    p.setColor(QPalette::Window,Qt::red);

//    m_leftBg = new QFrame(m_mainSplitter);
//    m_leftBg->setFixedSize(QSize(100,100));
//    m_leftBg->setPalette(p);
//    m_rightBg = new QFrame(m_mainSplitter);
//    m_rightBg->setFixedSize(QSize(100,100));
//    m_rightBg->setPalette(p);

////    this->layout()->addWidget(new QLabel("Hello"));
////    this->layout()->addWidget(m_mainSplitter);
//    m_mainSplitter->show();
}
