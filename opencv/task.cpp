#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

//定义颜色范围
Scalar redLower1 = Scalar(0, 120, 70);
Scalar redUpper1 = Scalar(10, 255, 255);
Scalar redLower2 = Scalar(170, 120, 70);
Scalar redUpper2 = Scalar(180, 255, 255);//豆包说红色范围是断开的，要写来两个，然后在和起来
Scalar greenLower = Scalar(40, 70, 70);
Scalar greenUpper = Scalar(80, 255, 255);//这个颜色参数是网上找的

// 检测绿色并返回最大轮廓及其面积
double detectGreenAndGetContour(Mat &frame, vector<Point> &maxContour) {
    Mat hsv, mask;
    cvtColor(frame, hsv, COLOR_BGR2HSV);
    inRange(hsv, greenLower, greenUpper, mask);
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
    dilate(mask,mask,kernel);

    vector<vector<Point>> contours;
    findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    double maxArea = 0;
    maxContour.clear();//清空之前的轮廓数据
    for (size_t i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i]);
        if (area > 50 && area > maxArea) {
            maxArea = area;
            maxContour = contours[i];
        }
    }
    return maxArea;
}

//检测红色并返回最大轮廓及其面积
double detectRedAndGetContour(Mat &frame, vector<Point> &maxContour) {
    Mat hsv, mask1, mask2, mask;
    cvtColor(frame, hsv, COLOR_BGR2HSV);
    inRange(hsv, redLower1, redUpper1, mask1);
    inRange(hsv, redLower2, redUpper2, mask2);
    mask = mask1 | mask2;  //合并红色范围
    
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
    dilate(mask,mask,kernel);
    
    vector<vector<Point>> contours;
    findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    double maxArea = 0;
    maxContour.clear();
    for (size_t i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i]);
        if (area > 50 && area > maxArea) {
            maxArea = area;
            maxContour = contours[i];
        }
    }
    return maxArea;
}

int main() {
    VideoCapture cap("resources/TrafficLight.mp4");
    
    Mat frame;
    string resultText;
    double AREA_THRESHOLD = 100;
    
    namedWindow("1", WINDOW_NORMAL);
    
    while (true) {
        cap >> frame;
        
        //存储两种颜色的最大轮廓
        vector<Point> redContour, greenContour;
        
        //检测两种颜色并获取轮廓
        double redArea = detectRedAndGetContour(frame, redContour);
        double greenArea = detectGreenAndGetContour(frame,greenContour);
        
        //确定结果和对应的轮廓
        vector<Point> targetContour;
        if (redArea > greenArea && redArea > AREA_THRESHOLD) {
            resultText = "Red Light";
            targetContour = redContour;
        } else if (greenArea > redArea && greenArea > AREA_THRESHOLD) {
            resultText = "Green Light";
            targetContour = greenContour;
        } else {
            resultText = "No Signal Detected";
            targetContour.clear();
        }
        
        // 绘制识别框
        if (!targetContour.empty()) {
        Rect BoundingRect = boundingRect(targetContour);
        Scalar boxColor = Scalar(255, 0, 0);
        rectangle(frame, BoundingRect, boxColor, 2);
        }
        
        
        // 显示识别结果
        putText(frame, resultText, Point(30, 50), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(255,0,0), 2);
        
        // 显示图像
        imshow("Traffic Light Detection", frame);
        
        // ESC退出
        char key = waitKey(30);
        if (key == 27) break;         
    }
    return 0;
}