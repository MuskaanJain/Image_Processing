#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int LT=0, HT=0;

int main(){
    Mat img = imread("lena.jpg");
    Mat img1(img.rows, img.cols,CV_8UC3,Scalar(255,255,255));
    namedWindow("lena",WINDOW_NORMAL);
    createTrackbar("t","lena",&LT, 255);
    createTrackbar("t1","lena",&HT, 255);
    while(1){
    
        Canny(img, img1, LT, HT);
        imshow("lena",img1);
        waitKey(5);

    
    }
    
    
       
}

