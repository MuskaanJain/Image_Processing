#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int i, j, k, l, a, b, c;

int main(){

    Mat img = imread("lena.jpg");
    Mat img1(img.rows*2, img.cols*2, CV_8UC3, 255);
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
        
            a = img.at<Vec3b>(i, j)[2];
            b = img.at<Vec3b>(i, j)[1];
            c = img.at<Vec3b>(i, j)[0];
            
            for(l=0+(2*i); l<2+(2*i); l++){
                for(k= 0+(2*j); k<2 +(2*j); k++){
                    img1.at<Vec3b>(l, k)[2] = a;
                    img1.at<Vec3b>(l, k)[1] = b;
                    img1.at<Vec3b>(l, k)[0] = c;
                }
            
            
            }
            
        }
    
    
    }
    
    
    imshow("lena", img1);
    waitKey(0);
    
}

