#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;
Mat img = imread("paint.png",CV_LOAD_IMAGE_GRAYSCALE);
Mat img1(img.rows, img.cols, CV_8UC1,Scalar(0));
int c=1,t=0;

Mat translation(Mat img1,int t){
    Mat img2(img.rows, img.cols, CV_8UC1,Scalar(0));
    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            img2.at<uchar>(i,j+t)= img1.at<uchar>(i,j);
        }}return img2;
}

void dbs(int x, int y){
    
    img1.at<uchar>(x,y) = 255/c;
    
    for(int p=-1; p<=1; p++){
        for(int q=-1; q<=1; q++){
            if(p+x>=0 && q+y<img.cols && p+x<img.rows && y +q>=0){
                if(img.at<uchar>(x+p,y+q)!=255 && img1.at<uchar>(x+p,y+q)==0){
                    dbs(x+p,y+q);}
            }
        }
        
    }
}




int main(){
    int i,j;
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
            
            if(img.at<uchar>(i,j)!=255 && img1.at<uchar>(i,j)==0){
                dbs(i,j);
                c++;}
            
        }
        
        
    }
    
    
      namedWindow("m1",WINDOW_NORMAL);
    createTrackbar("k","m1",&t,img.cols);
    while(1){
        imshow("m1", translation(img1,t));
    waitKey(5);
        }
    imshow("m", img1);      
    
}


