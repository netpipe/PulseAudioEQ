#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QDirIterator>
#include <QDebug>

int presetinitial=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    WritePresetFile(ui->PresetName->toPlainText().toLatin1()+".preset");
}

void MainWindow::WritePresetFile(QString fileName)
{
    QString pream_str, presetName_str;

    float kValue = ui->preamp_slider->value();
    kValue = kValue / 10;
    pream_str = QString::number(kValue);
    presetName_str = ui->PresetName->toPlainText();

    QFile file(fileName);
    file.open(QIODevice::Text | QIODevice::WriteOnly);
    QTextStream stream(&file);
    stream << "mbeq_1197" << endl;
    stream << "mbeq" << endl;
    stream << "Multiband EQ" << endl;


    stream << pream_str.toFloat() << endl;
    stream << presetName_str << endl;
    stream << "1" << endl; //equalizer status
        stream << "1" << endl; //persistance
        stream << "-30" << endl;
            stream << "30" << endl;
    stream << "15" << endl;
    stream <<  (float)ui->s50hz->value() / 10 << endl;
    stream <<  (float)ui->s100hz->value()/ 10 << endl;
    stream <<  (float)ui->s156hz->value()/ 10 << endl;
    stream <<  (float)ui->s220hz->value()/ 10 << endl;
    stream <<  (float)ui->s311hz->value()/ 10 << endl;
    stream <<  (float)ui->s440hz->value()/ 10 << endl;
    stream <<  (float)ui->s622hz->value()/ 10 << endl;
    stream <<  (float)ui->s880hz->value() / 10<< endl;
    stream <<  (float)ui->s125khz->value()/ 10 << endl;
    stream <<  (float)ui->s175khz->value()/ 10 << endl;
    stream <<  (float)ui->s25khz->value()/ 10 << endl;
    stream <<  (float)ui->s35khz->value()/ 10 << endl;
    stream <<  (float)ui->s5khz->value() / 10<< endl;
    stream <<  (float)ui->s10khz->value()/ 10 << endl;
    stream <<  (float)ui->s20khz->value()/ 10 << endl;
    stream << 50 << endl;
    stream << 100 << endl;
    stream << 156 << endl;
    stream << 220 << endl;
    stream << 311 << endl;
    stream << 440 << endl;
    stream << 622 << endl;
    stream << 880 << endl;
    stream << 1250 << endl;
    stream << 1750 << endl;
    stream << 2500 << endl;
    stream << 3500 << endl;
    stream << 5000 << endl;
    stream << 10000 << endl;
    stream << 20000 << endl;
    file.close();
    qDebug() << fileName.toLatin1() << "wrote";
}

void MainWindow::on_s50hz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l50hz->setText(QString::number(k)+" db");
    if(presetinitial)
    on_applybtn_clicked();
}

void MainWindow::on_s100hz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l100hz->setText(QString::number(k)+" db");
        if(presetinitial)
    on_applybtn_clicked();
}

void MainWindow::on_s156hz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l156hz->setText(QString::number(k)+" db");
        if(presetinitial)
    on_applybtn_clicked();
}

void MainWindow::on_s220hz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l220hz->setText(QString::number(k)+" db");
        if(presetinitial)
on_applybtn_clicked();
}

void MainWindow::on_s311hz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l311hz->setText(QString::number(k)+" db");
        if(presetinitial)
on_applybtn_clicked();
}

void MainWindow::on_s440hz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l440hz->setText(QString::number(k)+" db");
        if(presetinitial)
on_applybtn_clicked();
}

void MainWindow::on_s622hz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l622hz->setText(QString::number(k)+" db");
        if(presetinitial)
on_applybtn_clicked();
}

void MainWindow::on_s880hz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l880hz->setText(QString::number(k)+" db");
        if(presetinitial)
on_applybtn_clicked();
}

void MainWindow::on_s125khz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l125khz->setText(QString::number(k)+" db");
        if(presetinitial)
on_applybtn_clicked();
}

void MainWindow::on_s175khz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l175khz->setText(QString::number(k)+" db");
        if(presetinitial)
on_applybtn_clicked();
}

void MainWindow::on_s25khz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l25khz->setText(QString::number(k)+" db");
        if(presetinitial)
    on_applybtn_clicked();
}

void MainWindow::on_s35khz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l35khz->setText(QString::number(k)+" db");
        if(presetinitial)
    on_applybtn_clicked();
}

void MainWindow::on_s5khz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l5khz->setText(QString::number(k)+" db");
        if(presetinitial)
    on_applybtn_clicked();
}

void MainWindow::on_s10khz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l10khz->setText(QString::number(k)+" db");
        if(presetinitial)
on_applybtn_clicked();
}

void MainWindow::on_s20khz_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->l20khz->setText(QString::number(k)+" db");
        if(presetinitial)
    on_applybtn_clicked();
}

void MainWindow::on_preamp_slider_sliderMoved(int position)
{
    float k = position;
    k = k / 10;
    ui->lpreamp->setText(QString::number(k)+" X");
        if(presetinitial)
    on_applybtn_clicked();
}

void MainWindow::on_applybtn_clicked()
{
    //save QDir::homePath()+"/.config/pulse/equalizerrc"
    WritePresetFile(QDir::homePath()+"/.config/pulse/equalizerrc");
    QProcess::execute ("bash", QStringList() << "pulseaudio-equalizer" << "interface.applysettings");
}


void MainWindow::on_enableBTN_clicked()
{
 //   QProcess::execute ("pulseaudio-equalizer enable");
    QProcess::execute("bash", QStringList() << "/usr/bin/pulseaudio-equalizer" << "enable");
}


void MainWindow::on_disableBTN_clicked()
{
    QProcess::execute ("bash", QStringList() << "/usr/bin/pulseaudio-equalizer" << "disable");
}

void MainWindow::on_toggleBTN_clicked()
{
    QProcess::execute ("bash", QStringList() << "/usr/bin/pulseaudio-equalizer" << "toggle");

}

void MainWindow::on_preset_currentIndexChanged(int index)
{
        presetinitial=0;
    if( index == 0 )
    {
        ui->s50hz->setValue(4); on_s50hz_sliderMoved(4);
        ui->s100hz->setValue(4); on_s100hz_sliderMoved(4);
        ui->s156hz->setValue(4); on_s156hz_sliderMoved(4);
        ui->s220hz->setValue(4); on_s220hz_sliderMoved(4);
        ui->s311hz->setValue(4); on_s311hz_sliderMoved(4);
        ui->s440hz->setValue(4); on_s440hz_sliderMoved(4);
        ui->s622hz->setValue(4); on_s622hz_sliderMoved(4);
        ui->s880hz->setValue(4); on_s880hz_sliderMoved(4);
        ui->s125khz->setValue(4); on_s125khz_sliderMoved(4);
        ui->s175khz->setValue(4); on_s175khz_sliderMoved(4);
        ui->s156hz->setValue(4); on_s156hz_sliderMoved(4);
        ui->s25khz->setValue(4); on_s25khz_sliderMoved(4);
        ui->s35khz->setValue(4); on_s35khz_sliderMoved(4);
        ui->s5khz->setValue(4); on_s5khz_sliderMoved(4);
        ui->s10khz->setValue(4); on_s10khz_sliderMoved(4);
        ui->s20khz->setValue(4); on_s20khz_sliderMoved(4);
        ui->preamp_slider->setValue(20); on_preamp_slider_sliderMoved(20);
        ui->PresetName->setPlainText("default");
    }
    else
    {
        QString fileName = ui->preset->itemText(index);

        QFile PresetFile(fileName);
        if(PresetFile.exists())
        {
            PresetFile.open(QIODevice::ReadOnly);
            QTextStream in (&PresetFile);
            QString strBuffer = in.readAll();
            QStringList strList = strBuffer.split('\n');

            ui->preamp_slider->setValue(strList[3].toFloat()*10);
            on_preamp_slider_sliderMoved(strList[3].toFloat()*10);
            ui->PresetName->setPlainText(strList[4]);


            double kValue = strList[6].toFloat()*10;
            ui->s50hz->setValue((int)kValue); on_s50hz_sliderMoved((int)kValue);

            kValue = strList[7].toFloat()*10;
            ui->s100hz->setValue((int)kValue); on_s100hz_sliderMoved((int)kValue);

            kValue = strList[8].toFloat()*10;
            ui->s156hz->setValue((int)kValue); on_s156hz_sliderMoved((int)kValue);

            kValue = strList[9].toFloat()*10;
            ui->s220hz->setValue((int)kValue); on_s220hz_sliderMoved((int)kValue);

            kValue = strList[10].toFloat()*10;
            ui->s311hz->setValue((int)kValue); on_s311hz_sliderMoved((int)kValue);

            kValue = strList[11].toFloat()*10;
            ui->s440hz->setValue((int)kValue); on_s440hz_sliderMoved((int)kValue);

            kValue = strList[12].toFloat()*10;
            ui->s622hz->setValue((int)kValue); on_s622hz_sliderMoved((int)kValue);

            kValue = strList[13].toFloat()*10;
            ui->s880hz->setValue((int)kValue); on_s880hz_sliderMoved((int)kValue);

            kValue = strList[14].toFloat()*10;
            ui->s125khz->setValue((int)kValue); on_s125khz_sliderMoved((int)kValue);

            kValue = strList[15].toFloat()*10;
            ui->s175khz->setValue((int)kValue); on_s175khz_sliderMoved((int)kValue);

            kValue = strList[16].toFloat()*10;
            ui->s25khz->setValue((int)kValue); on_s25khz_sliderMoved((int)kValue);

            kValue = strList[17].toFloat()*10;
            ui->s35khz->setValue((int)kValue); on_s35khz_sliderMoved((int)kValue);

            kValue = strList[18].toFloat()*10;
            ui->s5khz->setValue((int)kValue); on_s5khz_sliderMoved((int)kValue);

            kValue = strList[19].toFloat()*10;
            ui->s10khz->setValue((int)kValue); on_s10khz_sliderMoved((int)kValue);

            kValue = strList[20].toFloat()*10;
            ui->s20khz->setValue((int)kValue); on_s20khz_sliderMoved((int)kValue);

            PresetFile.close();
        }
    }
    presetinitial=1;

}



void MainWindow::on_s156hz_valueChanged(int value)
{

}
