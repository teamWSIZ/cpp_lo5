#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include "ui_mainwindow.h"


#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_kwadratButton_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene* scene;

};

#endif // MAINWINDOW_H
