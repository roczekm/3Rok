#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mAddThread1("A",300,this)
    ,mAddThread2("BC",400,this)
    ,mAddThread3("D",500,this)
    ,mAddThread4(" ",300,this)
    ,mSubThread(400,this)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    mBuffor="";

    connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(this,SIGNAL(Update()),this,SLOT(UpdateDisplay()),Qt::QueuedConnection);
    connect(ui->spinBox,SIGNAL(valueChanged(int)),&mSubThread,SLOT(ChangeTime(int)),Qt::QueuedConnection);


    mAddThread1.start();
    mAddThread2.start();
    mAddThread3.start();
    mAddThread4.start();
    mSubThread.start();
}

MainWindow::~MainWindow()
{

    mAddThread1.requestInterruption();
    mAddThread2.requestInterruption();
    mAddThread3.requestInterruption();
    mAddThread4.requestInterruption();
    mSubThread.requestInterruption();

    mAddThread1.wait();
    mAddThread2.wait();
    mAddThread3.wait();
    mAddThread4.wait();
    mSubThread.wait();


    delete ui;
}


void MainWindow::AddData(QString text){


    QMutexLocker locker(&mMutex);
    if(mBuffor.size()<500)
    {
    mBuffor += text;
    }
    emit Update();

}

void MainWindow::UpdateDisplay(){
    ui->label->setText(mBuffor);
    ui->progressBar->setValue(mBuffor.size());
}

void MainWindow::RemoveData(){
    QMutexLocker locker(&mMutex);
    mBuffor.remove(0,1);
    emit Update();

}



