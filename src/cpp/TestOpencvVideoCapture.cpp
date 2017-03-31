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

void CaptureOneCamera()
{
    VideoCapture captrue(1);

    //VideoWriter write;

    string outFloder = "/home/xushen/Desktop/imcap/single/";
    string outFlie = outFloder + "video.avi";

    int w = static_cast<int>(captrue.get(CV_CAP_PROP_FRAME_WIDTH));
    int h = static_cast<int>(captrue.get(CV_CAP_PROP_FRAME_HEIGHT));
    cout << "Image size: " << w << " , " << h << endl;
    Size S(w, h);

    double r = captrue.get(CV_CAP_PROP_FPS);

    //write.open(outFlie.c_str(), CV_FOURCC_DEFAULT, r, S, true);

    if (!captrue.isOpened())
    {
    	cout << "Error: video is not open." << endl;
        return;
    }
    bool stop = false;
    bool start = false;
    bool capflag = false;
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

        key = waitKey(50);
        switch(key)
        {
			case 's':
			{
				cout << "Start capture!" << endl;
				start = true;
				capflag = false;
				break;
			}
			case 'q':
			{
				cout << "Quit" << endl;
				stop = true;
				start = false;
				capflag = false;
				break;
			}
			case 'p':
			{
				cout << "Current pause on." << endl;
				capflag = false;
				start = false;
				break;
			}
			case 'c':
			{
				cout << "Capture one frame." << endl;
				capflag = true;
				start = false;
				break;
			}
			default:
			{
				if(key != -1)
					cout << "Usage: 's'-> start; 'q'-> quit; 'p'-> pause." << endl;
			}
        }

        if(capflag)
        {
			stringstream s;
			s << setfill('0') << setw(6) << n++ << endl;
			imwrite(outFloder + s.str().substr(0,6)  + ".jpg", frame);
			capflag = false;
        }

        if(start)
        {
			stringstream s;
			s << setfill('0') << setw(6) << n++ << endl;
			imwrite(outFloder + s.str().substr(0,6) + ".jpg", frame);
			//write.write(frame);
        }

        if(stop)
        {
        	n = 0;
        	break;
        }
    }

    captrue.release();
    //write.release();
	cvDestroyAllWindows();
	return;
}


void CaptureTwoCameras()
{

    VideoCapture captrue1(1);
    VideoCapture captrue2(2);

    //VideoWriter write1;
    //VideoWriter write2;

    string outFloder1 = "/home/xushen/Desktop/imcap/image_0/";
    string outFloder2 = "/home/xushen/Desktop/imcap/image_1/";
    string outFlie1 = outFloder1 + "video.avi";
    string outFlie2 = outFloder2 + "video.avi";

    int w = static_cast<int>(captrue1.get(CV_CAP_PROP_FRAME_WIDTH));
    int h = static_cast<int>(captrue1.get(CV_CAP_PROP_FRAME_HEIGHT));
    Size S(w, h);

    double r = captrue1.get(CV_CAP_PROP_FPS);

    //write1.open(outFlie1.c_str(), CV_FOURCC_DEFAULT, r, S, true);
    //write2.open(outFlie2.c_str(), CV_FOURCC_DEFAULT, r, S, true);

    if ((!captrue1.isOpened()) || (!captrue2.isOpened()))
    {
    	cout << "Error: video is not open." << endl;
        return;
    }
    bool stop = false;
    bool start = false;
    bool capflag = false;
    char key;
    Mat frame1, frame2;

    int n = 0;
    while (!stop)
    {
        if ((!captrue1.read(frame1)) || (!captrue2.read(frame2))){
        	cout << "Data read error." << endl;
        	break;
        }
        imshow("Video1", frame1);
        imshow("Video2", frame2);

        key = waitKey(10);
        switch(key)
        {
			case 's':
			{
				cout << "Start capture!" << endl;
				start = true;
				capflag = false;
				break;
			}
			case 'q':
			{
				cout << "Quit" << endl;
				stop = true;
				start = false;
				capflag = false;
				break;
			}
			case 'p':
			{
				cout << "Current pause on." << endl;
				capflag = false;
				start = false;
				break;
			}
			case 'c':
			{
				cout << "Capture one frame." << endl;
				capflag = true;
				start = false;
				break;
			}
			default:
			{
				if(key != -1)
					cout << "Usage: 's'-> start; 'q'-> quit; 'p'-> capture." << endl;
			}
        }

        if(capflag)
        {
			stringstream s;
			s << setfill('0') << setw(6) << n++ << endl;
			imwrite(outFloder1 + s.str().substr(0,6) + ".jpg", frame1);
			imwrite(outFloder2 + s.str().substr(0,6) + ".jpg", frame2);
			capflag = false;
        }

        if(start)
        {
			stringstream s;
			s << setfill('0') << setw(6) << n++ << endl;
			imwrite(outFloder1 + s.str().substr(0,6) + ".jpg", frame1);
			imwrite(outFloder2 + s.str().substr(0,6) + ".jpg", frame2);
			//write1.write(frame1);
			//write2.write(frame2);
        }

        if(stop)
        {
        	n = 0;
        	break;
        }
    }

    captrue1.release();
    captrue2.release();
    //write1.release();
    //write2.release();
	cvDestroyAllWindows();
	return;
}

void TestOpencvVideoCapture::RunTests() const {
	int n = 1;
	if(n == 1)
	{
		cout << "One camera is set. Default is one camera" << endl;
		CaptureOneCamera();
	}
	else if(n == 2)
	{
		cout << "Tow cameras are set." << endl;
		CaptureTwoCameras();
	}
	else{
		cout << "Only one or two carmeras are legal. Quitting..." << endl;
		return;
	}
}

TestOpencvVideoCapture::~TestOpencvVideoCapture() {
	// TODO Auto-generated destructor stub
}

