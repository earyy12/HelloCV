#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>


using namespace cv;
using namespace std;

Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;

void getContours(Mat imgDil,Mat img){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    
    
    //过滤面积小的轮廓并绘制
    for(int i=0;i<contours.size();i++){
        double area=contourArea(contours[i]);
        cout<<area<<endl;
        if(area>1000){
            drawContours(img,contours,-1,Scalar(255,0,255),10);
    }
}
}




int main(){
    string path = "resources/1.jpg";
    Mat img = imread(path);

    cvtColor(img,imgGray,COLOR_BGR2GRAY);//转为灰度图
    GaussianBlur(imgGray,imgBlur,Size(7,7),5,0);//进行模糊化
    Canny(imgBlur,imgCanny,50,150);//进行边缘检测

    Mat kernel=getStructuringElement(MORPH_RECT,Size(5,5));
    dilate(imgCanny,imgDil,kernel);//进行膨胀操作

    getContours();//查找轮廓并绘制在原图上
   
    imshow("Image",img);
    
    waitKey(0);
    
    return 0;
}