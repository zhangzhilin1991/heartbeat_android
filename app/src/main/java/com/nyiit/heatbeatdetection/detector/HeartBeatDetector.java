package com.nyiit.heatbeatdetection.detector;

import org.opencv.core.Mat;

public class HeartBeatDetector {



    /**
     * detect heart beat detect
     * @param rgba
     * @param gray
     */
    public static void detectHeartBeat(Mat rgba, Mat gray) {
        detectHeartBeat(rgba.getNativeObjAddr(), gray.getNativeObjAddr());
    }

    private native static void detectHeartBeat(long matAddrGr, long matAddrRgba);
}
