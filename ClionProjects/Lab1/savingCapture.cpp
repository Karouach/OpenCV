#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



int main( int argc, char** argv ) {
    cvNamedWindow("Blob4", 0);
    CvCapture* capture = NULL;
    capture= cvCreateFileCapture(argv[1]);

    IplImage* frame;
    CvSize size = cvSize((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
                         (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));

    int fps = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
    fps = 30;
        IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);
        CvVideoWriter* writer = cvCreateVideoWriter(argv[2], CV_FOURCC('I', 'Y', 'U', 'V'),fps, size );
        int count = 1;
    while((frame = cvQueryFrame(capture))!= NULL){
        cvLogPolar(frame, logpolar_frame, cvPoint2D32f(frame->width/4, frame->height/4), count, CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);

        cvShowImage("Blob4", logpolar_frame);
        cvWriteFrame(writer, logpolar_frame);
        count++;
        char c = cvWaitKey(33);
        if(c == 27) break;

    }
    cvReleaseVideoWriter(&writer);
    cvReleaseCapture(&capture);
    cvReleaseImage(&frame);
    cvReleaseImage(&logpolar_frame);
    cvDestroyWindow("Blob4");
    return 0;
}




