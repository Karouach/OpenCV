#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



int main( int argc, char** argv ) {
    cvNamedWindow("Input", 0);
    IplImage *input = cvLoadImage(argv[1]);
    cvShowImage("Input", input);

    cvNamedWindow("Output", 0);
    IplImage *output = cvCreateImage(cvSize(input->width/2, input->height/2), input->depth, input->nChannels);
    assert(input->width%2 == 0 && input->height%2==0);
    cvPyrDown(input, output);
    cvShowImage("Output", output);

    cvWaitKey(0);
    cvReleaseImage(&output);
    cvReleaseImage(&input);
    cvDestroyWindow("Input");
    cvDestroyWindow("Output");

    return 0;

            }




