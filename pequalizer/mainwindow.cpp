#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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


void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_pushButton_clicked()
{
        QFile file("test.txt");
        file.open(QIODevice::Text | QIODevice::ReadOnly);
    QFile file2("themes.txt");
        if(file2.open(QIODevice::ReadWrite | QIODevice::Text))// QIODevice::Append |
        {
                QTextStream stream(&file2);
                file2.seek(0);
               stream << "theme:" << endl;
                for (int i = 0; i < 1; i++)
                {
                 stream << "theme:" << endl;
                }
            //                file.write("\n");
               file2.close();
        }
}
