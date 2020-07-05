#include "subdatathread.h"
#include"mainwindow.h"

subdatathread::subdatathread(int time,QObject *parent):
    QThread(parent),mTime(time)
{

}
void subdatathread::run(){

    while(!isInterruptionRequested()){
        MainWindow * wnd=dynamic_cast<MainWindow*>(parent());
        wnd->RemoveData();
        msleep(mTime);
    }
}

void subdatathread::ChangeTime(int time){
    mTime=time;
}
