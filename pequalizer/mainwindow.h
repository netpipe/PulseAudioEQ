#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_pushButton_clicked();

    void on_applybtn_clicked();

    void on_s50hz_sliderMoved(int position);

    void on_s100hz_sliderMoved(int position);

    void on_s156hz_sliderMoved(int position);

    void on_s220hz_sliderMoved(int position);

    void on_s311hz_sliderMoved(int position);

    void on_s440hz_sliderMoved(int position);

    void on_s622hz_sliderMoved(int position);

    void on_s880hz_sliderMoved(int position);

    void on_s125khz_sliderMoved(int position);

    void on_s175khz_sliderMoved(int position);

    void on_s25khz_sliderMoved(int position);

    void on_s35khz_sliderMoved(int position);

    void on_s5khz_sliderMoved(int position);

    void on_s10khz_sliderMoved(int position);

    void on_s20khz_sliderMoved(int position);

    void on_enableBTN_clicked();

    void on_disableBTN_clicked();

    void on_toggleBTN_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
