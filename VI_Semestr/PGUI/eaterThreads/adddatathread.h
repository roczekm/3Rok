#ifndef ADDDATATHREAD_H
#define ADDDATATHREAD_H
#include <QThread>

class adddatathread:public QThread
{
    Q_OBJECT
public:
    explicit adddatathread(QString text,int time,QObject *parent=0);


protected:
    QString mText;
    int mTime;
    void run() Q_DECL_OVERRIDE;

};

#endif // ADDDATATHREAD_H
