#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int i=0, a, t, j, img2;

Mat binary(Mat img,int t){

    Mat img2(img.rows, img.cols, CV_8UC1);
    
    
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
        
            a = img.at<uchar>(i, j);
            if(a<t){
                img2.at<uchar>(i, j) = 0;
            }else{
                img2.at<uchar>(i, j)=255;
            }
            
            
            
        }
    
    }
    
    return img2;
    
}

int main(){
    
    
    Mat img = imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    namedWindow("lena", WINDOW_NORMAL);
    createTrackbar("track", "lena", &t, 255);
    imshow("lena",img);
    
    while(1){
    
        
        imshow("lena2", binary(img,t));
    
        waitKey(5);
    
    }
    
    
    
    waitKey(0);
    
}

