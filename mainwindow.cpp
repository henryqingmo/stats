#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <cmath>

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
    std::vector<float> vec;
    float mean = 0, S = 0, median = 0;
    int n = 0;
    int size = ui->tableWidget->verticalHeader()->count();

    for(int i = 0; i < size; i++)
    {
        for(int f = 0;  f < ui->tableWidget->item(i, 1)->text().toInt(); f++)
        {
            vec.push_back(ui->tableWidget->item(i, 0)->text().toFloat());
        }
    }

    sort(vec.begin(),  vec.end());

    float range = vec.back() - vec.front();

   if(vec.size() %2 != 0)
   {
       median = (vec.size() + 1)/2;
   }
   else
   {
       median = ((vec[vec.size()/2] + vec[((vec.size()+2))/2])/2);
   }


    for(int i = 0; i < size; i++)
    {
        float x = ui->tableWidget->item(i, 0)->text().toFloat();
        int y = ui->tableWidget->item(i, 1)->text().toInt();
        mean += x * y;
        n += y;
    }

    mean /= n;

    for(int i = 0; i < size; i++)
    {
        float x = ui->tableWidget->item(i, 0)->text().toFloat();
        int y = ui->tableWidget->item(i, 1)->text().toInt();
        S += pow((x - mean), 2) * y;
    }

    float Sx = sqrt(S/(n-1));
    float Sd = sqrt(S/n);

    ui->textEdit->append("mean = " + QString::number(mean) + "\n");
    ui->textEdit->append("Population standard deviation = " + QString::number(Sd) + "\n");
    ui->textEdit->append("Sample standard deviation = " + QString::number(Sx) + "\n");

    ui->textEdit->append("Max number: " + QString::number(vec.back()));

    ui->textEdit->append("Lowest number: " + QString::number(vec.front()));

    ui->textEdit->append("range: " + QString::number(range));


    ui->textEdit->append("median: " + QString::number(median));


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

