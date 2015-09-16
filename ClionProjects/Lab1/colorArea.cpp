#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

void saturate_sv(IplImage* img){
    for (int y = 0; y <img->height; y++){
        uchar * ptr = (uchar*)(img->imageData + y * img->widthStep);
        for(int x = 0; x<img->width; x++){
            ptr[3*x+1] = 0;
            ptr[3*x+1] =0;
        }
    }
}

int main( int argc, char** argv ) {
    IplImage* img = cvLoadImage(argv[1]);
    cvNamedWindow("Blob-Original", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Blob-Saturated", CV_WINDOW_AUTOSIZE);
    cvShowImage("Blob-Original", img);
    saturate_sv(img);
    cvShowImage("Blob", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("Blob");




}




