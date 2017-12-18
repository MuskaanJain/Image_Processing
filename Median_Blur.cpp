#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int i, j, k, l, p=0, a[100], b[100], c[100], x, y, t;
int  g=0, sum1 =0, sum2=0, sum3=0;
float  avg1, avg2, avg3;


int main(){

    
    Mat img =  imread("lena.jpg");   Mat img1(img.rows, img.cols, CV_8UC3, 255);
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){ p=0;
            for(k=-1; k<=1; k++){
                for(l=-1; l<=1; l++){
                    
                    if(k+i>=0 && k+i<img.rows && j+l<img.cols && j +l>=0){
                        
                        a[p] = img.at<Vec3b>(i+k,j+l)[0];
                        b[p] = img.at<Vec3b>(i+k,j+l)[1];
                        c[p] = img.at<Vec3b>(i+k,j+l)[2];
                        p++;
                    
                    }
                }
            }
            for(x=0 ; x<p; x++){
                for(y=0; y<p-1; y++){
                
                    if(a[y]>a[y+1]){
                    
                        t = a[y];
                        a[y]=a[y+1];
                        a[y+1]= t;
                    
                    
                    }
                
                }
            }
            
            for(x=0 ; x<p; x++){
                for(y=0; y<p-1; y++){
                    
                    if(b[y]>b[y+1]){
                        
                        t = b[y];
                        b[y]=b[y+1];
                        b[y+1]= t;
                        
                        
                    }
                    
                }
            }
            for(x=0 ; x<p; x++){
                for(y=0; y<p-1; y++){
                    
                    if(c[y]>c[y+1]){
                        
                        t = c[y];
                        c[y]=c[y+1];
                        c[y+1]= t;
                        
                        
                    }
                    
                }
            }

            img1.at<Vec3b>(i,j)[0] = a[p/2];
            img1.at<Vec3b>(i,j)[1] = b[p/2];
            img1.at<Vec3b>(i,j)[2] = c[p/2];
            
        }
    }
       Mat img2(img.rows, img.cols, CV_8UC3, 255);
    for(i=0; i<img.rows; i++){
        for(j=0; j<img.cols; j++){
            for(k=-1; k<=1; k++){
                for(l=-1; l<=1; l++){
                    
                    if(k+i>=0 && l+j<img.cols && k+i<img.rows && j +l>=0){
                        
                        sum1+=img.at<Vec3b>(i+k, j+l)[0];
                        sum2+=img.at<Vec3b>(i+k, j+l)[1];
                        sum3+=img.at<Vec3b>(i+k, j+l)[2];
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
    imshow("lena2",img2);
    

    imshow("lena",img);  imshow("lena1",img1);
    waitKey(0);
}

