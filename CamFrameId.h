#ifndef CAMFRAMEID_H
#define CAMFRAMEID_H
#ifndef VERI_H
#define VERI_H

#include <QString>
#include <opencv4/opencv2/opencv.hpp>
using namespace cv;
// Struct tanımı
struct CamFrameId {
    cv::Mat frame;
    QString id;
};
#endif // VERI_H
#endif // CAMFRAMEID_H
