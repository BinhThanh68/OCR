#include "imageinput.h"

ImageInput::ImageInput()
{
    ImageSource = IDLE;
    newFile = false;

    cam.set(CAP_PROP_FRAME_WIDTH, 640);
    cam.set(CAP_PROP_FRAME_HEIGHT, 480);
    cam.set(CAP_PROP_AUTOFOCUS, 1);
    cam.set(CAP_PROP_FPS, 25);
}


bool ImageInput::CamOpen(unsigned char CamIdx){

    if(cam.open(CamIdx)){
        //ui->PTE_AppLog->appendPlainText("Camera opened");
        return true;
    }
    return false;
}

void ImageInput::CamClose(){
    if(cam.isOpened()){
        cam.release();
    }
}


bool ImageInput::VideoOpen(QString filename){
    if(cam.open(filename.toStdString())){
        return true;
    }
    return false;
}


void ImageInput::GetNextFrame(Mat &outPut) {
    if(ImageSource == FROM_CAMERA){
        if (cam.isOpened()) {
            cam >> outPut;
        }
    }else if(ImageSource == FROM_IMAGE){
        if(newFile){
            outPut = imread(FileName.toStdString());
            newFile = false;
        }
    }else if(ImageSource == FROM_VIDEO){
        if(cam.isOpened()){
            cam >> outPut;
        }
    }
}

