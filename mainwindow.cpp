#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTableWidgetItem* item = new QTableWidgetItem();
    ui->tableWidget->setItem(0, 1, item);
    item->setText("1");
}

class Init
{
public:
    Init(Ui::MainWindow);
};

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int size = ui->tableWidget->verticalHeader()->count();
    QTableWidgetItem* item = new QTableWidgetItem();
    ui->tableWidget->setRowCount(size + 1);
    ui->tableWidget->setItem(size, 1, item);
    item->setText("1");
}

float calc(std::vector<float> vec, int size, int &pos1, int &pos2)
{
    if(size %2 != 0)
   {
       pos1 = (size+1)/2 - 1;
       pos2 = pos1;
       return vec[pos1];

   }
   else
   {
       pos1 = size/2 - 1;
       pos2 = (size+2)/2 - 1;
       return (vec[pos1] + vec[pos2])/2;
   }

}

void MainWindow::on_pushButton_3_clicked()
{

   int size = ui->tableWidget->verticalHeader()->count();
   ui->tableWidget->setRowCount(size - 1);
}

void MainWindow::on_pushButton_6_clicked()
{
    std::vector<float> vec;
    float mean = 0, S = 0, median = 0, Q1 = 0, Q3 = 0, range = 0;
    int n = 0, pos1 = 0, pos2 = 0;
    int size = ui->tableWidget->verticalHeader()->count();
    ui->textEdit->clear();

    for(int i = 0; i < size; i++)
    {
        float x = ui->tableWidget->item(i, 0)->text().toFloat();
        int y = ui->tableWidget->item(i, 1)->text().toInt();
        mean += x * y;
        n += y;
        for(int f = 0;  f < y; f++)
        {
            vec.push_back(x);
        }
    }

    mean /= n;

    for(int i = 0; i < size; i++)
    {
        float x = ui->tableWidget->item(i, 0)->text().toFloat();
        int y = ui->tableWidget->item(i, 1)->text().toInt();
        S += pow((x - mean), 2) * y;
    }


    sort(vec.begin(),  vec.end());

    range = vec.back() - vec.front();

    median = calc(vec, vec.size(), pos1, pos2);

    Q1 = calc(vec, pos1+1, pos1, pos2);

    Q3 = calc(vec, pos2, pos1, pos2);

//   if(vec.size() %2 != 0)
//   {
//       median = vec[(vec.size() + 1)/2];

//   }
//   else
//   {
//       median = ((vec[vec.size()/2] + vec[((vec.size()+2))/2])/2);
//   }




//    for(int i = 0; i < size; i++)
//    {
//        float x = ui->tableWidget->item(i, 0)->text().toFloat();
//        int y = ui->tableWidget->item(i, 1)->text().toInt();
//        mean += x * y;
//        n += y;
//    }

//    mean /= n;

//    for(int i = 0; i < size; i++)
//    {
//        float x = ui->tableWidget->item(i, 0)->text().toFloat();
//        int y = ui->tableWidget->item(i, 1)->text().toInt();
//        S += pow((x - mean), 2) * y;
//    }

    float Sx = sqrt(S/(n-1));
    float Sd = sqrt(S/n);

    ui->textEdit->append("mean = " + QString::number(mean) + "\n");
    ui->textEdit->append("Population standard deviation = " + QString::number(Sd) + "\n");
    ui->textEdit->append("Sample standard deviation = " + QString::number(Sx) + "\n");

    ui->textEdit->append("Max number: " + QString::number(vec.back()));

    ui->textEdit->append("Lowest number: " + QString::number(vec.front()));

    ui->textEdit->append("range: " + QString::number(range));


    ui->textEdit->append("median: " + QString::number(median));


    ui->textEdit->append("Q1: " + QString::number(Q1));


    ui->textEdit->append("Q3: " + QString::number(Q3));


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

