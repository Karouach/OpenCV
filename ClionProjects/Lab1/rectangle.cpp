#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;



int main( int argc, char** argv ) {
    IplImage* src;
    cvNamedWindow("Blob-Original", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Blob-Post", CV_WINDOW_AUTOSIZE);
    if(argc == 7 && ((src = cvLoadImage(argv[1], 1))!=0)){
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);
        int width = atoi(argv[4]);
        int height = atoi(argv[5]);
        int add = atoi(argv[6]);
        cvShowImage("Blob-Post", src);
        cvSetImageROI(src, cvRect(x, y, width, height));
        cvAddS(src, cvScalar(add), src);
        cvResetImageROI(src);
        cvShowImage("Blob-Post", src);
        cvWaitKey();
    }
    cvReleaseImage(&src);
    cvDestroyWindow("Blob-Original");
    cvDestroyWindow("Blob-Post");
    return 0;





}




