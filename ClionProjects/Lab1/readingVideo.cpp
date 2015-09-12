#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main( int argc, char** argv ) {
    namedWindow("Blob", 0);
    VideoCapture cap;
    if(argc >1 ) cap.open(argv[1]);
    else{cap.open(0); std::cerr << "Call ./Lab1 Blob.avi " << std::endl; return -1;}
    Mat frame;
    while (1){
        cap >> frame;
        if(!frame.data)break;
        imshow("Blob", frame);
        if(waitKey(30) >= 0)break;
    }
    return 0;


}




