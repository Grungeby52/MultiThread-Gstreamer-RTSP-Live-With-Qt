#include "startprocess.h"

StartProcess::StartProcess(QObject *parent)
    : QObject{parent}
{

    m_writer = new VideoWriter(pipeline, CAP_GSTREAMER, 0, 20, Size(1600, 800), true);

    // kumanda da ön
    cap_0 = new CameraCapture(nullptr,"/dev/video7",&queueTemp,&locker);
    future_0 = QtConcurrent::run(&CameraCapture::captureFrame, cap_0);
    connect(cap_0,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_0,Qt::QueuedConnection);
    // arka kemara
    cap_1 = new CameraCapture(nullptr,"/dev/video1",&queueTemp,&locker);
    future_1 = QtConcurrent::run(&CameraCapture::captureFrame, cap_1);
    connect(cap_1,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_1,Qt::QueuedConnection);
    //sol --- ÇALIŞMIYOR <<<<<<
    cap_2 = new CameraCapture(nullptr,"/dev/video2",&queueTemp,&locker);
    future_2 = QtConcurrent::run(&CameraCapture::captureFrame, cap_2);
    connect(cap_2,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_2,Qt::QueuedConnection);
    //sağ
    cap_3 = new CameraCapture(nullptr,"/dev/video3",&queueTemp,&locker);
    future_3 = QtConcurrent::run(&CameraCapture::captureFrame, cap_3);
    connect(cap_3,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_3,Qt::QueuedConnection);

    // cap_4 = new CameraCapture(nullptr,"4.mp4",&queueTemp,&locker);
    // future_4 = QtConcurrent::run(&CameraCapture::captureFrame, cap_4);
    // connect(cap_4,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_4,Qt::QueuedConnection);

    // cap_5 = new CameraCapture(nullptr,"5.mp4",&queueTemp,&locker);
    // future_5 = QtConcurrent::run(&CameraCapture::captureFrame, cap_5);
    // connect(cap_5,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_5,Qt::QueuedConnection);

    // cap_6 = new CameraCapture(nullptr,"6.mp4",&queueTemp,&locker);
    // future_6 = QtConcurrent::run(&CameraCapture::captureFrame, cap_6);
    // connect(cap_6,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_6,Qt::QueuedConnection);

    // cap_7 = new CameraCapture(nullptr,"7.mp4",&queueTemp,&locker);
    // future_7 = QtConcurrent::run(&CameraCapture::captureFrame, cap_7);
    // connect(cap_7,&CameraCapture::getFrame,this,&StartProcess::newFrameCamera_7,Qt::QueuedConnection);


    //m_writer = new VideoWriter(pipeline, 0, 30, Size(1920*1, 1080), true);
    //m_writer = new VideoWriter(pipeline, 0, 30, Size(1920*2, 1080), true);
    //m_writer = new VideoWriter(pipeline, 0, 30, Size(1920*3, 1080), true);
    //m_writer = new VideoWriter(pipeline, 0, 60, Size(1920*8, 1080), true);
    operationFrame = new FrameOperations();
    socket = new QUdpSocket(this);
    // connecttionRemote = udpConnectionFactory::createInstance();
    // / udpSocket->binimage_0d(QHostAddress("172.28.0.106"), 5000);
    // connect(connecttionRemote, &udpConnection::recieveCurrentCamData, this, &StartProcess::processPendingDatagrams,Qt::UniqueConnection);
    //m_x264Encoder.Create(1280,800,3,30);

}

bool StartProcess::startListening(quint16 port) {
    if (socket->bind(port)) {
        connect(socket, &QUdpSocket::readyRead, this, &StartProcess::readPendingDatagrams);
        qDebug() << "Listening on port" << port << "...";
        return true;
    } else {
        qDebug() << "Failed to bind socket to port" << port;
        return false;
    }
}

void StartProcess::readPendingDatagrams() {
    while (socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
         qDebug() << "Received datagram from" << sender.toString() << ":" << senderPort << "with data:" << datagram;
        bool ok;
         selectedID = static_cast<unsigned char>(datagram.at(0));
        qDebug()<<selectedID;

    }
}

QImage StartProcess::matToQImage(const cv::Mat &mat) {
    if(mat.type() == CV_8UC3) {
        // Renkli görüntüler (BGR formatı)
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_BGR888);
    } else if(mat.type() == CV_8UC1) {
        // Gri tonlamalı görüntüler
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
    }
    return QImage(); // Desteklenmeyen format
}

cv::Mat StartProcess::sendFrames(QQueue<CamFrameId> &queueSender)
{


    while (!queueSender.size() == 0) {

        CamFrameId temp = queueSender.dequeue();
        if (!temp.frame.empty()) {
            if (temp.id==cap_0->m_id) {
                m_temp_0 = temp.frame;
                if(selectedID == 0)
                    cv::resize(m_temp_0,m_temp_0,cv::Size(1280,1280));
                else
                    cv::resize(m_temp_0,m_temp_0,cv::Size(400,400));

            }
            if (temp.id==cap_1->m_id) {
                m_temp_1 = temp.frame;
                if(selectedID == 1)
                    cv::resize(m_temp_1,m_temp_1,cv::Size(1280,1280));
                else
                    cv::resize(m_temp_1,m_temp_1,cv::Size(400,400));

            }
            if (temp.id==cap_2->m_id) {
                m_temp_2 = temp.frame;
                if(selectedID == 2)
                    cv::resize(m_temp_2,m_temp_2,cv::Size(1280,1280));
                else
                    cv::resize(m_temp_2,m_temp_2,cv::Size(400,400));

            }
            if (temp.id==cap_3->m_id) {
                m_temp_3 = temp.frame;
                if(selectedID == 3)
                    cv::resize(m_temp_3,m_temp_3,cv::Size(1280,1280));
                else
                    cv::resize(m_temp_3,m_temp_3,cv::Size(400,400));

            }



            // if (temp.id==cap_4->m_id) {
            //     m_temp_4 = temp.frame;
            //     if(selectedID == 4)
            //         cv::resize(m_temp_4,m_temp_4,cv::Size(1280,1280));
            //     else
            //         cv::resize(m_temp_4,m_temp_4,cv::Size(400,400));
            // }
        }
        // if (temp.id==cap_5->m_id) {
        //     m_temp_5 = temp.frame;
        //     if(selectedID == 5)
        //         cv::resize(m_temp_5,m_temp_5,cv::Size(1280,1280));
        //     else
        //         cv::resize(m_temp_5,m_temp_5,cv::Size(320,320));
        // }
        // if (temp.id==cap_6->m_id) {
        //     m_temp_6 = temp.frame;
        //     if(selectedID ==6)
        //         cv::resize(m_temp_6,m_temp_6,cv::Size(1280,1280));
        //     else
        //         cv::resize(m_temp_6,m_temp_6,cv::Size(320,320));
        // }
        // if (temp.id==cap_7->m_id) {
        //     m_temp_7 = temp.frame;
        //     if(selectedID == 7)
        //         cv::resize(m_temp_7,m_temp_7,cv::Size(1280,1280));
        //     else
        //         cv::resize(m_temp_7,m_temp_7,cv::Size(320,320));
        // }
    }

    if(!m_temp_0.empty()&&!m_temp_1.empty()&&!m_temp_2.empty()&&!m_temp_3.empty()/*&&!m_temp_4.empty()*//*&&!m_temp_5.empty()&&!m_temp_6.empty()&&!m_temp_7.empty()*/){
        //m_concatenated_frame = operationFrame->combineFrames(m_temp_0,m_temp_1,m_temp_2,m_temp_3,m_temp_4,m_temp_5,m_temp_6,m_temp_7,selectedID);
        //m_concatenated_frame = operationFrame->combineFrames(m_temp_0,m_temp_1,m_temp_2,m_temp_3,m_temp_4,selectedID);
        m_concatenated_frame = operationFrame->combineFrames(m_temp_0,m_temp_1,m_temp_2,m_temp_3,selectedID);
        //cv::imwrite("frame.jpg",m_concatenated_frame);
        //m_concatenated_frame = operationFrame->combineFrames(m_temp_0,m_temp_1,m_temp_2);
        //m_concatenated_frame = operationFrame->combineFrames(m_temp_0,m_temp_1);
        //m_concatenated_frame = operationFrame->combineFrames(m_temp_5);
        //imwrite("com.jpg",m_concatenated_frame);
        //qDebug()<<m_concatenated_frame.cols<<"  "<<m_concatenated_frame.rows;
        //auto start_time = std::chrono::high_resolution_clock::now();
        //m_writer = new VideoWriter(pipeline, CAP_GSTREAMER, 0, 30, Size(1920, 1280), true);

        auto now = system_clock::now();
        auto now_ms = time_point_cast<milliseconds>(now);

        // Milisaniye cinsinden zamanı al
        auto ms = duration_cast<milliseconds>(now_ms.time_since_epoch()) % 1000;
        // Saat, dakika, saniye ve milisaniyeyi ayarla
        time_t now_time = system_clock::to_time_t(now);
        auto tm_now = localtime(&now_time);

        // Saati ve milisaniyeyi bir string'e dönüştür
        stringstream ss;
        ss <<"Sender  :" <<put_time(tm_now, "%H:%M:%S:") << setw(3) << setfill('0') << ms.count();
        // //qDebug()<<frameCounter;
        // // Frame oluşturma

        cv::resize(m_concatenated_frame,dst,cv::Size(1280,800));
        putText(dst, ss.str(), Point(160, 320), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 255, 255), 8);

        // size = m_x264Encoder.EncodeOneFrame(dst);
        // data = nullptr;
        // data = m_x264Encoder.GetEncodedFrame();


        //udpSocket->writeDatagram(reinterpret_cast<const char*>(data), size, QHostAddress("127.0.0.1"), 5005);

        //qDebug()<<"m_concatenated_frame_size:"<<m_concatenated_frame.cols<<"x"<<m_concatenated_frame.rows;
        m_writer->write(m_concatenated_frame);

        // delete m_writer;
        // auto end_time = std::chrono::high_resolution_clock::now();
        // double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
        // elapsed /= 1000000000;
        //qDebug()<<"FPS Detection: "<<1/(elapsed);

        //QThread::currentThread()->msleep(1000/33);
    }
    return m_concatenated_frame;
}

void StartProcess::processPendingDatagrams(QByteArray message) {

    QString string(message);
    qDebug()<<"Selected ID: "<<message;
    bool ok;
    int intValue = string.toInt(&ok);
    selectedID = intValue;
    //QThread::currentThread()->msleep(1000);
}

void StartProcess::newFrameCamera_0()
{
    Mat frame = cap_0->Frame;
    CamFrameId temp;
    // QImage tempQ ;
    // QImage qFrame =  matToQImage(frame);
    // tempQ = qFrame.mirrored(true,false);

    try {
        Mat mirrorFrame;
        flip(frame, mirrorFrame, 1);
        temp.frame = mirrorFrame;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV hatası: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Standart hata: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Bilinmeyen bir hata oluştu." << std::endl;
    }

    temp.id = cap_0->m_id;
    m_matQueueMain.enqueue(temp);
    //qDebug()<<"Grapping..._0"<<m_matQueueMain.size();


    if (m_matQueueMain.size() == 8) {
        //qDebug()<<"1 Gönderdi";
        // while (!matQueueMain.size()==0) {
        //     qDebug()<<matQueueMain.dequeue().frame.empty();
        // }
        sendFrames(m_matQueueMain);
    }
}

void StartProcess::newFrameCamera_1()
{
    Mat frame = cap_1->Frame;
    // Mat flippedFrame;
    // cv::flip(frame,flippedFrame,1);
    CamFrameId temp;
    temp.frame = frame;
    temp.id = cap_1->m_id;
    m_matQueueMain.enqueue(temp);
    //qDebug()<<"Grapping..._1"<<m_matQueueMain.size();

    if (m_matQueueMain.size() == 8) {
        //qDebug()<<"1 Gönderdi";
        // while (!matQueueMain.size()==0) {
        //     qDebug()<<matQueueMain.dequeue().frame.empty();
        // }
        sendFrames(m_matQueueMain);
    }
}

void StartProcess::newFrameCamera_2()
{
    Mat frame = cap_2->Frame;
    CamFrameId temp;
    temp.frame = frame;
    temp.id = cap_2->m_id;
    m_matQueueMain.enqueue(temp);
    //qDebug()<<"Grapping..._2"<<m_matQueueMain.size();

    if (m_matQueueMain.size() == 8) {
        //qDebug()<<"2 Gönderdi";
        // while (!matQueueMain.size()==0) {
        //     qDebug()<<matQueueMain.dequeue().frame.empty();
        // }
        sendFrames(m_matQueueMain);
    }
}

void StartProcess::newFrameCamera_3()
{
    Mat frame = cap_3->Frame;
    CamFrameId temp;
    temp.frame = frame;
    temp.id = cap_3->m_id;
    m_matQueueMain.enqueue(temp);
    //qDebug()<<"Grapping..._3"<<m_matQueueMain.size();

    if (m_matQueueMain.size() == 8) {
        //qDebug()<<"3 Gönderdi";
        // while (!matQueueMain.size()==0) {
        //     qDebug()<<matQueueMain.dequeue().frame.empty();
        // }
        sendFrames(m_matQueueMain);
    }
}

void StartProcess::newFrameCamera_4()
{
    Mat frame = cap_4->Frame;
    CamFrameId temp;
    temp.frame = frame;
    temp.id = cap_4->m_id;
    m_matQueueMain.enqueue(temp);
    //qDebug()<<"Grapping..._4"<<m_matQueueMain.size();

    if (m_matQueueMain.size() == 8) {
        //qDebug()<<"4 Gönderdi";
        // while (!matQueueMain.size()==0) {
        //     qDebug()<<matQueueMain.dequeue().frame.empty();
        // }
        sendFrames(m_matQueueMain);
    }
}

void StartProcess::newFrameCamera_5()
{
    Mat frame = cap_5->Frame;
    CamFrameId temp;
    temp.frame = frame;
    temp.id = cap_5->m_id;
    m_matQueueMain.enqueue(temp);
    //qDebug()<<"Grapping..._5"<<m_matQueueMain.size();

    if (m_matQueueMain.size() == 8) {
        // qDebug()<<"5 Gönderdi";
        // while (!matQueueMain.size()==0) {
        //     qDebug()<<matQueueMain.dequeue().frame.empty();
        // }
        sendFrames(m_matQueueMain);
    }
}

void StartProcess::newFrameCamera_6()
{
    Mat frame = cap_6->Frame;
    CamFrameId temp;
    temp.frame = frame;
    temp.id = cap_6->m_id;
    m_matQueueMain.enqueue(temp);
    //qDebug()<<"Grapping..._6"<<m_matQueueMain.size();

    if (m_matQueueMain.size() == 8) {
        //qDebug()<<"6 Gönderdi";
        // while (!matQueueMain.size()==0) {
        //     qDebug()<<matQueueMain.dequeue().frame.empty();
        // }
        sendFrames(m_matQueueMain);
    }
}

void StartProcess::newFrameCamera_7()
{
    Mat frame = cap_7->Frame;
    CamFrameId temp;
    temp.frame = frame;
    temp.id = cap_7->m_id;
    m_matQueueMain.enqueue(temp);
    //qDebug()<<"Grapping..._7"<<m_matQueueMain.size();

    if (m_matQueueMain.size() == 8) {
        //qDebug()<<"7 Gönderdi";
        // while (!matQueueMain.size()==0) {
        //     qDebug()<<matQueueMain.dequeue().frame.empty();
        // }
        sendFrames(m_matQueueMain);
    }
}
