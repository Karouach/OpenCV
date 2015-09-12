#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int g_slider_position = 0;
int run = 1, dontset = 0;
VideoCapture cap;

void onTrackbarSlide(int pos, void *){
    cap.set(CV_CAP_PROP_POS_FRAMES, pos);
    if(!dontset)
        run = 1;
        dontset = 0;
}
void help(){
    cout << "Call ./Lab1 Blob.avi" << endl;

}



int main( int argc, char** argv ) {
    namedWindow("Blob", 0);

    if(argc >1 ) cap.open(string(argv[1]));
    else{cap.open(0); std::cerr << "Call ./Lab1 Blob.avi " << std::endl; return -1;}
    help();
    int frames = (int) cap.get(CV_CAP_PROP_FRAME_COUNT);
    int tmpw = (int) cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int tmph = (int) cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cout << "Video has" << frames << "frames" << tmpw << "tmpw" << tmph << "tmph"<< std::endl;
    createTrackbar("Position", "Blob", &g_slider_position,frames, onTrackbarSlide);

    Mat frame;
    frames = 0;
    int single_step = 0;
    while (1){
        if(run !=0 ){
            cap >> frame;
            if(!frame.data)break;
            imshow("Blob", frame);
            if(waitKey(30) >= 0)break;
            frames = (int)cap.get(CV_CAP_PROP_POS_FRAMES);
            dontset = 1;
            setTrackbarPos("Position", "Blob", frames);
            run-=1;

        }



    char c = (char)waitKey(10);
    if(c == 'h') help();
    if(c == 's'){
        run = 1;
        cout << "Single step, run "<< run<< endl;
    }
    if(c == 'r'){
        run = -1;
        cout << "Run mode, run ="<< run << endl;
    }
    if(c == 27)
        break;

    }
    return 0;


}




