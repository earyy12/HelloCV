#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){
    VideoCapture cap(0); // 打开默认摄像头（编号为0）
    if (!cap.isOpened()) { // 检查摄像头是否打开失败
        cout << "错误：无法打开摄像头！" << endl;
        return -1; // 异常退出
    }

    Mat img;
    while(true){
        cap.read(img); // 读取一帧图像
        if (img.empty()) { // 检查是否读取到有效图像
            cout << "警告：未读取到图像帧！" << endl;
            waitKey(1000); // 等待1秒后重试
            continue;
        }
        imshow("Video", img); // 显示图像
        if (waitKey(1) == 27) { // 按ESC键（ASCII码27）退出循环
            break;
        }
    }
    return 0;
}