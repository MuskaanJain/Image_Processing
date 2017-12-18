#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int i,j,x;
Mat morph(Mat img1,Mat img2,int x)
{
    Mat img3(600, 600, CV_8UC3, Scalar(255,255,255));
    for(i=0; i<600; i++){
        for(j=0; j<600; j++){
            img3.at<Vec3b>(i,j)[0] = (x/100.0)*img1.at<Vec3b>(i,j)[0]  + ((100-x)/100.0)*img2.at<Vec3b>(i,j)[0];
            img3.at<Vec3b>(i,j)[1] = (x/100.0)*img1.at<Vec3b>(i,j)[1]  + ((100-x)/100.0)*img2.at<Vec3b>(i,j)[1];
            img3.at<Vec3b>(i,j)[2] = (x/100.0)*img1.at<Vec3b>(i,j)[2]  + ((100-x)/100.0)*img2.at<Vec3b>(i,j)[2];
        }
    }
    return img3;
}

int main(){

    Mat img1= imread("6.png");
 Mat img2= imread("61.png");
    
    namedWindow("600",WINDOW_NORMAL);
    createTrackbar("t","600",&x,100);
    
    Mat img3(600, 600, CV_8UC3, Scalar(255,255,255));
    
    while(1){

                imshow("600",morph(img1,img2,x));
                waitKey(5);
        }


}

