#ifndef STARTPROCESS_H
#define STARTPROCESS_H

#include <QObject>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QQueue>
#include <QMutex>
#include <QtNetwork>
#include <QThread>
#include <QImage>
#include <QUdpSocket>
#include "cameracapture.h"
#include "CamFrameId.h"
#include "frameoperations.h"
//#include "x264_encoder.h"
//#include "h264encoder.h"

class StartProcess : public QObject
{
    Q_OBJECT
public:
    explicit StartProcess(QObject *parent = nullptr);
    CameraCapture *cap_0;
    CameraCapture *cap_1;
    CameraCapture *cap_2;
    CameraCapture *cap_3;
    CameraCapture *cap_4;
    CameraCapture *cap_5;
    CameraCapture *cap_6;
    CameraCapture *cap_7;
    bool startListening(quint16 port);
public slots:
    void newFrameCamera_0();
    void newFrameCamera_1();
    void newFrameCamera_2();
    void newFrameCamera_3();
    void newFrameCamera_4();
    void newFrameCamera_5();
    void newFrameCamera_6();
    void newFrameCamera_7();

    void processPendingDatagrams(QByteArray message);
    QImage matToQImage(const cv::Mat &mat);
    void readPendingDatagrams();

signals:

private:
    cv::VideoWriter *m_writer;
    QUdpSocket *socket;
    // cv::cudacodec::VideoWriter *c_writer;

    //std::string pipeline = "appsrc  ! videoconvert ! x264enc tune=zerolatency bitrate=4096 speed-preset=superfast ! h264parse  ! rtph264pay config-interval=1 pt=96 ! udpsink sync=1 host=172.28.0.100  port=5000";
    //std::string pipeline = "appsrc  ! videoconvert ! x264enc tune=zerolatency openh264enc bitrate=4096 speed-preset=superfast ! rtph264pay config-interval=1 pt=96 ! udpsink host=192.168.1.100 port=5000";
    //std::string pipeline = "appsrc ! videoconvert ! video/x-raw,format=BGR  ! videoconvert ! x264enc tune=zerolatency bitrate=4096  speed-preset=superfast ! h264parse ! rtph264pay config-interval=1 pt=96 ! udpsink host=172.28.0.108 port=5000";

    //15ms CPU
    //std::string pipeline = "appsrc  is-live=true ! videoconvert ! x264enc noise-reduction=10000 byte-stream=true threads=8 tune=zerolatency  bitrate=8192 speed-preset=superfast ! h264parse ! rtph264pay ! udpsink host=172.28.0.106  port=5005 auto-multicast=false sync=true";

    //std::string pipeline = "appsrc ! videoconvert ! videoscale ! video/x-raw,width=640,height=480 ! x264enc speed-preset=veryfast tune=zerolatency bitrate=640 ! rtspclientsink location=rtsp://127.0.0.1:5005/mystream";
    //RTSP
    //std::string pipeline = "appsrc ! videoconvert ! videoscale ! video/x-raw,width=1920,height=960 ! x264enc speed-preset=veryfast tune=zerolatency bitrate=4096 ! rtspclientsink location=rtsp://127.0.0.1:5005/mystream";



    //59ms Cuda
    //std::string pipeline = "appsrc ! video/x-raw,format=BGR,width=1920,height=1080,framerate=30/1 ! videoconvert ! video/x-raw,format=BGRx ! nvvideoconvert ! nvv4l2h264enc ! h264parse ! rtph264pay ! udpsink host=127.0.0.1 port=5000";
    //std::string pipeline = "appsrc  ! nvvideoconvert ! queue max-size-buffers=1000 ! video/x-raw(memory:NVMM),width=(int)1920, height=(int)1280, format=I420, framerate=30/1 ! nvv4l2h264enc control-rate=1  bitrate=8000000 iframeinterval=300  idrinterval=30 ! rtph264pay ! udpsink host=172.28.0.101 port=5005 auto-multicast=false";

    //std::string pipeline = "appsrc ! videoconvert ! x264enc tune=zerolatency bitrate=2048 speed-preset=ultrafast ! rtph264pay ! udpsink host=192.168.1.150 port=5005 sync=false";
    //std::string pipeline = "appsrc ! videoconvert !  x264enc tune=zerolatency  bitrate=2048 speed-preset=ultrafast ! rtph264pay ! udpsink host=127.0.0.1 port=5005 sync=false";

    //çalışan
    std::string pipeline = "appsrc !  videoconvert ! x264enc threads=900 speed-preset=veryfast tune=zerolatency bitrate=2048 ! rtph264pay ! udpsink host=172.28.0.134 port=5005 sync=false";

    cv::Mat m_temp_0 ;
    cv::Mat m_temp_1 ;
    cv::Mat m_temp_2 ;
    cv::Mat m_temp_3 ;
    cv::Mat m_temp_4 ;
    cv::Mat m_temp_5 ;
    cv::Mat m_temp_6 ;
    cv::Mat m_temp_7 ;
    cv::Mat m_concatenated_frame;
    cv::Mat sendFrames(QQueue<CamFrameId> &matQueueMain);

    QQueue<CamFrameId> m_matQueueMain;

    QFuture<void> future_0;
    QFuture<void> future_1;
    QFuture<void> future_2;
    QFuture<void> future_3;
    QFuture<void> future_4;
    QFuture<void> future_5;
    QFuture<void> future_6;
    QFuture<void> future_7;

    FrameOperations *operationFrame;
    int selectedID = 1;

    int frameCounter = 0;

    QQueue<QString> queueTemp;
    QMutex locker;

    QUdpSocket *udpSocket = new QUdpSocket();
    //x264Encoder m_x264Encoder;
    uchar* data = nullptr;
    cv::Mat dst;
    int size;

    // h264Encoder h264;
    // AvH264EncConfig conf;
};

#endif // STARTPROCESS_H
