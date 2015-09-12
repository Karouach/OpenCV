#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;


int main( int argc, char** argv ) {
    cv::Mat img = imread(argv[1], -1);
    if(img.empty()){
        std::cerr << "Couldnt open Image" << argv[1] << std::endl;
        std::cerr << "Call ./Lab1 Blob.jpg"<< std::endl;
        return -1;
    }
    cv::namedWindow("Blob", CV_WINDOW_AUTOSIZE);
    cv::imshow("Blob", img);
    cv::waitKey(0);
    cv::destroyWindow("Blob");

}




