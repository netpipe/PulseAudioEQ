#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QDirIterator>

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

//    QDirIterator it("./Resource/themes/", QStringList() << "*.qss", QDir::Files, QDirIterator::Subdirectories);
//    while (it.hasNext()){
//      //  QFileInfo fileInfo(f.fileName());
//        ui->cmbTheme->addItem(it.next().toLatin1());
//    }


//    QFile MyFile("themes.txt");
//    if(MyFile.exists()){
//        MyFile.open(QIODevice::ReadWrite);
//        QTextStream in (&MyFile);
//        QString line;
//        QStringList list;
//         //   QList<QString> nums;
//        QStringList nums;
//        QRegExp rx("[:]");
//        line = in.readLine();
//  QString stylesheet;
//        if (line.contains(":")) {
//            list = line.split(rx);
//                qDebug() << "theme" <<  list.at(1).toLatin1();
//                stylesheet =  list.at(1).toLatin1();
//          loadStyleSheet( list.at(1).toLatin1());

//                MyFile.close();
//        }

//      fileName=stylesheet;


        QDirIterator it(QDir::homePath()+"/.config/pulse/presets", QStringList() << "*.preset", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()){
          //  QFileInfo fileInfo(f.fileName());
            ui->preset->addItem(it.next().toLatin1());
        }


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

void MainWindow::on_s50hz_sliderMoved(int position)
{
    ui->l50hz->setText(QString::number(position)+" db");
}

void MainWindow::on_s100hz_sliderMoved(int position)
{
    ui->l100hz->setText(QString::number(position)+" db");

}

void MainWindow::on_s156hz_sliderMoved(int position)
{
    ui->l156hz->setText(QString::number(position)+" db");
}

void MainWindow::on_s220hz_sliderMoved(int position)
{
    ui->l220hz->setText(QString::number(position)+" db");

}

void MainWindow::on_s311hz_sliderMoved(int position)
{
    ui->l311hz->setText(QString::number(position)+" db");

}

void MainWindow::on_s440hz_sliderMoved(int position)
{
    ui->l440hz->setText(QString::number(position)+" db");

}

void MainWindow::on_s622hz_sliderMoved(int position)
{
    ui->l622hz->setText(QString::number(position)+" db");

}

void MainWindow::on_s880hz_sliderMoved(int position)
{
    ui->l880hz->setText(QString::number(position)+" db");

}

void MainWindow::on_s125khz_sliderMoved(int position)
{
    ui->l125khz->setText(QString::number(position)+" db");

}

void MainWindow::on_s175khz_sliderMoved(int position)
{
    ui->l175khz->setText(QString::number(position)+" db");

}

void MainWindow::on_s25khz_sliderMoved(int position)
{
    ui->l25khz->setText(QString::number(position)+" db");

}

void MainWindow::on_s35khz_sliderMoved(int position)
{
    ui->l35khz->setText(QString::number(position)+" db");

}

void MainWindow::on_s5khz_sliderMoved(int position)
{
    ui->l5khz->setText(QString::number(position)+" db");

}

void MainWindow::on_s10khz_sliderMoved(int position)
{
    ui->l10khz->setText(QString::number(position)+" db");

}

void MainWindow::on_s20khz_sliderMoved(int position)
{
    ui->l20khz->setText(QString::number(position)+" db");

}

void MainWindow::on_applybtn_clicked()
{
    //save QDir::homePath()+"/.config/pulse/equalizerrc"
    QProcess::execute ("pulseaudio-equalizer interface.applysettings");
}


void MainWindow::on_enableBTN_clicked()
{
    QProcess::execute ("pulseaudio-equalizer enable");
}


void MainWindow::on_disableBTN_clicked()
{
    QProcess::execute ("pulseaudio-equalizer disable");

}

void MainWindow::on_toggleBTN_clicked()
{
    QProcess::execute ("pulseaudio-equalizer toggle");

}
