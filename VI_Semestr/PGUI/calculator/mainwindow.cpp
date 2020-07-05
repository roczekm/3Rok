#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digitPressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digitPressed()));

    connect(ui->pushButton_point,SIGNAL(released()),this,SLOT(pointPressed()));
    connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(plusMinusPressed()));
    connect(ui->pushButton_procent,SIGNAL(released()),this,SLOT(procentPressed()));
    connect(ui->pushButton_fraction,SIGNAL(released()),this,SLOT(fractionPressed()));
    connect(ui->pushButton_sqrt,SIGNAL(released()),this,SLOT(sqrtPressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(mathButtonPressed()));

    connect(ui->pushButton_equal,SIGNAL(released()),this,SLOT(equalPressed()));

    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(clearPressed()));
    connect(ui->pushButton_clearE,SIGNAL(released()),this,SLOT(clearEPressed()));

    pointAdded=false;
    addPressed=false;
    subPressed=false;
    multPressed=false;
    divPressed=false;
    equalClicked=false;
    firstNumber=0.0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitPressed(){

    QPushButton * button =(QPushButton*)sender();

    double temp;
    QString newValue;
    if(equalClicked){
        ui->label->setText("0");
        equalClicked=false;
    }

    if(pointAdded && button->text()=="0"){
    newValue=ui->label->text()+button->text();
    }else{
      temp=(ui->label->text()+button->text()).toDouble();

      newValue=QString::number(temp,'g',15);
    }

    ui->label->setText(newValue);



}
void MainWindow::pointPressed(){

    if(!pointAdded){
        pointAdded = true;
    ui->label->setText(ui->label->text()+'.');

    }

}

void MainWindow::plusMinusPressed(){

    double temp;
    QString newValue;

    temp=(ui->label->text().toDouble())*(-1);

    newValue=QString::number(temp,'g',15);

    if(newValue.contains('.')){
        pointAdded=true;
    }
    ui->label->setText(newValue);


}

void MainWindow::procentPressed(){

   /* double temp;
    QString newValue;

    temp=(ui->label->text().toDouble())*0.01;
    newValue=QString::number(temp,'g',15);
    ui->label->setText(newValue);*/

    double temp;
    QString newValue;

    temp=(ui->label->text().toDouble())*firstNumber*0.01;


    newValue=QString::number(temp,'g',15);
    ui->label->setText(newValue);
    if(newValue.contains('.')){
        pointAdded=true;
    }
    equalClicked=true;


}
void MainWindow::mathButtonPressed(){

    pointAdded=false;
    addPressed=false;
    subPressed=false;
    multPressed=false;
    divPressed=false;

    QPushButton * button =(QPushButton*)sender();
    firstNumber=ui->label->text().toDouble();

    if(button->text()=='+'){
        addPressed=true;
    }else if(button->text()=='-'){
        subPressed=true;
    }else if(button->text()=='*'){
        multPressed=true;
    }else if(button->text()=='/'){
        divPressed=true;
    }
    ui->label->setText("");
    QString temp=QString::number(firstNumber,'g',15);
    ui->label_2->setText(temp+button->text());

}
void MainWindow::equalPressed(){

    double temp;
    QString newValue;

    temp=(ui->label->text().toDouble());
    if(addPressed){
        temp+=firstNumber;
    }else if(subPressed){
        temp=firstNumber-temp;
    }else if(multPressed){
        temp=firstNumber*temp;
    }else if(divPressed){
        temp=firstNumber/temp;
    }

    addPressed=false;
    subPressed=false;
    multPressed=false;
    divPressed=false;
    firstNumber=0.0;
    newValue=QString::number(temp,'g',15);
    ui->label->setText(newValue);
    ui->label_2->setText("");
    equalClicked=true;

}

void MainWindow::clearPressed(){
    pointAdded=false;
    addPressed=false;
    subPressed=false;
    multPressed=false;
    divPressed=false;
    equalClicked=false;
    firstNumber=0.0;
    ui->label->setText("0");
    ui->label_2->setText("");


}


void MainWindow::clearEPressed(){

    ui->label->setText("0");

}

void MainWindow:: sqrtPressed(){
    double temp;
    QString newValue;

    temp=sqrt(ui->label->text().toDouble());
    newValue=QString::number(temp,'g',15);
    if(newValue.contains('.')){
        pointAdded=true;
    }
    ui->label->setText(newValue);
    equalClicked=true;



}
void MainWindow:: fractionPressed(){

    double temp;
    QString newValue;


    temp= 1/(ui->label->text().toDouble());
    newValue=QString::number(temp,'g',15);
    if(newValue.contains('.')){
        pointAdded=true;
    }
    ui->label->setText(newValue);
    equalClicked=true;

}
