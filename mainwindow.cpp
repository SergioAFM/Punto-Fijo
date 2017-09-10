#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString> // Library for the use of text strings
#include <cmath>  // Library for the use of mathematical functions

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Metodo,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


double MainWindow::funcion(double c){
    return (667.38/c)*(1-exp(-0.146843*c))-40;  // return the drag function

}
void MainWindow::metodo(){
    QString temp,temp2,temp3;       // Temporary text strings
    double X1=ui->x->value();       // Retrieve the X1 value of the spinbox
    double error=ui->Error->value();// Retrieve the value of the spinbox error
    double xr=0.0;
    double ea=100.0;
    while(ea>error){
        xr=funcion(X1); // It evaluates the function with the value X1 of the spinbox
        ea=100*std::abs(xr-X1)/xr;  // The error is calculated
        X1=xr;
    }
    temp.append("Raiz=").append(temp2.setNum(xr)).append("\nError=").append(temp3.setNum(ea));  // The text to be presented
    ui->Texto->setText(temp);   // The text is presented
    }
    void MainWindow::borrar(){
        ui->x->setValue(0.0); // The spinbox is deleted
        ui->Error->setValue(0.0); // The spinbox is deleted
        ui->Texto->clear();  // Text is deleted
    }
