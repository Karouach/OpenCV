#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

/* Gaussian Blur : SUM(e = 1 + (1/n!)) ~= 2.8*/

using namespace cv;
using namespace std;

void help(){
    cout << "Call ./Lab1 blob.jpg" << endl;

}

int main( int argc, char** argv ) {
    namedWindow("Blob", CV_WINDOW_AUTOSIZE);
    help();
    VideoCapture cap;
    if(argc == 1){
        cap.open(0);
    }else{
        cap.open(argv[1]);
    }
    if(!cap.isOpened()){
        cerr << "Cant Open" <<endl;
        return -1;
    }
    Mat frame;
    while(1){
        cap >> frame;
        if(!frame.data)break;
        cvtColor(frame, frame, CV_BGR2GRAY);
        Canny(frame, frame, 10, 100, 3, true);
        imshow("Blob", frame);
        char c = waitKey(10);
        if(c == 27)break;
    }



}




