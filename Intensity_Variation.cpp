#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int i, j ,a, b ,c,t , p,q;


void createimage(){

Mat lena = imread("lena.jpg");

    for(i=0; i<lena.rows; i++){
        for(j=0; j<lena.cols; j++){
        
            a = lena.at<Vec3b>(i,j)[0];
            b = lena.at<Vec3b>(i,j)[1];
            c = lena.at<Vec3b>(i,j)[2];
         
            t = (a + b + c)/3;
            lena.at<Vec3b>(i,j)[0] = t;
            lena.at<Vec3b>(i,j)[1] = t;
            lena.at<Vec3b>(i,j)[2] = t;
            
        }
         
    
    }

    Mat img2 = imread("lena.jpg");
    
    Mat img3 = imread("lena.jpg");
    
    for(i=0; i<lena.rows; i++){
        for(j=0; j<lena.cols; j++){
            
            a = img3.at<Vec3b>(i,j)[0];
            b = img3.at<Vec3b>(i,j)[1];
            c = img3.at<Vec3b>(i,j)[2];
       
            p = min(min(a,b) , min(b,c));
            q = max(max(a, b), max(b ,c));
            
            t = q - p ;
            img3.at<Vec3b>(i,j)[0] = t;
        img3.at<Vec3b>(i,j)[1] = t;
            img3.at<Vec3b>(i,j)[2] = t;
        
        }
    
    }
    
    
    
    Mat img4 = imread("lena.jpg");
    
    for(i=0; i<lena.rows; i++){
        for(j=0; j<lena.cols; j++){
            
            a = img4.at<Vec3b>(i,j)[0];
            b = img4.at<Vec3b>(i,j)[1];
            c = img4.at<Vec3b>(i,j)[2];
            
            p = min(min(a,b) , min(b,c));
            q = max(max(a, b), max(b ,c));
            
            t = (q + p )/2;
            img4.at<Vec3b>(i,j)[0] = t;
            img4.at<Vec3b>(i,j)[1] = t;
            img4.at<Vec3b>(i,j)[2] = t;
            
        }
        
    }
    
    Mat img5 = imread("lena.jpg");
    
    for(i=0; i<lena.rows; i++){
        for(j=0; j<lena.cols; j++){
            
            a = img5.at<Vec3b>(i,j)[0];
            b = img5.at<Vec3b>(i,j)[1];
            c = img5.at<Vec3b>(i,j)[2];
            
            
            t = .11*a + .59*b + .30*c;
            img5.at<Vec3b>(i,j)[0] = t;
            img5.at<Vec3b>(i,j)[1] = t;
            img5.at<Vec3b>(i,j)[2] = t;
            
        }
        
    }

       imshow("img4", img4);
        imshow("img3", img3);
        imshow("lena", lena  );
    imshow("img2", img2);
}



int main(){

   
    
    createimage();
    
    waitKey(0);
    return 0;






}

