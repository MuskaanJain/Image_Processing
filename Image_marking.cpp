#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;
Mat img = imread("paint.png",CV_LOAD_IMAGE_GRAYSCALE);
Mat img1(img.rows, img.cols, CV_8UC1,Scalar(0));
int c=1, k=0;

Mat trans(Mat img2,int k){
    Mat img3(img.rows, img.cols, CV_8UC1,Scalar(0));
    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            img3.at<uchar>(i,j) = img2.at<uchar>(i,j);
           }}
    
         for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            if(img1.at<uchar>(i,j)==255){
    img3.at<uchar>(i,j+k) = img1.at<uchar>(i,j);
            }}}
    return img3;
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
        
    }}




int main(){
    int i, j;
    imshow("m", img1);
        for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
            
            if(img.at<uchar>(i,j)!=255 && img1.at<uchar>(i,j)==0){
                dbs(i,j);
                                   c++;}
            
        }}
    
    Mat img2(img.rows, img.cols, CV_8UC1,Scalar(0));
    for(i=0; i<img.rows; i++){
            for(j=0; j<img.cols; j++){
                if((img1.at<uchar>(i,j)== 255/2 || img1.at<uchar>(i,j)== 255/3) && img2.at<uchar>(i,j)!=255 ){
                    img2.at<uchar>(i,j) = img1.at<uchar>(i,j);
                }}}
    
                         namedWindow("m1",WINDOW_NORMAL);
                         createTrackbar("t","m1",&k,img1.cols);
                         while(1){
                             
                             imshow("m1", trans(img2,k));
                             waitKey(5);
                             
                
            }
   
    
}

