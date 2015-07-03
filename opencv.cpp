#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include <opencv/highgui.h>

using namespace cv;
using namespace std;


int main( int argc, char** argv ) {

    IplImage* img = cvLoadImage("blob1.jpg");
    cvNamedWindow("Example1.jpg", CV_WINDOW_AUTOSIZE);
    cvShowImage("Example1.jpg", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("Example1.jpg");
}