#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QtConcurrent/QtConcurrent>
#include <QDebug>
#include <QQueue>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc.hpp>
// #include <opencv4/opencv2/cudacodec.hpp>
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace cv;
using namespace std;
using namespace chrono;

class CameraCapture : public QObject, QQueue<QString>
{
    Q_OBJECT
public:
    explicit CameraCapture(QObject *parent = nullptr, QString id = "0", QQueue<QString> *queueTemp= nullptr, QMutex *locker= nullptr);
    Mat Frame;
    void captureFrame();
    QString m_id;
    QQueue<QString> *m_queueTemp;
    QMutex *m_locker;
    QMutex locker;

    VideoCapture *Cap;

signals:
    void getFrame();

public slots:

private:
};

#endif // CAMERACAPTURE_H
