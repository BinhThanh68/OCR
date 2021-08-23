#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_DisplayTimer()));

    ui->LB_ScoreTresholdVal->setText(QString::number(float(ui->SB_ScoreTreshold->value() / 10.0)));
    ui->LB_NMSThresholdVal->setText(QString::number(float(ui->SB_NMSThreshold->value() / 10.0)));


    MainViewBG = QPixmap(":/Images/Default_background.png");
    ui->LB_MainView->setPixmap(MainViewBG.scaled(ui->LB_MainView->width(), ui->LB_MainView->height(), Qt::IgnoreAspectRatio));

    OutputFile.setFileName("OutputText.txt");


    pixCamOff =    QPixmap(":/Images/camera_off.png");
    pixCamOn =     QPixmap(":/Images/camera_on.png");
    pixImgOff =    QPixmap(":/Images/image_off.png");
    pixImgOn =     QPixmap(":/Images/image_on.png");
    pixVideoOff =  QPixmap(":/Images/video_off.png");
    pixVideoOn =   QPixmap(":/Images/video_on.png");
    pixpauseDflt = QPixmap(":/Images/Pause_disabled.png");
    pixPauseStart = QPixmap(":/Images/Resume.png");
    pixPauseStop = QPixmap(":/Images/Pause.png");




    QIcon BTIconCamOff(pixCamOff);
    ui->BTN_CamOpen->setIcon(BTIconCamOff);
    ui->BTN_CamOpen->setIconSize(ui->BTN_CamOpen->rect().size());


    QIcon BTIconImgOff(pixImgOff);
    ui->BTN_ImageOpen->setIcon(BTIconImgOff);
    ui->BTN_ImageOpen->setIconSize(pixImgOff.rect().size());


    QIcon BTIconVideoOff(pixVideoOff);
    ui->BTN_VideoOpen->setIcon(BTIconVideoOff);
    ui->BTN_VideoOpen->setIconSize(pixVideoOff.rect().size());

    QIcon BTIPauseDflt(pixpauseDflt);
    ui->BTNPause->setIcon(BTIPauseDflt);
    ui->BTNPause->setIconSize(ui->BTNPause->rect().size());


    ui->PTE_AppLog->appendPlainText("Application Started!");
    timer_value = 10;
    timer.start(timer_value);


}


void MainWindow::on_DisplayTimer(){

    if(ImgInput.GetImageSource() != IDLE){
        ImgInput.GetNextFrame(frame);

        if(!frame.empty()){
            frame.copyTo(displayFrame);

            if(ui->CB_TextDetectorEnable->isChecked()){
                Text.Detect(displayFrame, float(ui->SB_ScoreTreshold->value()/10.0),
                                        float(ui->SB_NMSThreshold->value()/10.0), RecogCandidateBoxes);
            }
            if(ui->CB_TextRecogEnable->isChecked()){
                Text.Recognize(frame, &RecogCandidateBoxes, recognizedText);
                ui->PTE_TextOutput->clear();
                ui->PTE_TextOutput->appendPlainText(recognizedText.c_str());
    //            cout<<"result: "<<recognizedText<<endl;
            }

            cvtColor(displayFrame, displayFrame, COLOR_BGR2RGB);
            QImage qimg = QImage((uchar*)displayFrame.data, displayFrame.cols, displayFrame.rows,
                                         displayFrame.step, QImage::Format_RGB888);
            ui->LB_MainView->setPixmap(QPixmap::fromImage(qimg).scaled(ui->LB_MainView->width(),
                                                  ui->LB_MainView->height(), Qt::KeepAspectRatio));
        }else{

        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BTN_CamOpen_clicked()
{
    if(ImgInput.GetImageSource() != FROM_CAMERA){
        if(ImgInput.CamOpen()){
        ui->PTE_AppLog->appendPlainText("Camera opened");
        ImgInput.SetImageSource(FROM_CAMERA);

        QIcon BTIconCamOn(pixCamOn);
        ui->BTN_CamOpen->setIcon(BTIconCamOn);
        ui->BTN_CamOpen->setIconSize(pixCamOn.rect().size());

        QIcon BTIconImgOff(pixImgOff);
        ui->BTN_ImageOpen->setIcon(BTIconImgOff);
        ui->BTN_ImageOpen->setIconSize(pixImgOff.rect().size());

        QIcon BTIconVideoOff(pixVideoOff);
        ui->BTN_VideoOpen->setIcon(BTIconVideoOff);
        ui->BTN_VideoOpen->setIconSize(pixVideoOff.rect().size());

        QIcon BTIconPause(pixPauseStop);
        ui->BTNPause->setIcon(BTIconPause);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());
        }else{
            ui->PTE_AppLog->appendPlainText("Failed to open camera");
        }
    }else{
        ImgInput.CamClose();
        ui->PTE_AppLog->appendPlainText("Camera closed");
        ImgInput.SetImageSource(IDLE);

//        ui->LB_MainView->setPixmap(MainViewBG.scaled(ui->LB_MainView->width(), ui->LB_MainView->height(),
//                                                     Qt::IgnoreAspectRatio));

        QIcon BTIconCamOff(pixCamOff);
        ui->BTN_CamOpen->setIcon(BTIconCamOff);
        ui->BTN_CamOpen->setIconSize(pixCamOff.rect().size());

        QIcon BTIPauseDflt(pixpauseDflt);
        ui->BTNPause->setIcon(BTIPauseDflt);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());
    }
}




void MainWindow::on_BTN_ImageOpen_clicked()
{
    //Close cam if operating
    if(ImgInput.GetImageSource() == FROM_CAMERA){
        ImgInput.CamClose();
        ui->PTE_AppLog->appendPlainText("Camera closed");

        QIcon BTIconCamOff(pixCamOff);
        ui->BTN_CamOpen->setIcon(BTIconCamOff);
        ui->BTN_CamOpen->setIconSize(pixCamOff.rect().size());

        QIcon BTIPauseStop(pixPauseStop);
        ui->BTNPause->setIcon(BTIPauseStop);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());

        QIcon BTIconPause(pixpauseDflt);
        ui->BTNPause->setIcon(BTIconPause);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());

    }else if((ImgInput.GetImageSource() == FROM_VIDEO)){
        ImgInput.CamClose();
        ui->PTE_AppLog->appendPlainText("Video closed");

        QIcon BTIconVideoOff(pixVideoOff);
        ui->BTN_VideoOpen->setIcon(BTIconVideoOff);
        ui->BTN_VideoOpen->setIconSize(pixVideoOff.rect().size());

        QIcon BTIconPause(pixpauseDflt);
        ui->BTNPause->setIcon(BTIconPause);
        ui->BTNPause->setIconSize(ui->BTNPause->rect().size());
    }

    timer.stop();
    QString filename =  QFileDialog::getOpenFileName(
              this,
              "Open Image",
              QDir::currentPath(),
              "All files (*.*) ;; JPG files (*.jpg);; PNG files (*.png)");

    if(!filename.isNull()){
       ImgInput.SetFileName(filename);
       ImgInput.SetImageSource(FROM_IMAGE);

       QIcon BTIconImgOn(pixImgOn);
       ui->BTN_ImageOpen->setIcon(BTIconImgOn);
       ui->BTN_ImageOpen->setIconSize(pixImgOn.rect().size());

       QIcon BTIPauseStop(pixPauseStop);
       ui->BTNPause->setIcon(BTIPauseStop);
       ui->BTNPause->setIconSize(ui->BTNPause->rect().size());
    }else{
        ImgInput.SetImageSource(IDLE);
        ui->PTE_AppLog->appendPlainText("File invalid");
    }
    timer.start(timer_value);
}



void MainWindow::on_BTN_VideoOpen_clicked()
{
    //Close cam if operating
    if(ImgInput.GetImageSource() == FROM_CAMERA){
        ImgInput.CamClose();
        ui->PTE_AppLog->appendPlainText("Camera closed");

        QIcon BTIconCamOff(pixCamOff);
        ui->BTN_CamOpen->setIcon(BTIconCamOff);
        ui->BTN_CamOpen->setIconSize(pixCamOff.rect().size());
    }else if(ImgInput.GetImageSource() == FROM_IMAGE){
        QIcon BTIconImgOff(pixImgOff);
        ui->BTN_ImageOpen->setIcon(BTIconImgOff);
        ui->BTN_ImageOpen->setIconSize(pixImgOff.rect().size());
    }

    QString filename =  QFileDialog::getOpenFileName(
              this,
              "Open Video",
              QDir::currentPath(),
              "All files (*.*) ;; MP4 files (*.mp4);; MOV files (*.mov)");

    if(!filename.isNull()){
       ImgInput.SetImageSource(FROM_VIDEO);
       if(ImgInput.VideoOpen(filename)){
           QIcon BTIconVideoOn(pixVideoOn);
           ui->BTN_VideoOpen->setIcon(BTIconVideoOn);
           ui->BTN_VideoOpen->setIconSize(ui->BTN_VideoOpen->rect().size());

           QIcon BTIPauseStop(pixPauseStop);
           ui->BTNPause->setIcon(BTIPauseStop);
           ui->BTNPause->setIconSize(ui->BTNPause->rect().size());

           ui->PTE_AppLog->appendPlainText("Video opened suscessfully");
       }else{
           ui->PTE_AppLog->appendPlainText("Fail to open video");
       }

    }else{
        ImgInput.SetImageSource(IDLE);
        ui->PTE_AppLog->appendPlainText("File invalid");
    }
}


void MainWindow::on_BTNPause_clicked()
{
    if(ImgInput.GetImageSource() != IDLE){
        if(timer.isActive()){
            timer.stop();
            QIcon BTIPauseStart(pixPauseStart);
            ui->BTNPause->setIcon(BTIPauseStart);
            ui->BTNPause->setIconSize(ui->BTNPause->rect().size());

        }else{
            timer.start(timer_value);

            QIcon BTIPauseStop(pixPauseStop);
            ui->BTNPause->setIcon(BTIPauseStop);
            ui->BTNPause->setIconSize(ui->BTNPause->rect().size());
        }
    }
}


void MainWindow::on_SB_ScoreTreshold_valueChanged(int value)
{
    ui->LB_ScoreTresholdVal->setText(QString::number(float(value / 10.0)));
}


void MainWindow::on_SB_NMSThreshold_valueChanged(int value)
{
    ui->LB_NMSThresholdVal->setText(QString::number(float(value / 10.0)));
}


void MainWindow::on_BTN_WriteText2File_clicked()
{
    bool openfile = false;
    if(ui->CBB_WriteMethod->currentIndex() == 0){
        openfile = OutputFile.open(QIODevice::WriteOnly | QIODevice::Text);
    }else if(ui->CBB_WriteMethod->currentIndex() == 1){
        openfile = OutputFile.open(QIODevice::WriteOnly | QIODevice::Append);
    }
    if(openfile){
       OutputFile.write(QByteArray::fromStdString(recognizedText));
       OutputFile.close();
       ui->PTE_AppLog->appendPlainText("Write finished");
    }else{
        ui->PTE_AppLog->appendPlainText("failed to write text");
    }

}
