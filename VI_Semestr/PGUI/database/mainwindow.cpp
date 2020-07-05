#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    mdb = QSqlDatabase::addDatabase("QSQLITE", "bazatestowa");
    mdb.setDatabaseName(":memory:");
    if (!mdb.open())
    {

    }
    QSqlQuery query(mdb);
    query.exec("create table osoba (id integer primary key AUTOINCREMENT, "
               "imie varchar(20), nazwisko varchar(20))");

    query.exec("create table ksiazka (id integer primary key AUTOINCREMENT, "
               "autor varchar(60), tytul varchar(60),id_osoba int)");


    query.exec("insert into osoba values(1, 'Jan', 'Kowalski')");
    query.exec("insert into osoba values(2, 'Mariusz', 'Nowak')");
    query.exec("insert into osoba values(3, 'Krzysztof', 'Nowak')");
    query.exec("insert into osoba values(4, 'Robert', 'Kowalski')");
    query.exec("insert into osoba values(5, 'Marek', 'Cybulski')");
    query.exec("insert into osoba values(6, 'Wacek', 'Nowak')");

    query.exec("insert into ksiazka values(1, 'Stephen Prata', 'Jezyk C++. Szkola programowania', 1)");
    query.exec("insert into ksiazka values(2, 'David Natingga', 'Algorytmy Data Science',NULL)");
    query.exec("insert into ksiazka values(3, 'Mark Lutz', 'Python. Wprowadzenie', NULL)");

    ui->osobyBox->addItem("Jan Kowalski");
    ui->osobyBox->addItem("Mariusz Nowak");
    ui->osobyBox->addItem("Krzysztof Nowak");
    ui->osobyBox->addItem("Robert Kowalski");
    ui->osobyBox->addItem("Marek Cybulski");
    ui->osobyBox->addItem("Wacek Nowak");

    ui->osobyBox2->addItem("Jan Kowalski");
    ui->osobyBox2->addItem("Mariusz Nowak");
    ui->osobyBox2->addItem("Krzysztof Nowak");
    ui->osobyBox2->addItem("Robert Kowalski");
    ui->osobyBox2->addItem("Marek Cybulski");
    ui->osobyBox2->addItem("Wacek Nowak");

    ui->ksiazkiBox->addItem("Jezyk C++. Szkola programowania");
    ui->ksiazkiBox->addItem("Algorytmy Data Science");
    ui->ksiazkiBox->addItem("Python. Wprowadzenie");

    ui->ksiazkiBox2->addItem("Algorytmy Data Science");
    ui->ksiazkiBox2->addItem("Python. Wprowadzenie");

    ui->wypozyczeniaBox->addItem("Jezyk C++. Szkola programowania");




    showAll();







}

MainWindow::~MainWindow()
{
    this->mdb.close();
    QSqlDatabase::removeDatabase(mdb.connectionName());
    delete ui;
}


void MainWindow::showAll(){

    wyswietlCzytelnikow();
    wyswietlKsiazki();
    wyswietlWypozyczenia();


}



void MainWindow:: wyswietlCzytelnikow(){

    QSqlQuery query("select * from osoba", mdb);
    QString temp;
    while(query.next())
    {

        for(int i= 0; i < query.record().count(); i++)
        {

            temp+=((const char*)query.value(i).toString().toLatin1());
            temp+=" ";
        }

        temp+="\n";
    }
    ui->czytelnicyLabel->setText(temp);

    query.finish();


}

void MainWindow:: wyswietlKsiazki(){

    QSqlQuery query("select id,autor,tytul from ksiazka", mdb);
    QString temp;
    while(query.next())
    {

        for(int i= 0; i < query.record().count(); i++)
        {

            temp+=((const char*)query.value(i).toString().toLatin1());
            temp+=" ";
        }
        temp+="\n";
    }
    ui->ksiazkiLabel->setText(temp);
    query.finish();

}

void MainWindow:: wyswietlWypozyczenia(){

    QSqlQuery query("select ksiazka.autor,ksiazka.tytul,osoba.imie,osoba.nazwisko from ksiazka INNER JOIN osoba ON ksiazka.id_osoba=osoba.id  WHERE id_osoba>0", mdb);
    QString temp;
    while(query.next())
    {

        for(int i= 0; i < query.record().count(); i++)
        {

            temp+=((const char*)query.value(i).toString().toLatin1());
            temp+=" ";
        }

        temp+="\n";
    }
    ui->WypozyczeniaLabel->setText(temp);
    query.finish();

}


void MainWindow::on_osobaDodaj_clicked()
{
    QString imie = ui->imieEdit->text();
    QString nazwisko = ui->nazwiskoEdit->text();

    if(imie != "" && nazwisko != "")
    {

        QSqlQuery query (mdb);

        query.exec("INSERT INTO osoba (imie,nazwisko) VALUES ('"+imie+"', '"+nazwisko+"')");

    }

    ui->osobyBox->addItem(QString(imie+" "+nazwisko));
    ui->osobyBox2->addItem(QString(imie+" "+nazwisko));
    ui->imieEdit->setText("");
    ui->nazwiskoEdit->setText("");

    showAll();


}



void MainWindow::on_pushButton_clicked()
{


    QString temp = ui->osobyBox->currentText();


    QStringList myStringList = temp.split(' ');



    if(myStringList.first() != "" && myStringList.last() != "") {

        QSqlQuery query (mdb);

        query.exec("DELETE FROM osoba WHERE imie='"+myStringList.first()+"' AND nazwisko = '"+myStringList.last()+"'");
    }


    ui->osobyBox->removeItem(ui->osobyBox->currentIndex());
    ui->osobyBox2->removeItem(ui->osobyBox->currentIndex());

    showAll();

}

void MainWindow::on_ksiazkaDodaj_clicked()
{
    QString autor = ui->autorEdit->text();
    QString tytul = ui->tytulEdit->text();

    if(autor != "" && tytul != "")
    {

        QSqlQuery query (mdb);

        query.exec("INSERT INTO ksiazka (autor,tytul,id_osoba) VALUES ('"+autor+"', '"+tytul+"',NULL)");

    }

    ui->ksiazkiBox->addItem(tytul);
    ui->ksiazkiBox2->addItem(tytul);
    ui->autorEdit->setText("");
    ui->tytulEdit->setText("");

    showAll();



}

void MainWindow::on_ksiazkaUsun_clicked()
{

    QString temp = ui->ksiazkiBox->currentText();





    if(temp!= "" ) {

        QSqlQuery query (mdb);

        query.exec("DELETE FROM ksiazka WHERE tytul='"+temp+"'");
    }
    ui->ksiazkiBox->removeItem(ui->ksiazkiBox->currentIndex());

    showAll();

}

void MainWindow::on_wypozyczButton_clicked()
{

    QString temp = ui->osobyBox2->currentText();
    QStringList myStringList = temp.split(' ');
    QString temp2 = ui->ksiazkiBox2->currentText();

    if(myStringList.first() != "" && myStringList.last() != "" &&temp2!= "") {


        QSqlQuery query (mdb);

        query.exec("UPDATE ksiazka SET id_osoba= (SELECT id FROM osoba WHERE imie='"+myStringList.first()+"' AND nazwisko = '"+myStringList.last()+"') WHERE ksiazka.tytul='"+temp2+"'");


    }

    ui->ksiazkiBox2->removeItem(ui->ksiazkiBox2->currentIndex());
    ui->wypozyczeniaBox->addItem(temp2);

    showAll();

}

void MainWindow::on_oddajButton_clicked()
{
    QString temp2 = ui->wypozyczeniaBox->currentText();

    if(temp2!= "" ) {

        QSqlQuery query (mdb);

        query.exec("UPDATE ksiazka SET id_osoba=NULL WHERE tytul='"+temp2+"'");
    }

    ui->ksiazkiBox2->addItem(temp2);
    ui->wypozyczeniaBox->removeItem(ui->wypozyczeniaBox->currentIndex());

    showAll();

}
