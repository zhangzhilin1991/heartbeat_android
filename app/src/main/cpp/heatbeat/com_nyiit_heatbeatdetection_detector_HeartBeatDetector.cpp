//
// Created by nyiit on 20-3-5.
//

#ifndef com_nyiit_heatbeatdetection_detector_HeartBeatDetector_cpp
#define com_nyiit_heatbeatdetection_detector_HeartBeatDetector_cpp

#include <include/opencv.hpp>
#include "com_nyiit_heatbeatdetection_detector_HeartBeatDetector.h"

//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include "opencv.hpp"
//#include "Baseline.hpp"
#include <time.h>
//#include "RPPG.cpp"

#define DEFAULT_RPPG_ALGORITHM "g"
#define DEFAULT_FACEDET_ALGORITHM "haar"
#define DEFAULT_RESCAN_FREQUENCY 1
#define DEFAULT_SAMPLING_FREQUENCY 1
#define DEFAULT_MIN_SIGNAL_SIZE 5
#define DEFAULT_MAX_SIGNAL_SIZE 5
#define DEFAULT_DOWNSAMPLE 1 // x means only every xth frame is used

#define HAAR_CLASSIFIER_PATH "algomodel/haar/haarcascade_frontalface_alt.xml"
#define DNN_PROTO_PATH "algomodel/dnn/deploy.prototxt"
#define DNN_MODEL_PATH "algomodel/dnn/res10_300x300_ssd_iter_140000.caffemodel"

using namespace cv;
using namespace std;

#include <android/log.h>
#include <RPPG.hpp>
//#include <opencv2/features2d.hpp>

#define LOG_TAG "FaceDetection/DetectionBasedTracker"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

RPPG rppg;
rPPGAlgorithm rPPGAlg;
faceDetAlgorithm faceDetAlg;
bool isInit = false;

rPPGAlgorithm to_rppgAlgorithm(string s) {
    rPPGAlgorithm result;
    if (s == "g")
    {
        result = g;
    }
    else if (s == "pca")
    {
        result = pca;
    }
    else
    {
        result = xminay;
    }
    return result;
}

faceDetAlgorithm  to_faceDetAlgorithm(string s) {
    faceDetAlgorithm result;
    if (s == "haar")
    {
        result = haar;
    }
    else if (s == "deep")
    {
        result = deep;
    }
    else //default
    {
        result = mtcnn_deep;
    }
    return result;
}

bool initRPPG(int width, int height) {
    if (isInit == false) {
        rPPGAlg = to_rppgAlgorithm(DEFAULT_RPPG_ALGORITHM);
        faceDetAlg =  to_faceDetAlgorithm(DEFAULT_FACEDET_ALGORITHM);
        double rescanFrequency = DEFAULT_RESCAN_FREQUENCY;
        double samplingFrequency = DEFAULT_SAMPLING_FREQUENCY;
        int  minSignalSize = DEFAULT_MIN_SIGNAL_SIZE;
        int maxSignalSize = DEFAULT_MAX_SIGNAL_SIZE;
        int downsample = DEFAULT_DOWNSAMPLE;
        string LOG_PATH = "sdcard/heartbeat/Live_ffmpeg";

        // Load video information
        const int WIDTH = width;
        const int HEIGHT = height;
        //const double FPS = cap.get(cv::CAP_PROP_FPS);
        const double TIME_BASE = 0.001;

        //rppg = cv::Ptr<RPPG>(new RPPG());
        rppg = RPPG();
        return rppg.load(rPPGAlg, faceDetAlg,
                          WIDTH, HEIGHT, TIME_BASE, downsample,
                          samplingFrequency, rescanFrequency,
                          minSignalSize, maxSignalSize,
                          LOG_PATH, HAAR_CLASSIFIER_PATH,
                          DNN_PROTO_PATH, DNN_MODEL_PATH,
                          false, false, 250);
    }
    return false;
}

/**
 * call initRPPG first
 * @param imageRgba
 * @param imageGray
 */
void process(Mat& imageRgba, Mat& imageGray) { //ref
    if (isInit == false) {
        isInit = initRPPG(imageRgba.cols, imageRgba.rows);
    }
    // 计算当前是第几帧
    rppg.countFrame();

    // 对图像做镜像翻转
    //flip(frameRGB, frameRGB, 1);

    // 产生灰度图像
    //cvtColor(frameRGB, frameGray, COLOR_BGR2GRAY);
    //equalizeHist(frameGray, frameGray);

    int time;
    // 如果读取视频文件进行测试，建议打开下行注释
    // offlineMode = true;
    //if (offlineMode) {
        //time = videoReader.get(cv::CAP_PROP_POS_MSEC);
    //    time = cap.get(cv::CAP_PROP_POS_MSEC);
    //} else {
        time = (cv::getTickCount()*1000.0)/cv::getTickFrequency();
    //}

    // 主要处理部分
    //if (i % downsample == 0) {
        rppg.processFrame(imageRgba, imageGray, time, rppg.face_detector);
    //} else {
     //   cout << "SKIPPING FRAME TO DOWNSAMPLE!" << endl;
    //}

    //if (baseline_input != "") {
    //    baseline.processFrame(frameRGB, time);
    //}

    //int after_time = (cv::getTickCount() * 1000.0) / cv::getTickFrequency() - start;
}

/*
* Class:     com_nyiit_heatbeatdetection_detector_HeartBeatDetector
* Method:    detectHeartBeat
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_nyiit_heatbeatdetection_detector_HeartBeatDetector_detectHeartBeat
(JNIEnv *env, jclass cls, jlong rgbaAddr, jlong greyAddr)
{
    Mat& mRgb  = *(Mat*)rgbaAddr; //ref
    Mat& mGr = *(Mat*)greyAddr; //ref

    //try {
    int rgbWidth = mRgb.cols;
    int rgbHeight = mRgb.rows;
    LOGD("mRgb width: %d, height: %d", rgbWidth, rgbHeight);

    int greyWidth = mGr.cols;
    int greyHeight = mGr.rows;
    LOGD("mGr width: %d, height: %d", greyWidth, greyHeight);

    std::stringstream str;
    str.str("test");
    str << "width: ";
    str << rgbWidth;
    str << ", height: ";
    str << rgbHeight;
    putText(mRgb, str.str(), Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0, 255), 2);

        //initRPPG(width, height); /
        process(mRgb, mGr);
    //} (
    //

    /*String text = "Funny text inside the box";
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 2;
    int thickness = 3;

    //Mat img(600, 800, CV_8UC3, Scalar::all(0));

    int baseline=0;
    Size textSize = getTextSize(text, fontFace,
                                fontScale, thickness, &baseline);
    baseline += thickness;

    // center the text
    Point textOrg((mRgb.cols - textSize.width)/2,
                  (mRgb.rows + textSize.height)/2);

    // draw the box
    rectangle(mRgb, textOrg + Point(0, baseline),
              textOrg + Point(textSize.width, -textSize.height),
              Scalar(0,0,255));
    // ... and the baseline first
    line(mRgb, textOrg + Point(0, thickness),
         textOrg + Point(textSize.width, thickness),
         Scalar(0, 0, 255));

    // then put the text itself
    putText(mRgb, text, textOrg, fontFace, fontScale,
            Scalar::all(255), thickness, 8);
            */
}

#endif