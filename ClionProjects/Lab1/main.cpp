#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv/highgui.h>


int main( int argc, char** argv )
{
    IplImage * img = cvLoadImage(argv[1]);
    cvNamedWindow("blob", CV_WINDOW_AUTOSIZE);
    cvShowImage("blob", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("blob");
    return 0;
}