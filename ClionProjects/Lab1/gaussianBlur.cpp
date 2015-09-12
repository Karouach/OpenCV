#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

/* Gaussian Blur : SUM(e = 1 + (1/n!)) ~= 2.8*/

using namespace cv;
using namespace std;


void example(Mat &image){
   namedWindow("Input", 0);
   namedWindow("Output", 0);
   imshow("Input", image);
   Mat out;
    GaussianBlur(image, out, Size(5, 5), 3, 3);
    GaussianBlur(out, out, Size(5, 5), 3,3);
    imshow("Output", out);
    waitKey(0);

}
void help(){
    cout << "Call ./Lab1 blob.jpg" << endl;

}



int main( int argc, char** argv ) {

    help();
    cv::Mat img = imread(argv[1],-1);
    if(img.empty()){
        std::cerr << "Cant Open" << argv[1] << std::endl;
        return -1;
    }
    example(img);


}




