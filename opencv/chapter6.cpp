#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat imgHSV,mask;
int bmin=0, gmin=110, rmin=153;
int bmax=19, gmax=240, rmax=255;

int main(){
    string path ="resources/1.jpg";
    Mat img = imread(path);

    cvtColor(img,imgHSV,COLOR_BGR2HSV);//转换为颜色空间

    namedWindow("Trackbars",(640,200));
    createTrackbar("B_MIN","Trackbars",&bmin,255);
    createTrackbar("G_MIN","Trackbars",&gmin,255);
    createTrackbar("R_MIN","Trackbars",&rmin,255);
    createTrackbar("B_MAX","Trackbars",&bmax,255);
    createTrackbar("G_MAX","Trackbars",&gmax,255);
    createTrackbar("R_MAX","Trackbars",&rmax,255);

    while(true){
    Scalar lower(bmin,gmin,rmin);
    Scalar upper(bmax,gmax,rmax);
    inRange(imgHSV,lower,upper,mask);

    imshow("Image", img);
    imshow("Image HSV", imgHSV);
    imshow("Mask", mask);
    int key=waitKey(1);
    if(key==27){
        break;  
    }
}


    return 0;
}