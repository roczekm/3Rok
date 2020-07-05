#include "adddatathread.h"
#include "mainwindow.h"

adddatathread::adddatathread(QString text,int time,QObject *parent):
QThread(parent),mText(text),mTime(time){

}

void adddatathread::run(){

    while(!isInterruptionRequested()){
        MainWindow * wnd=dynamic_cast<MainWindow*>(parent());
        wnd->AddData(mText);
        msleep(mTime);
    }
}
