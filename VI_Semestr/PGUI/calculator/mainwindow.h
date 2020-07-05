#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void digitPressed();
    void pointPressed();
    void plusMinusPressed();
    void procentPressed();
    void mathButtonPressed();
    void equalPressed();
    void clearPressed();
    void clearEPressed();
    void sqrtPressed();
    void fractionPressed();

private:
    bool pointAdded;
    bool addPressed;
    bool subPressed;
    bool multPressed;
    bool divPressed;
    bool equalClicked;
    double firstNumber;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
