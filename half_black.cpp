#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

void displayimage(Mat image,String windowname)
{
    imshow(windowname, image);
}



void createimagesampe()
{
    
    Mat img = imread("img.jpg");
    
    
    
    for(int i=0; i<img.rows / 2; i++){
        for(int j=0; j<img.cols; j++){
            
            img.at<Vec3b>(i, j)[2] = 0;
            img.at<Vec3b>(i, j)[1] = 0;
            img.at<Vec3b>(i, j)[0] = 0;
        
        }
    
    
    };
        displayimage(img, "random");
}

int main()
{
    createimagesampe();
    waitKey(0);
    return 0;
}


#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

void displayimage(Mat image,String windowname)
{
    imshow(windowname, image);
}



void createimagesampe()
{
    
    Mat img = imread("img.jpg");
    
    
    
    for(int i=0; i<img.rows / 2; i++){
        for(int j=0; j<img.cols; j++){
            
            img.at<Vec3b>(i, j)[2] = 0;
            img.at<Vec3b>(i, j)[1] = 0;
            img.at<Vec3b>(i, j)[0] = 0;
        
        }
    
    
    };
        displayimage(img, "random");
}

int main()
{
    createimagesampe();
    waitKey(0);
    return 0;
}




