#include "TextHandling.h"

void decode(const Mat& scores, const Mat& geometry, float scoreThresh,
            std::vector<RotatedRect>& detections, std::vector<float>& confidences){
    detections.clear();
    CV_Assert(scores.dims == 4); CV_Assert(geometry.dims == 4); CV_Assert(scores.size[0] == 1);
    CV_Assert(geometry.size[0] == 1); CV_Assert(scores.size[1] == 1); CV_Assert(geometry.size[1] == 5);
    CV_Assert(scores.size[2] == geometry.size[2]); CV_Assert(scores.size[3] == geometry.size[3]);

    const int height = scores.size[2];
    const int width = scores.size[3];
    for (int y = 0; y < height; ++y)
    {
        const float* scoresData = scores.ptr<float>(0, 0, y);
        const float* x0_data = geometry.ptr<float>(0, 0, y);
        const float* x1_data = geometry.ptr<float>(0, 1, y);
        const float* x2_data = geometry.ptr<float>(0, 2, y);
        const float* x3_data = geometry.ptr<float>(0, 3, y);
        const float* anglesData = geometry.ptr<float>(0, 4, y);
        for (int x = 0; x < width; ++x)
        {
            float score = scoresData[x];
            if (score < scoreThresh)
                continue;

            // Decode a prediction.
            // Multiple by 4 because feature maps are 4 time less than input image.
            float offsetX = x * 4.0f, offsetY = y * 4.0f;
            float angle = anglesData[x];
            float cosA = std::cos(angle);
            float sinA = std::sin(angle);
            float h = x0_data[x] + x2_data[x];
            float w = x1_data[x] + x3_data[x];

            Point2f offset(offsetX + cosA * x1_data[x] + sinA * x2_data[x],
                           offsetY - sinA * x1_data[x] + cosA * x2_data[x]);
            Point2f p1 = Point2f(-sinA * h, -cosA * h) + offset;
            Point2f p3 = Point2f(-cosA * w, sinA * w) + offset;
            RotatedRect r(0.5f * (p1 + p3), Size2f(w, h), -angle * 180.0f / (float)CV_PI);
            detections.push_back(r);
            confidences.push_back(score);
        }
    }
}

TextHandling::TextHandling()
{
//    net = dnn::readNet("/home/binhthanh/Documents/personal_cv_projects/Optical_Character_Recognition/Model_files/frozen_east_text_detection.pb");
    net = dnn::readNet("Model_files/frozen_east_text_detection.pb");
    outputLayers.assign(2, "");
    outputLayers[0] = "feature_fusion/Conv_7/Sigmoid";
    outputLayers[1] = "feature_fusion/concat_3";

    ocr = OCRTesseract::create();
}

void TextHandling::Detect(Mat &image, float confThreshold, float nmsThreshold, vector<Rect> &outputBox){
    outputBox.clear();

    inputBlob = dnn::blobFromImage(image, 1.0, Size(320, 320), Scalar(123.68, 116.78, 103.94), true, false);
    net.setInput(inputBlob);
    net.forward(output, outputLayers);
    Mat scores = output[0];
    Mat geometry = output[1];
    decode(scores, geometry, confThreshold, boxes, confidences);


    dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);

    // Render detections.
            Point2f ratio((float)image.cols / 320, (float)image.rows / 320);
            for (size_t i = 0; i < indices.size(); ++i)
            {
                RotatedRect& box = boxes[indices[i]];

                outputBox.push_back(box.boundingRect());

                Point2f vertices[4];
                box.points(vertices);
                for (int j = 0; j < 4; ++j)
                {
                    vertices[j].x *= ratio.x;
                    vertices[j].y *= ratio.y;
                }
                for (int j = 0; j < 4; ++j)
                    line(image, vertices[j], vertices[(j + 1) % 4], Scalar(0, 255, 0), 2, LINE_AA);
            }

            boxes.clear();
            confidences.clear();
            indices.clear();
}


void TextHandling::Recognize(Mat &image, vector<Rect> *boxes, string &outputText){

    ocr->run(image, outputText, boxes);
}

