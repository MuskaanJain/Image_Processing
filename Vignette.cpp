#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int a, b,   i, j, r;
float r1, d, f;

int main(){
    Mat img = imread("lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    a = img.rows/2; b= img.cols/2;
    
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
            r1 = sqrt((a-i)*(a-i) + (b-j)*(b-j));
            d = sqrt((a*a + b*b));
            
           
            r = img.at<uchar>(i,j);
            img.at<uchar>(i,j)= r*(1-(r1/d));
        
        }
    }
    imshow("lena1", img);  
    waitKey(0);
}

