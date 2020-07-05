#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include<subdatathread.h>
#include <adddatathread.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddData(QString text);
    void RemoveData();

signals:
    void Update();


public slots:
    void UpdateDisplay();

protected:
    QString mBuffor;
    adddatathread mAddThread1;
    adddatathread mAddThread2;
    adddatathread mAddThread3;
    adddatathread mAddThread4;

    subdatathread mSubThread;

private:
    Ui::MainWindow *ui;
    mutable QMutex mMutex;
};
#endif // MAINWINDOW_H
