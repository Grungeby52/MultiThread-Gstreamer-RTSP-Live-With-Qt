#include "frameoperations.h"

FrameOperations::FrameOperations(QObject *parent)
    : QObject{parent}
{

}

Mat FrameOperations::combineFrames(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2, const Mat& frame_3, const Mat& frame_4, const Mat& frame_5, const Mat& frame_6, const Mat& frame_7, int id) {

    if (id == 0) {
        cv::Mat temp_resize;
        cv::resize(frame_0,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(temp_resize,frame_1,frame_2,frame_3);
        cv::Mat temp_2 = combineFrames(temp_1,frame_0);
        cv::Mat temp_3 = combineFramesVertical(frame_4,frame_5,frame_6,frame_7);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;

    }
    else if(id == 1) {
        cv::Mat temp_resize;
        cv::resize(frame_1,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,temp_resize,frame_2,frame_3);
        cv::Mat temp_2 = combineFrames(temp_1,frame_1);
        cv::Mat temp_3 = combineFramesVertical(frame_4,frame_5,frame_6,frame_7);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;

    }
    else if (id ==2) {
        cv::Mat temp_resize;
        cv::resize(frame_2,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,temp_resize,frame_3);
        cv::Mat temp_2 = combineFrames(temp_1,frame_2);
        cv::Mat temp_3 = combineFramesVertical(frame_4,frame_5,frame_6,frame_7);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;

    }
    else if (id ==3) {
        cv::Mat temp_resize;
        cv::resize(frame_3,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,frame_2,temp_resize);
        cv::Mat temp_2 = combineFrames(temp_1,frame_3);
        cv::Mat temp_3 = combineFramesVertical(frame_4,frame_5,frame_6,frame_7);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if (id ==4) {
        cv::Mat temp_resize;
        cv::resize(frame_4,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,frame_2,frame_3);
        cv::Mat temp_2 = combineFrames(temp_1,frame_4);
        cv::Mat temp_3 = combineFramesVertical(temp_resize,frame_5,frame_6,frame_7);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if (id ==5) {
        cv::Mat temp_resize;
        cv::resize(frame_5,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,frame_2,frame_3);
        cv::Mat temp_2 = combineFrames(temp_1,frame_5);
        cv::Mat temp_3 = combineFramesVertical(frame_4,temp_resize,frame_6,frame_7);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if (id ==6) {
        cv::Mat temp_resize;
        cv::resize(frame_6,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,frame_2,frame_3);
        cv::Mat temp_2 = combineFrames(temp_1,frame_6);
        cv::Mat temp_3 = combineFramesVertical(frame_4,frame_5,temp_resize,frame_7);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if (id ==7) {
        cv::Mat temp_resize;
        cv::resize(frame_7,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,frame_2,frame_3);
        cv::Mat temp_2 = combineFrames(temp_1,frame_7);
        cv::Mat temp_3 = combineFramesVertical(frame_4,frame_5,frame_6,temp_resize);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
}

Mat FrameOperations::combineFrames(const Mat &frame_0, const Mat &frame_1, const Mat &frame_2, const Mat &frame_3, const Mat &frame_4, const Mat &frame_5, int id)
{
    if (id == 0) {
        cv::Mat temp_resize;
        cv::resize(frame_0,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(temp_resize,frame_1,frame_2);
        cv::Mat temp_2 = combineFrames(temp_1,frame_0);
        cv::Mat temp_3 = combineFramesVertical(frame_3,frame_4,frame_5);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if(id == 1) {
        cv::Mat temp_resize;
        cv::resize(frame_1,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,temp_resize,frame_2);
        cv::Mat temp_2 = combineFrames(temp_1,frame_1);
        cv::Mat temp_3 = combineFramesVertical(frame_3,frame_4,frame_5);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if (id ==2) {
        cv::Mat temp_resize;
        cv::resize(frame_2,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,temp_resize);
        cv::Mat temp_2 = combineFrames(temp_1,frame_2);
        cv::Mat temp_3 = combineFramesVertical(frame_3,frame_4,frame_5);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if (id ==3) {
        cv::Mat temp_resize;
        cv::resize(frame_3,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,frame_2);
        cv::Mat temp_2 = combineFrames(temp_1,frame_3);
        cv::Mat temp_3 = combineFramesVertical(temp_resize,frame_4,frame_5);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if (id ==4) {
        cv::Mat temp_resize;
        cv::resize(frame_4,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,frame_2);
        cv::Mat temp_2 = combineFrames(temp_1,frame_4);
        cv::Mat temp_3 = combineFramesVertical(frame_3,temp_resize,frame_5);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
    else if (id ==5) {
        cv::Mat temp_resize;
        cv::resize(frame_5,temp_resize,cv::Size(320,320));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1,frame_2);
        cv::Mat temp_2 = combineFrames(temp_1,frame_5);
        cv::Mat temp_3 = combineFramesVertical(frame_3,frame_4,temp_resize);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;
    }
}

Mat FrameOperations::combineFrames(const Mat &frame_0, const Mat &frame_1, const Mat &frame_2, const Mat &frame_3, const Mat &frame_4, int id)
{
    if (id == 0) {
        cv::Mat temp_resize;
        cv::resize(frame_0,temp_resize,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(frame_1,frame_2);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize);
        cv::Mat temp_3 = combineFramesVertical(frame_3,frame_4);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;

    }
    else if(id == 1) {
        cv::Mat temp_resize;
        cv::resize(frame_1,temp_resize,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_2);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize);
        cv::Mat temp_3 = combineFramesVertical(frame_3,frame_4);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;

    }
    else if (id ==2) {
        cv::Mat temp_resize;
        cv::resize(frame_2,temp_resize,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize);
        cv::Mat temp_3 = combineFramesVertical(frame_3,frame_4);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;

    }
    else if (id ==3) {
        cv::Mat temp_resize;
        cv::resize(frame_3,temp_resize,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize);
        cv::Mat temp_3 = combineFramesVertical(frame_2,frame_4);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;

    }
    else if (id ==4) {
        cv::Mat temp_resize;
        cv::resize(frame_4,temp_resize,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize);
        cv::Mat temp_3 = combineFramesVertical(frame_2,frame_3);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);
        return temp_4;

    }

}

Mat FrameOperations::combineFrames(const Mat &frame_0, const Mat &frame_1, const Mat &frame_2, const Mat &frame_3, int id)
{

    //qDebug()<<"id FrameProcessor"<<id;
    if (id==0) {
        cv::Mat temp_resize;
        cv::Mat temp_resize_Main;

        cv::resize(frame_0,temp_resize,cv::Size(400,400));
        cv::resize(frame_0,temp_resize_Main,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(temp_resize,frame_1);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize_Main);
        cv::Mat temp_3 = combineFramesVertical(frame_2,frame_3);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);


        return temp_4;
    }
    else if (id==1) {
        cv::Mat temp_resize;
        cv::Mat temp_resize_Main;

        cv::resize(frame_1,temp_resize,cv::Size(400,400));
        cv::resize(frame_1,temp_resize_Main,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(frame_0,temp_resize);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize_Main);
        cv::Mat temp_3 = combineFramesVertical(frame_2,frame_3);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);


        return temp_4;
    }
    else if (id==2) {
        cv::Mat temp_resize;
        cv::Mat temp_resize_Main;

        cv::resize(frame_2,temp_resize,cv::Size(400,400));
        cv::resize(frame_2,temp_resize_Main,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize_Main);
        cv::Mat temp_3 = combineFramesVertical(temp_resize,frame_3);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);


        return temp_4;
    }
    else if (id==3) {
        cv::Mat temp_resize;
        cv::Mat temp_resize_Main;

        cv::resize(frame_3,temp_resize,cv::Size(400,400));
        cv::resize(frame_3,temp_resize_Main,cv::Size(800,800));
        cv::Mat temp_1 = combineFramesVertical(frame_0,frame_1);
        cv::Mat temp_2 = combineFrames(temp_1,temp_resize_Main);
        cv::Mat temp_3 = combineFramesVertical(frame_2,temp_resize);
        cv::Mat temp_4 = combineFrames(temp_2,temp_3);


        return temp_4;
    }

}

Mat FrameOperations::combineFrames(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2) {
    int height = max(frame_0.rows, max(frame_1.rows, frame_2.rows));
    int width = frame_0.cols + frame_1.cols + frame_2.cols;

    Mat combinedFrame(height, width, frame_0.type());
    frame_0.copyTo(combinedFrame(Rect(0, 0, frame_0.cols, frame_0.rows)));
    frame_1.copyTo(combinedFrame(Rect(frame_0.cols, 0, frame_1.cols, frame_1.rows)));
    frame_2.copyTo(combinedFrame(Rect(frame_0.cols + frame_1.cols, 0, frame_2.cols, frame_2.rows)));
    return combinedFrame;
    // return combinedFrame;
}

Mat FrameOperations::combineFramesVertical(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2, const Mat& frame_3) {
    int width = max(frame_0.cols, max(frame_1.cols, max(frame_2.cols, frame_3.cols)));
    int height = frame_0.rows + frame_1.rows + frame_2.rows + frame_3.rows;

    Mat combinedFrame(height, width, frame_0.type());

    frame_0.copyTo(combinedFrame(Rect(0, 0, frame_0.cols, frame_0.rows)));
    frame_1.copyTo(combinedFrame(Rect(0, frame_0.rows, frame_1.cols, frame_1.rows)));
    frame_2.copyTo(combinedFrame(Rect(0, frame_0.rows + frame_1.rows, frame_2.cols, frame_2.rows)));
    frame_3.copyTo(combinedFrame(Rect(0, frame_0.rows + frame_1.rows + frame_2.rows, frame_3.cols, frame_3.rows)));
    return combinedFrame;
}

Mat FrameOperations::combineFramesVertical(const Mat& frame_0, const Mat& frame_1, const Mat& frame_2) {
    int width = max(frame_0.cols, max(frame_1.cols, frame_2.cols));
    int height = frame_0.rows + frame_1.rows + frame_2.rows;

    Mat combinedFrame(height, width, frame_0.type());

    frame_0.copyTo(combinedFrame(Rect(0, 0, frame_0.cols, frame_0.rows)));
    frame_1.copyTo(combinedFrame(Rect(0, frame_0.rows, frame_1.cols, frame_1.rows)));
    frame_2.copyTo(combinedFrame(Rect(0, frame_0.rows + frame_1.rows, frame_2.cols, frame_2.rows)));

    return combinedFrame;
}

Mat FrameOperations::combineFramesVertical(const Mat& frame_0, const Mat& frame_1) {
    int width = max(frame_0.cols, frame_1.cols);
    int height = frame_0.rows + frame_1.rows;

    Mat combinedFrame(height, width, frame_0.type());
    frame_0.copyTo(combinedFrame(Rect(0, 0, frame_0.cols, frame_0.rows)));
    frame_1.copyTo(combinedFrame(Rect(0, frame_0.rows, frame_1.cols, frame_1.rows)));

    return combinedFrame;
}

Mat FrameOperations::combineFrames(const Mat& frame_0, const Mat& frame_1) {
    int height = max(frame_0.rows, frame_1.rows);
    int width = frame_0.cols + frame_1.cols;

    Mat combinedFrame(height, width, frame_0.type());
    frame_0.copyTo(combinedFrame(Rect(0, 0, frame_0.cols, frame_0.rows)));
    frame_1.copyTo(combinedFrame(Rect(frame_0.cols, 0, frame_1.cols, frame_1.rows)));

    return combinedFrame;
}

Mat FrameOperations::combineFrames(const Mat &frame_0)
{
    return frame_0;
}
