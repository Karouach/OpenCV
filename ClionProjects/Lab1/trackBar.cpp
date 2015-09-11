#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


    int slider_position = 0;
    CvCapture* cvCapture = NULL;
    void onTrackBarSlide(int pos) {
        cvSetCaptureProperty(cvCapture, CV_CAP_PROP_POS_FRAMES, pos);
    }

int main( int argc, char** argv ) {
            cvNamedWindow("Blob", 0);
            cvCapture=cvCreateFileCapture(argv[1]);
            int frames=cvGetCaptureProperty(cvCapture,CV_CAP_PROP_FRAME_COUNT);
            if(frames!=0){
                cvCreateTrackbar("Position", "Blob", &slider_position, frames, onTrackBarSlide);
            }
            IplImage * frameImage;

            while (1){
            frameImage = cvQueryFrame(cvCapture);
                if(!frameImage)break;
                cvShowImage("Blob", frameImage);
                char c = cvWaitKey(33);
                if(c == 27 ) break;
            }
    cvReleaseCapture(&cvCapture);
    cvDestroyWindow("Blob");
    return 0;

}
