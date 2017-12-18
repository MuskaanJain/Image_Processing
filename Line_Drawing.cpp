#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;


int main(){
    Mat img(500, 500, CV_8UC1,Scalar(0));
    for(int i=0; i<500; i++){
        for(int j=0; j<500; j++){
            
            float s = -3.14/6;
            if(   i*cos(s) + j*sin(s) >200  && i*cos(s) + j*sin(s) <200.1  ){
                img.at<uchar>(i,j) = 255;
            } }}

    imshow("img",img);
    waitKey(0);
}

