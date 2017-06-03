/*
 * TestMyMatcher.h
 *
 *  Created on: Feb 28, 2017
 *      Author: xushen
 */

#ifndef HEADER_TESTOPENCVMYMATCHER_H_
#define HEADER_TESTOPENCVMYMATCHER_H_

#include "TestOpencv.h"

class TestOpencvMyMatcher: public Tests {
public:
    string imgf1, imgf2;
    cv::Mat desc1, desc2;
    cv::Mat img1, img2;
    vector<cv::KeyPoint> key1, key2;
    TestOpencvMyMatcher(string imgf1 = "/home/xushen/Pictures/Webcam/image_8.jpg",
                        string imgf2 = "/home/xushen/Pictures/Webcam/image_6.png")
    {this->imgf1 = imgf1; this->imgf2 = imgf2;}
    void setMatchFiles(string imgf1, string imgf2){this->imgf1 = imgf1; this->imgf2 = imgf2;}
    void getKeyAndDescs(string imgf1, cv::Mat & img1, std::vector<cv::KeyPoint> & key1, cv::Mat & desc1);
    void extractDescs(string imgf1, cv::Mat & img1, std::vector<cv::KeyPoint> & key1, cv::Mat & desc1);
	void RunTests() const;
    void RunTests();
	virtual ~TestOpencvMyMatcher();
};

#endif /* HEADER_TESTOPENCVMYMATCHER_H_ */
