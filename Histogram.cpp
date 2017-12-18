#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;


int i, j, a[256], l=0, t;

int main(){
    Mat  img= imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    
    
    for(i=0; i<256; i++){
        a[i] = 0;
    }
    for(i=0; i<img.rows; i++){
        
        for(j=0; j<img.cols; j++){
            
            t = img.at<uchar>(i, j);
            a[t]++;
        }
    }



    for(i=0; i<256; i++){
    
        l = max(l,a[i]);
   
    }
    Mat img1(l , 255, CV_8UC3, 255 );
    
    for(i=0; i<img1.rows; i++){
        for(j=0; j<img1.cols; j++){
            img1.at<Vec3b>(i, j)[2] = 255;
            img1.at<Vec3b>(i, j)[1] = 255;
            img1.at<Vec3b>(i, j)[0] = 255;
        
        }
    
    }
    
    for(i=0; i<img1.cols; i++){
    
        for(j=0; j<a[i] ; j++){
        
            img1.at<Vec3b>(j,i)[2] = 0;
            img1.at<Vec3b>(j,i)[1] = 0;
            img1.at<Vec3b>(j,i)[0] = 0;
        }
    
    }
    
    
    imshow("histogram", img1);
    waitKey(0);
    return 0;
    
    
}


