package com.nyiit.heatbeatdetection;

import android.os.Bundle;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Display;

import com.nyiit.heatbeatdetection.detector.HeartBeatDetector;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraActivity;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.JavaCameraView;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.imgproc.Imgproc;

import java.util.Collections;
import java.util.List;

import static org.opencv.imgproc.Imgproc.FONT_HERSHEY_SIMPLEX;

public class CameraPreviewActivity extends CameraActivity implements CameraBridgeViewBase.CvCameraViewListener2 {

    public static final String TAG = CameraPreviewActivity.class.getName();

    // Used to load the 'native-lib' library on application startup.
    Mat mRgba;
    Mat mRgbaT;
    Mat mGray;
    Mat mGrayT;
    JavaCameraView mOpenCvCameraView;

    private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                    //mOpenCvCameraView.setDisplayOrientation(90);
                    System.loadLibrary("heartbeat");

                    mOpenCvCameraView.enableView();
                    break;
                default:
                    super.onManagerConnected(status);
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camerapreview);

        Display display = getWindow().getWindowManager().getDefaultDisplay();
        DisplayMetrics displayMetrics = new DisplayMetrics();
        display.getMetrics(displayMetrics);

        int width = displayMetrics.widthPixels;//宽度
        int height = displayMetrics.heightPixels;//高度

        Log.d(TAG, "display width: " + width + ", height: " + height);

        mOpenCvCameraView = findViewById(R.id.hb_activity_surface_view);
        mOpenCvCameraView.setVisibility(CameraBridgeViewBase.VISIBLE);
        mOpenCvCameraView.setMaxFrameSize(800, 600); //landscape
        mOpenCvCameraView.setCvCameraViewListener(this);
        // Example of a call to a native method
        //TextView tv = findViewById(R.id.sample_text);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (OpenCVLoader.initDebug()) {
            Log.d(TAG, "OpenCV library found inside package. Using it!");
            mLoaderCallback.onManagerConnected(LoaderCallbackInterface.SUCCESS);
        } else {
            Log.d(TAG, "OpenCV library not found inside package. exit!");
            this.finish();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (mOpenCvCameraView != null) {
            mOpenCvCameraView.disableView();
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mOpenCvCameraView.disableView();
    }

    @Override
    protected List<? extends CameraBridgeViewBase> getCameraViewList() {
        return Collections.singletonList(mOpenCvCameraView);
    }

    @Override
    public void onCameraViewStarted(int width, int height) {
        mRgba = new Mat(height, width, CvType.CV_8UC4);
        mRgbaT = new Mat(height, width, CvType.CV_8UC4);
        mGray = new Mat(height, width, CvType.CV_8UC1);
        mGrayT = new Mat();
    }

    @Override
    public void onCameraViewStopped() {
        mRgba.release();
        mGray.release();
        mGrayT.release();
    }

    @Override
    public Mat onCameraFrame(CameraBridgeViewBase.CvCameraViewFrame inputFrame) {

        mRgba = inputFrame.rgba();
        /*if (mRgbaT != null) {
            mRgbaT.release();
        }
        mRgbaT = mRgba.t();
        Core.flip(mRgbaT, mRgbaT, 1);
        Imgproc.resize(mRgbaT, mRgbaT, mRgba.size());

        mGray = inputFrame.gray();
        if (mGrayT != null) {
            mGrayT.release();
        }
        mGrayT = mGray.t();
        Core.flip(mGrayT, mGrayT, 1);
        Imgproc.resize(mGrayT, mGrayT, mGray.size());
        */


        //HeartBeatDetector.detectHeartBeat(mRgbaT, mGrayT);

        int fps = fps();
        Imgproc.putText(mRgba, "fps: " + fps, new Point(30,60),FONT_HERSHEY_SIMPLEX, 1, new Scalar(255,0,0,255), 2);
        //mRgba.release();
        return mRgba;
    }

    int fps = 0;
    long lastTime = System.currentTimeMillis(); // ms
    int frameCount = 0;

    int fps() {
        ++frameCount;

        long curTime = System.currentTimeMillis();
        if (curTime - lastTime > 1000) // 取固定时间间隔为1秒
        {
            fps = frameCount;
            frameCount = 0;
            lastTime = curTime;
        }
        return fps;

    }
}
