#ifndef SUBDATATHREAD_H
#define SUBDATATHREAD_H
#include <QThread>

class subdatathread:public QThread
{
    Q_OBJECT
public:
    explicit subdatathread(int time,QObject *parent=0);

public slots:
    void ChangeTime(int time);
protected:
    int mTime;
    void run() Q_DECL_OVERRIDE;
};

#endif // SUBDATATHREAD_H
