#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



int main( int argc, char** argv ) {
    cvNamedWindow("Input", 0);
    IplImage *input = cvLoadImage(argv[1]);
    cvShowImage("Input", input);

    cvNamedWindow("Output", 0);
    IplImage *output = cvCreateImage(cvGetSize(input), IPL_DEPTH_8U, 3);
    cvSmooth(input, output, CV_GAUSSIAN_5x5, 3, 3);
    cvShowImage("Output", output);

    cvWaitKey(0);
    cvReleaseImage(&output);
    cvReleaseImage(&input);
    cvDestroyWindow("Input");
    cvDestroyWindow("Output");

    return 0;

            }




