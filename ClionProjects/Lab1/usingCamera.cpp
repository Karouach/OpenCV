#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



int main( int argc, char** argv ) {
    cvNamedWindow("Blob", 0);
    CvCapture* capture = NULL;

    if(argc == 1){
        capture= cvCreateCameraCapture(0); //own Camera

    }else{
        capture= cvCreateFileCapture(argv[1]);
    }
    IplImage* frame;
    while(1){
        frame = cvQueryFrame(capture);
        if(!frame)break;
        cvShowImage("Blob", frame);
        char c = cvWaitKey(33);
        if(c == 27) break;

    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("Blob");
    return 0;
}




