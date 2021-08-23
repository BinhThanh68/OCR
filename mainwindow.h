#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFileDialog>
#include "imageinput.h"
#include "Struct_and_Enum.h"
#include "TextHandling.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void on_DisplayTimer();



private slots:
    void on_BTN_CamOpen_clicked();



    void on_BTN_ImageOpen_clicked();

    void on_BTN_VideoOpen_clicked();

    void on_BTNPause_clicked();

    void on_SB_ScoreTreshold_valueChanged(int value);

    void on_SB_NMSThreshold_valueChanged(int value);

    void on_BTN_WriteText2File_clicked();

private:
    Ui::MainWindow *ui;
    ImageInput ImgInput;
    TextHandling Text;
    QTimer timer;
    Mat frame, displayFrame;
    int timer_value;
    QPixmap MainViewBG;
    QPixmap pixCamOff, pixCamOn, pixImgOff, pixImgOn, pixVideoOff, pixVideoOn, pixpauseDflt,
    pixPauseStart, pixPauseStop;
    vector<Rect> RecogCandidateBoxes;
    string recognizedText;
    QFile OutputFile;

};
#endif // MAINWINDOW_H
