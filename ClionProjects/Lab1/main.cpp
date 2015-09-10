#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main( int argc, char** argv )
{
    cvNamedWindow("blob1", 0);
    CvCapture* capture = cvCreateFileCapture(argv[1]);
    IplImage* frame;
    while (1){
        frame = cvQueryFrame(capture);
        if(! frame)break;
        cvShowImage("blob1", frame);
        char c = cvWaitKey(33);
        if(c == 27) break;


    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("blob1");
    return 0;

}