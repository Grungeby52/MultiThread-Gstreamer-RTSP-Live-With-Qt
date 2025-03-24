#include "cameracapture.h"

CameraCapture::CameraCapture(QObject *parent, QString id, QQueue<QString> *queueTemp,    QMutex *locker)
    : QObject(parent),m_id(id),m_queueTemp(queueTemp),m_locker(locker)
{
    std::string pipeline;
    if(id==QString("/dev/video7").toStdString().c_str())
        pipeline = "rtspsrc location=rtsp://10.42.0.176/mainstream latency=0 ! rtph264depay ! avdec_h264 max-threads=900 ! videoconvert ! appsink sync=false";
    if(id==QString("/dev/video1").toStdString().c_str())
        pipeline = "rtspsrc location=rtsp://10.42.0.177/mainstream latency=0 ! rtph264depay ! avdec_h264 max-threads=900 ! videoconvert ! appsink sync=false";
    if(id==QString("/dev/video2").toStdString().c_str())
        pipeline = "rtspsrc location=rtsp://10.42.0.178/mainstream latency=0 ! rtph264depay ! avdec_h264 max-threads=900 ! videoconvert ! appsink sync=false ";
    if(id==QString("/dev/video3").toStdString().c_str())
        pipeline = "rtspsrc location=rtsp://10.42.0.179/mainstream latency=0 ! rtph264depay ! avdec_h264 max-threads=900 ! videoconvert ! appsink sync=false";

    qDebug()<<"Pipe Line:"<<pipeline;
    //std::cout<<"Kameralar Açılıyor..."<<std::endl;
    Cap = new VideoCapture(pipeline, cv::CAP_GSTREAMER);
    //Cap.open(id.toStdString().c_str());


    // QThread::currentThread()->msleep(100);
    // Cap.open(id.toStdString().c_str(),CAP_V4L2);
    // QThread::currentThread()->msleep(100);
    // Cap.open(id.toStdString().c_str(),CAP_V4L2);
    // QThread::currentThread()->msleep(100);
    //::cout<<"Set Start"<<std::endl;
    Cap->setExceptionMode(true);
    qDebug()<<"Exposure:"<<Cap->get(CAP_PROP_EXPOSURE);
    //std::cout<<"Set Finish"<<std::endl;

    //Cap.set(CAP_PROP_BUFFERSIZE,1);
    //qDebug()<<"Buffer:  "<<    Cap.get(CAP_PROP_BUFFERSIZE); // internal buffer will now store only 3 frames

    //Cap.set(CAP_PROP_BUFFERSIZE, 2); // internal buffer will now store only 3 frames
    if (!Cap->isOpened()) {
        qDebug() << "ERROR! Unable to open camera\n";
    }


    // try {
    //     Cap.set(CAP_PROP_FRAME_WIDTH, 1920);
    //     Cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
    // } catch (int e) {
    //     std::cout<<"Çözünürlük Set Edilemedi.";
    // }

    //Cap.set(CAP_PROP_FPS, 30);        // try {
    //     Cap.set(CAP_PROP_FRAME_WIDTH, 1920);
    //     Cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
    // } catch (int e) {
    //     std::cout<<"Çözünürlük Set Edilemedi.";
    // }// try {
    //     Cap.set(CAP_PROP_FRAME_WIDTH, 1920);
    //     Cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
    // } catch (int e) {
    //     std::cout<<"Çözünürlük Set Edilemedi.";
    // }

    qDebug()<<"ID:"<<id<<"  Inıtilaized Camera Settings, Start grabbing "<<"Fps:"<<Cap->get(CAP_PROP_FPS)<<"     FrameCount:"<<Cap->get(CAP_PROP_FRAME_COUNT) ;
    qDebug()<< "Inıtilaized Camera Settings, Start grabbing";
    qDebug()<<Cap->get(CAP_PROP_FRAME_WIDTH)<<" x "<<Cap->get(CAP_PROP_FRAME_HEIGHT);
    qDebug()<<"OpenCV Version:  "<<CV_VERSION;
    std::cout<<"Kameralar Açıldı."<<std::endl;


}
void CameraCapture::captureFrame()
{
    while (Cap->isOpened()) {
        //locker.lock();
        Cap->read(Frame);
        //locker.unlock();
        // auto now = system_clock::now();
        // auto now_ms = time_point_cast<milliseconds>(now);

        // auto ms = duration_cast<milliseconds>(now_ms.time_since_epoch()) % 1000;
        // time_t now_time = system_clock::to_time_t(now);
        // auto tm_now = localtime(&now_time);

        // stringstream ss;
        // ss << put_time(tm_now, "%H:%M:%S:") << setw(3) << setfill('0') << ms.count();
        // putText(Frame, ss.str(), Point(10, 70), FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 255, 255), 8);
        if (!Frame.empty()) {
            emit getFrame();
        }
        //QThread::currentThread()->msleep(1000/33);
        //locker.lock();
       //Frame.release();
        //locker.unlock();
    }
}
