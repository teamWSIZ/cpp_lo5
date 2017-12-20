#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <qmessagebox.h>

#include <bits/stdc++.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //odczyt daty, zamiana na epoch...
    QDate date = ui->dateEdit->date();
    QDateTime dt(date, QTime());
    ui->lineEdit_2->setText(dt.toString());
}

void MainWindow::on_pushButton_2_clicked()
{
    QBrush blue(Qt::blue);
    QPen pen(Qt::black);
    pen.setWidth(3);
    scene->addLine(10, 10, 30, 70, pen);
}

void MainWindow::on_kwadratButton_clicked()
{
    cout << "clicked!" << endl; //works
    ui->pushButton->setText("abraKadabra");
    QString input = ui->lineEdit->text();
    int w = input.toInt();
    int kwadrat = w * w;
    QString output = QString::number(kwadrat);
    ui->lineEdit_2->setText(output);
    //QMessageBox::information( this, "Jakieś okienko", "Ta wiadomość nie ma większego sensu", QMessageBox::Ok );
}
