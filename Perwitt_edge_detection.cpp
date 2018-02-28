///Edge detection of an image using Perwitt operator

#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int a[3][3] = {-1, 0, 1,-1, 0, 1,-1, 0, 1, }; int b[3][3] = {-1, -1, -1, 0, 0, 0, 1, 1, 1},sum1 = 0, sum2=0, v=0, p=0,G[1300*1300];
int i, j, k, l;
Mat img = imread("img1.png",CV_LOAD_IMAGE_GRAYSCALE);
Mat binary(int G[], int v){
    Mat img1(img.rows, img.cols, CV_8UC1);
    int x = 0;
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
            if(G[x++] < v){
                img1.at<uchar>(i,j)= 0;
    
            }else{
                img1.at<uchar>(i,j)= 255;
            }
        }
    }return img1;
}


int main(){
    cout<<img.rows<< " "<<img.cols;
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
            for(k=-1; k<=1; k++){
                for(l=-1; l<=1; l++){
                    if(k+i>=0 && l+j<img.cols && k+i<img.rows && j +l>=0){
                        sum1+= a[k+1][l+1]*img.at<uchar>(i+k, j+l);
                        sum2+= b[k+1][l+1]*img.at<uchar>(i+k, j+l);
                    }
                }
            }
            G[p] = abs(sum1) +  abs(sum2);
            p++;
            sum1=0;
            sum2=0;
        }      
    }
    namedWindow("img1",WINDOW_NORMAL);
    createTrackbar("t","img1", &v, 255);
        while(1){
            imshow("img1", binary(G, v));
            Mat img2(img.rows, img.cols, CV_8UC1);
            img2 = binary(G, v);
            int q = 0;
            for(i=0; i<img.rows; i++){
                for(j=0; j<img.cols; j++){
                    for(k=-1; k<=1; k++){
                        for(l=-1; l<=1; l++){
                            if(img2.at<uchar>(i+k,j+l) == 0){
                                img2.at<uchar>(i,j) = 0;
                            }else {img2.at<uchar>(i,j) = 255;}
                        }
                    }
                }
            }
                
            for(i=0; i<img.rows; i++){
                for(j=0; j<img.cols; j++){
                    for(k=-1; k<=1; k++){
                        for(l=-1; l<=1; l++){
                            if(img2.at<uchar>(i+k,j+l)== 255){
                                img2.at<uchar>(i,j) = 255;
                            }else {img2.at<uchar>(i,j) = 0;}
                            }
                    }
                }
            }
            imshow("img1",img2);
            waitKey(100);
        }
}


