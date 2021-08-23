#ifndef TEXTHANDLING_H
#define TEXTHANDLING_H

#include <opencv2/dnn/dnn.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/text/ocr.hpp>
#include <opencv2/text.hpp>

using namespace cv;
using namespace std;
using namespace cv::text;

class TextHandling
{


public:
    TextHandling();

    void Detect(Mat &image, float confThreshold, float nmsThreshold, vector<Rect> &outputBox);
    void Recognize(Mat &image, vector<Rect> *boxes, string &outputText);

private:
    dnn::Net net;
    vector<String> outputLayers;
    Mat inputBlob;
    vector<Mat> output;
    vector<RotatedRect> boxes;
    vector<float> confidences;
    vector<int> indices;
    Ptr<OCRTesseract> ocr;
};


#endif // TEXTHANDLING_H
