#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

float w=250,h=350;
Mat imgWarp, martrix;

int main(){
    string path ="resources/2.jpeg";
    Mat img = imread(path);

    Point2f src[4]={{287,83},{641,181},{111,578},{495,696}};//通过gimp打开图片获取的点
    Point2f dst[4]={{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};

    martrix=getPerspectiveTransform(src,dst);
    warpPerspective(img, imgWarp, martrix, Point(w,h));

    for(int i=0;i<4;i++){
        circle(img,src[i],10,Scalar(0,0,255),FILLED);
    }

    imshow("Image", img);
    imshow("Image Warp", imgWarp);
    waitKey(0);


    return 0;
}