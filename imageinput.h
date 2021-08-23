#ifndef IMAGEINPUT_H
#define IMAGEINPUT_H

#include <QObject>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>
#include "Struct_and_Enum.h"

using namespace cv;
using namespace std;

class ImageInput
{
//    Q_OBJECT
public:
    ImageInput();


    bool CamOpen(unsigned char CamIdx=0);
    void CamClose();
    bool VideoOpen(QString fileName);
    void GetNextFrame(Mat &outPut);
    inline void SetFileName(QString filename) {FileName = filename; newFile = true;}
    inline void SetImageSource(ImgSource source) {ImageSource = source;}
    inline ImgSource GetImageSource() {return ImageSource;}

private:
    VideoCapture cam;
    QString FileName;
    bool newFile;
    ImgSource ImageSource;
};

#endif // IMAGEINPUT_H
