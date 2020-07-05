#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QString>
#include <QFileInfo>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



protected:
    void showAll();
    void wyswietlCzytelnikow();
    void wyswietlKsiazki();
    void wyswietlWypozyczenia();

private slots:
    void on_osobaDodaj_clicked();

    void on_pushButton_clicked();

    void on_ksiazkaDodaj_clicked();

    void on_ksiazkaUsun_clicked();

    void on_wypozyczButton_clicked();

    void on_oddajButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mdb;

};
#endif // MAINWINDOW_H
