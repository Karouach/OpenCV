#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

void help(){
    cout << "Call ./Lab1 blob.jpg" << endl;

}

int NOWRITE = 1; //Write only if we get output file.

int main( int argc, char** argv ) {
    if(argc > 2)
        NOWRITE = 0;
    cout << "Nowrite" << NOWRITE << endl;
    namedWindow("Blob", CV_WINDOW_AUTOSIZE);
    namedWindow("Blob_Log_Polar", CV_WINDOW_AUTOSIZE);
    Mat bgr_frame;
    VideoCapture capture;
    if(argc < 2 || !capture.open(argv[1])){
        help();
        cout << "FAIL TO OPEN" << argv[1] << endl;
        return -1;

    }
    double fps = capture.get(CV_CAP_PROP_FPS);
    cout << "fps " << fps<<endl;
    Size size((int)capture.get(CV_CAP_PROP_FRAME_WIDTH), (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));
    cout << "Fram w, h =  (" <<size.width << ", " << size.height << ")" << endl;
    VideoWriter writer;
    if(!NOWRITE){
        writer.open(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
    }
    Mat logpolar_frame(size, CV_8UC3);
    Mat gray_frame(size, CV_8UC1);

    for(;;){
        capture  >> bgr_frame;
        if(bgr_frame.empty())break;
        imshow("Blob", bgr_frame);
        cvtColor(bgr_frame, gray_frame, CV_BGR2GRAY);
        IplImage lp = logpolar_frame;
        IplImage bgrf = bgr_frame;
        cvLogPolar(&bgrf, &lp, cvPoint2D32f(bgr_frame.cols/2, bgr_frame.rows/2), 40, CV_WARP_FILL_OUTLIERS);
        imshow("Log Polar", logpolar_frame);
        if(!NOWRITE)
            writer << logpolar_frame;
        char c = waitKey(10);
        if(c== 27) break;
    }
    capture.release();





}




