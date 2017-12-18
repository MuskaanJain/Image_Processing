#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

int i, j, k, l, c=0, sum1 =0, sum2=0, sum3=0;
float  avg1, avg2, avg3;
using namespace cv;
using namespace std;
int main(){

    Mat img =  imread("lena.jpg");   Mat img1(img.rows, img.cols, CV_8UC3, 255);
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
            for(k=-1; k<=1; k++){
                for(l=-1; l<=1; l++){
                
                    if(k+i>=0 && l+j<img.cols && k+i<img.rows && j +l>=0){
                    
                        sum1+=img.at<Vec3b>(i+k, j+l)[0];
                        sum2+=img.at<Vec3b>(i+k, j+l)[1];
                        sum3+=img.at<Vec3b>(i+k, j+l)[2];
                        c++;
                    }
                
                
                
                }
            
            }
            avg1= sum1/c;  avg2= sum2/c;   avg3= sum3/c;
            
            img1.at<Vec3b>(i, j)[0] = avg1;
            img1.at<Vec3b>(i, j)[1] = avg2;
            img1.at<Vec3b>(i, j)[2] = avg3;
            c=0;
            sum1=0;
            sum2=0;
            sum3=0;
            
        }
    }
    imshow("lena2",img1); imshow("lena", img);
    waitKey(0);
}

