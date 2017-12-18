#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int main(){

    Mat img =  imread("s.png",CV_LOAD_IMAGE_COLOR);
imshow("s1",img);
    Mat img1(img.rows, img.cols, CV_8UC3, Scalar(0,0,0));

    int i,j,a,b1,c,r =0, b =0, g=0, t =0;
    namedWindow("s2",WINDOW_NORMAL);
    createTrackbar("R","s2",&r, 255);
    createTrackbar("G","s2",&g, 255);
    createTrackbar("B","s2",&b, 255);
    createTrackbar("T","s2",&t, 255);
    
    while(1){
    
        for(i=0;i<img.rows;i++){
            for(j=0;j<img.cols;j++){
            
                a=img.at<Vec3b>(i,j)[0];
                b1=img.at<Vec3b>(i,j)[1];
                c=img.at<Vec3b>(i,j)[2];
                if((a>=b-t && a<=b+t) && (b1>=g-t && b1<=g+t) && (c>=r-t && c<=r+t)){
                
                    img1.at<Vec3b>(i,j)[0] = a;
                    img1.at<Vec3b>(i,j)[1] = b1;
                    img1.at<Vec3b>(i,j)[2] = c;
                }else{
                
                    img1.at<Vec3b>(i,j)[0] = 0;
                    img1.at<Vec3b>(i,j)[1] = 0;
                    img1.at<Vec3b>(i,j)[2] = 0;
                }
                }
            
            }
        
        
    
        imshow("s2",img1);
        waitKey(5);

    
    
    }
    
    waitKey(0);
    }

