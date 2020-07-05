#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QtGui>

#include <complex>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:

    void paintEvent(QPaintEvent * e) ;

    int MandelbrotSet(int x, int y);
    int widthW;
    int heightW;
};
#endif // MAINWINDOW_H
