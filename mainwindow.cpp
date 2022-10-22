#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/res/img/planet.png");
    int w = ui->label_3->width();
    int h = ui->label_3->height();
    ui->label_3->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if(login == "login1234" && password == "PASpas"){
        ui->statusbar->showMessage("Login and Password are correct");
    }
    else if(login == "login1234"){
        QMessageBox::warning(this, "Warning", "Password error");
    }
    else if(password == "PASpas"){
        QMessageBox::warning(this, "Warning", "Login error");
    }
    else{
        QMessageBox::warning(this, "Warning", "Password and Login error");
    }
}


void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{
    QString text = ui->lineEdit_3->text();
    ui->statusbar->showMessage(text);
}

