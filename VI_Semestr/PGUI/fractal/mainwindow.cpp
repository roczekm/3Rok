#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,widthW(1280)
    ,heightW(720)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen;

    for(int i = 0; i <widthW; i++){
        for(int j = 0; j <  heightW; j++){

            int temp = MandelbrotSet( i,j );


             QColor color(temp,0,temp);

            pen.setColor(color);
            painter.setPen(pen);
            painter.drawPoint(QPoint(i,j));
        }
    }

}




int MainWindow::MandelbrotSet(int x, int y)
{



    double rangey=1.0+1.0;

   double rangex=1.0+2.0;



    std::complex<double> point (double(x)*(rangex/double(widthW))-2.0, double(y)*(rangey/double(heightW))-1.0);

 std::complex<double> z(0, 0);
  int maxIter = 512;
    int i=0;

    while((abs(z)<2)&& (i<=maxIter) ){
        z=z*z+point;
        i++;
        }
        if (i < maxIter){
            return (255*i)/maxIter;
        }
        else{
            return 0;
        }


}
