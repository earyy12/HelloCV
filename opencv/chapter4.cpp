#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){
    Mat img(512,512,CV_8UC3,Scalar(255,255,255));//先定义一个背景版

    //circle(img,Point(256,256),155,Scalar(0,69,255),5);   // 画一个空心圆
    circle(img,Point(256,256),155,Scalar(0,69,255),FILLED);  // 画一个实心圆

    //rectangle(img,Point(130,226),Point(382,286),Scalar(255,255,255),5);   // 画一个空心矩形
    rectangle(img,Point(130,226),Point(382,286),Scalar(255,255,255),FILLED);  // 画一个实心矩形

    line(img,Point(130,296),Point(382,296),Scalar(255,255,255),2); // 画一条直线

    putText(img,"difficuit",Point(137,262),FONT_HERSHEY_DUPLEX,1.5,Scalar(0,69,255),2);   //输入文本

    imshow("Image",img);
    waitKey(0);
    return 0;
}