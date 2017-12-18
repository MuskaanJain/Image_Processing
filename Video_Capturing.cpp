#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>


using namespace cv;
using namespace std;

int i, j;

int main(){

    VideoCapture VC(0);
    Mat frame;
     VC >> frame;
    
    

    
    while(1){
            VC >> frame;
        for(i=0;i<frame.rows;i++){
            for(j=0;j<frame.cols/2; j++){
                frame.at<Vec3b>(i,j)[0] = frame.at<Vec3b>(i,j)[0];
                frame.at<Vec3b>(i,j)[1] = frame.at<Vec3b>(i,j)[1];
                frame.at<Vec3b>(i,j)[2] = frame.at<Vec3b>(i,j)[2];
                
            }
        }
        for(i=0;i<frame.rows;i++){
            for(j=frame.cols/2;j<frame.cols; j++){
                frame.at<Vec3b>(i,j)[0] = frame.at<Vec3b>(i,frame.cols-j)[0];
                frame.at<Vec3b>(i,j)[1] = frame.at<Vec3b>(i,frame.cols-j)[1];
                frame.at<Vec3b>(i,j)[2] = frame.at<Vec3b>(i,frame.cols-j)[2];
                
            }
        }

        

        
        imshow("video",frame);
        waitKey(5);
    
    
    }
    




}

