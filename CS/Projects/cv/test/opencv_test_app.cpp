#include <opencv2/opencv.hpp>
#include <iostream>

using std::cout;
using std::endl;

using namespace cv;

int main() {
    cout << "open cv testing in progress..." << endl;
    Mat A(2, 2, CV_8UC3, Scalar(0,0,255));
	cout << "A = " << endl << A << endl << endl;
    return 0;
}
