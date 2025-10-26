#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){
    string path = "resources/1.jpg";
    Mat img = imread(path);
    Mat imgResize,imgCrop;

    //cout<<img.size()<<endl;    //1280*1280
    //resize(img,imgResize,Size(640,640));    //将图像大小调整为640*640
    resize(img,imgResize,Size(),0.5,0.5);    //将图像大小调整为原来的一半

    Rect roi(100,100,300,300); //定义一个矩形区域：x=100,y=100,width=300,height=300
    imgCrop=img(roi); 

    imshow("Image",img);
    imshow("Image Resize",imgResize);
    imshow("Image Crop",imgCrop);
    waitKey(0);
    
    return 0;
}