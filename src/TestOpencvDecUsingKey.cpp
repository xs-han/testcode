/*
 * TestOpencvDecUsingKey.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: xushen
 */

#include "TestOpencvDecUsingKey.h"

TestOpencvDecUsingKey::TestOpencvDecUsingKey() {
	// TODO Auto-generated constructor stub

}

TestOpencvDecUsingKey::~TestOpencvDecUsingKey() {
	// TODO Auto-generated destructor stub
}

void TestOpencvDecUsingKey::RunTests() const
{
    cv::Mat img1 = cv::imread("/home/xushen/Pictures/Webcam/image_6.png", cv::IMREAD_COLOR);

    if(img1.empty())
    {
        cout << "Error in reading images. Exit now." << endl;
        exit(-1);
    }

    std::vector<cv::KeyPoint> key1, keynew, keydet;
    cv::Mat desc1, descnew, descdec, out1;
    cv::Ptr<cv::xfeatures2d::SIFT> fdetector1 = cv::xfeatures2d::SIFT::create(500);
    fdetector1->detect(img1, key1, cv::Mat());
    cout << "There are " << key1.size() << " descs in the image" << endl;

    cv::drawKeypoints(img1, key1, out1);
    cv::namedWindow("out1",0);
    cv::imshow("out1",out1);
    fdetector1->compute(img1, key1, desc1);

    //keynew.resize(key1.size());
    for(int i = 0; i < (int)key1.size(); i++)
    {
    	keynew.push_back(cv::KeyPoint(key1[i].pt, 5));
    }
    fdetector1->detectAndCompute(img1,cv::noArray(),keynew,descnew,true);

    cv::Mat mask1 = cv::Mat::zeros(img1.size(), CV_8U);
    for(int i = 0; i < (int)key1.size(); i++)
    {
    	mask1.at<int>((int)key1[i].pt.x, (int)key1[i].pt.y) = 1;
    	mask1.at<int>((int)key1[i].pt.x, (int)key1[i].pt.y + 1) = 1;
    	mask1.at<int>((int)key1[i].pt.x + 1, (int)key1[i].pt.y) = 1;
    	mask1.at<int>((int)key1[i].pt.x + 1, (int)key1[i].pt.y + 1) = 1;
    }
    fdetector1->detect(img1, keydet, mask1);
    fdetector1->compute(img1, keydet, descdec);

    cout << desc1.row(0) << endl;
    cout << descnew.row(0) << endl;
    cout << descdec.row(0) << endl;

    cv::waitKey(0);
    cv::destroyAllWindows();
}

