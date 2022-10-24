#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <cmath>

std::vector<int> vect;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->verticalHeader()->count()+1);
}


void MainWindow::on_pushButton_3_clicked()
{
   ui->tableWidget->setRowCount(1);
}


void MainWindow::on_pushButton_6_clicked()
{
    float mean = 0;
    int n = 0;
    float Sx = 0;
    for(int i = 0; i < ui->tableWidget->verticalHeader()->count(); i++)
    {
        mean += ui->tableWidget->item(i,0)->text().toFloat();
        n += ui->tableWidget->item(i, 1)->text().toInt();
    }

    for(int i = 0; i< ui->tableWidget->verticalHeader()->count(); i++)
    {
        Sx += (ui->tableWidget->item(i,0)->text().toFloat() - mean);
        Sx = pow(Sx, 2);
    }

    Sx = sqrt(Sx/(n-1));

   // QString x = ui->tableWidget->item(0,1)->text();

    ui->textEdit->append(QString::number(mean));

    ui->textEdit->append(" ");
    ui->textEdit->append(QString::number(n));

    ui->textEdit->append(" ");
    ui->textEdit->append(QString::number(mean/n));

    ui->textEdit->append(" ");
    ui->textEdit->append(QString::number(Sx));

}




void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
}


void MainWindow::on_pushButton_7_clicked()
{
   ui->tableWidget->setRowCount(1);
   ui->textEdit->clear();
}

