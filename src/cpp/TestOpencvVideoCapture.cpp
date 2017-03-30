/*
 * TestOpencvVideoCapture.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: xushen
 */

#include "/home/xushen/workspace/Tests/src/header/TestOpencvVideoCapture.h"
#include <string>
#include <iomanip>
using namespace cv;
using namespace std;

TestOpencvVideoCapture::TestOpencvVideoCapture() {
	// TODO Auto-generated constructor stub

}

void TestOpencvVideoCapture::RunTests() const {

    VideoCapture captrue(0);

    VideoWriter write;

    string outFloder = "/home/xushen/Desktop/imcap/";
    string outFlie = outFloder + "video.avi";

    int w = static_cast<int>(captrue.get(CV_CAP_PROP_FRAME_WIDTH));
    int h = static_cast<int>(captrue.get(CV_CAP_PROP_FRAME_HEIGHT));
    Size S(w, h);

    double r = captrue.get(CV_CAP_PROP_FPS);

    write.open(outFlie.c_str(), CV_FOURCC_DEFAULT, r, S, true);

    if (!captrue.isOpened())
    {
    	cout << "Error: video is not open." << endl;
        return;
    }
    bool stop = false;
    bool start = false;
    bool pause = false;
    char key;
    Mat frame;

    int n = 0;
    while (!stop)
    {
        if (!captrue.read(frame)){
        	cout << "Data read error." << endl;
        	break;
        }
        imshow("Video", frame);

        key = waitKey(10);
        switch(key)
        {
			case 's':
			{
				cout << "Start capture!" << endl;
				start = true;
				pause = false;
				break;
			}
			case 'q':
			{
				cout << "Quit" << endl;
				stop = true;
				start = false;
				pause = false;
				break;
			}
			case 'p':
			{
				cout << "Current pause on." << endl;
				pause = true;
				start = false;
				break;
			}
			default:
			{
				if(key != -1)
					cout << "Usage: 's'-> start; 'q'-> quit; 'p'-> pause." << endl;
			}
        }

        if(start)
        {
			stringstream s;
			s << setfill('0') << setw(6) << n++ << endl;
			imwrite(outFloder + s.str() + ".jpg", frame);
			write.write(frame);
        }

        if(stop)
        {
        	n = 0;
        	break;
        }
    }

    captrue.release();
    write.release();
	cvDestroyWindow("Video");
	return;
}

TestOpencvVideoCapture::~TestOpencvVideoCapture() {
	// TODO Auto-generated destructor stub
}

