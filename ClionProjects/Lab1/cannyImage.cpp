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
    Mat img_rgb = imread(argv[1]);
    help();
    if(img_rgb.empty()){
        std::cerr << "Cant Open" << argv[1] << std::endl;
        return -1;

    }
    Mat img_gry, img_cny;
    cvtColor(img_rgb, img_gry, CV_BGR2GRAY);
    namedWindow("Original", 0);
    imshow("Original", img_rgb);
    namedWindow("Gray", 0);
    namedWindow("Canny", 0);
    imshow("Gray", img_gry);
    Canny(img_gry, img_cny, 10, 100, 3, true);
    imshow("Canny", img_cny);
    waitKey(0);


}




