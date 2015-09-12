#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



int main( int argc, char** argv ) {
    cvNamedWindow("Blob5", 0);
    CvSize size = cvSize(200, 200); //pixels
    IplImage* frame = cvCreateImage(size, IPL_DEPTH_8U, 3); //In memory no value in hard drive
    cvRectangle(frame,cvPoint(5, 10), cvPoint(20, 30), cvScalar(255,255,255));
    cvCircle(frame, cvPoint(30, 60), 10, cvScalar(255, 255, 255), 2);
    cvLine(frame, cvPoint(30, 60), cvPoint(50,60),cvScalar(0, 255, 0));
    cvShowImage("Blob5", frame);
    cvWaitKey(0);
    cvReleaseImage(&frame);
    cvDestroyWindow("Blob5");
    return 0;
}




