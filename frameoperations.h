#ifndef FRAMEOPERATIONS_H
#define FRAMEOPERATIONS_H

#include <QObject>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <QDebug>
using namespace cv;
class FrameOperations : public QObject
{
    Q_OBJECT
public:
    explicit FrameOperations(QObject *parent = nullptr);
    Mat combineFrames(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2, const Mat& frame_3, const Mat& frame_4, const Mat& frame_5, const Mat& frame_6, const Mat& frame_7, int id);
    Mat combineFrames(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2, const Mat& frame_3, const Mat& frame_4, const Mat& frame_5, int id);
    Mat combineFrames(const Mat &frame_0, const Mat &frame_1, const Mat &frame_2, const Mat &frame_3, const Mat &frame_4, int id);
    Mat combineFrames(const Mat &frame_0, const Mat &frame_1, const Mat &frame_2, const Mat &frame_3, int id);

    Mat combineFrames(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2);
    Mat combineFrames(const Mat& frame_0, const Mat& frame_1);
    Mat combineFrames(const Mat& frame_0);

    Mat combineFramesVertical(const Mat& frame_0, const Mat& frame_1);
    Mat combineFramesVertical(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2);
    Mat combineFramesVertical(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2, const Mat& frame_3);

signals:

private:
    cv::Mat temp_1;
    cv::Mat temp_2;
    cv::Mat temp_3;
    cv::Mat temp_4;
};

#endif // FRAMEOPERATIONS_H
