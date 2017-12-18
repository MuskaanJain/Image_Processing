#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;




int s=0, k=0;

Mat rotation(Mat img, int s){
    int a = img.rows/2, b = img.cols/2 ,x1,y1;
    Mat img1(sqrt(img.rows*img.rows +img.cols*img.cols), sqrt(img.rows*img.rows +img.cols*img.cols), CV_8UC3, Scalar(255,255,255));
    for(int x=0; x<img.rows; x++){
        for(int y=0; y<img.cols; y++){
            x1 = (x-a)*cos(s) + (y-b)*sin(s) + img1.rows/2;
            y1 = (x-a)*sin(s) + (y-b)*cos(s) + img1.cols/2;
            img1.at<Vec3b>(x1,y1)[0] = img.at<Vec3b>(x,y)[0];
            img1.at<Vec3b>(x1,y1)[1] = img.at<Vec3b>(x,y)[1];
            img1.at<Vec3b>(x1,y1)[2] = img.at<Vec3b>(x,y)[2];
        }
    
    }
    return img1;

}



int main(){
    Mat img = imread("lena.jpg");
    namedWindow("lena",WINDOW_NORMAL);
    createTrackbar("t","lena",&k, 360);
   
    while(1){
        s = k*(3.14/180);

        imshow("lena",rotation(img,s));
        waitKey(5);
    }


}

