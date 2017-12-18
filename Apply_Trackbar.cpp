#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int i, j, k,l  ;
Mat img = imread("lena.jpg");

void Mean(int pos, void* data){
    int sum1=0, sum2=0, sum3=0,avg1, avg2, avg3, g=0,v=pos;
    if(v%2 == 1){
        Mat* img = (Mat*)data;
    Mat img2(img->rows, img->cols, CV_8UC3, Scalar(255,255,255));
    for(i=0; i<img->rows; i++){
        for(j=0; j<img->cols; j++){
            for(k=-v; k<=v; k++){
                for(l=-v; l<=v; l++){
                    
                    if(k+i>=0 && l+j<img->cols && k+i<img->rows && j +l>=0){
                        
                        sum1+=img->at<Vec3b>(i+k, j+l)[0];
                        sum2+=img->at<Vec3b>(i+k, j+l)[1];
                        sum3+=img->at<Vec3b>(i+k, j+l)[2];
                        g++;
                    }
                    
                    
                    
                }
                
            }
            avg1= sum1/g;  avg2= sum2/g;   avg3= sum3/g;
            
            img2.at<Vec3b>(i, j)[0] = avg1;
            img2.at<Vec3b>(i, j)[1] = avg2;
            img2.at<Vec3b>(i, j)[2] = avg3;
            g=0;
            sum1=0;
            sum2=0;
            sum3=0;
            
        }
    }
        imshow("lena",img2);
        waitKey(0);}}



int main(){
    int v=0;
    
    namedWindow("lena", WINDOW_NORMAL);
    createTrackbar("t", "lena", &v, 5,Mean, (void*)&img);

    waitKey(0);



}

