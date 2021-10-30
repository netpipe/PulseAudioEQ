#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

//PA_LADSPA_PLUGIN='mbeq_1197'
//PA_LADSPA_PLUGIN_NAME='Multiband EQ'
//PA_LADSPA_LABEL='mbeq'
//PA_NUM_LADSPA_INPUTS='15'
//PA_LADSPA_CONTROLS='0,0,0,0,0,0,0,0,0,0,0,0,0,0,0'
//PA_LADSPA_INPUTS='50,100,156,220,311,440,622,880,1250,1750,2500,3500,5000,10000,20000'
//PA_CONTROL_MIN='-30'
//PA_CONTROL_MAX='30'
//PA_PREAMP='1.0'
//PA_CURRENT_PRESET=''


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
