/*
 * TestMyMatcher.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: xushen
 */

#include "../header/TestOpencvMyMatcher.h"

TestOpencvMyMatcher::TestOpencvMyMatcher() {
	// TODO Auto-generated constructor stub

}

TestOpencvMyMatcher::~TestOpencvMyMatcher() {
	// TODO Auto-generated destructor stub
}

void TestOpencvMyMatcher::RunTests() const
{
    cv::Mat img1 = cv::imread("/home/xushen/Pictures/Webcam/image_6.png", cv::IMREAD_COLOR);
    cv::Mat img2 = cv::imread("/home/xushen/Pictures/Webcam/image_8.jpg", cv::IMREAD_COLOR);

    if(img1.empty() || img2.empty())
    {
        cout << "Error in reading images. Exit now." << endl;
        exit(-1);
    }

    std::vector<cv::KeyPoint> key1, key2;
    cv::Mat desc1, out1, desc2, out2, outm;
    cv::Ptr<cv::Feature2D> fdetector1 = cv::xfeatures2d::SIFT::create(500);
    cv::Ptr<cv::Feature2D> fdetector2 = cv::xfeatures2d::SIFT::create(500);
    fdetector1->detectAndCompute(img1,cv::Mat(),key1,desc1,false);
    fdetector2->detectAndCompute(img2,cv::Mat(),key2,desc2,false);

    cout << "There are " << key1.size() << " and " << key2.size() << " descs in 2 images, respectively." << endl;

    cv::drawKeypoints(img1, key1, out1);
    cv::drawKeypoints(img2, key2, out2);

    cv::namedWindow("out1",0);
    cv::imshow("out1",out1);
    cv::namedWindow("out2",0);
    cv::imshow("out2",out2);
    cv::waitKey(0);
    cv::destroyAllWindows();

    std::vector<std::vector<cv::DMatch> > matches12, matches21, good;


    for(int i = 0; i < desc1.rows; i++)
    {
        double mindis = 1000;
        int minid = 0;
        double dis = 0;
    	for(int j = 0; j < desc2.rows; j++)
    	{
    		dis = (cv::sum(cv::abs(desc1.row(i) - desc2.row(j))))[0];
    		if(dis < mindis)
    		{
    			mindis = dis;
    			minid = j;
    		}
    	}

    	double mindis_back = 1000;
    	int minid_back = 0;

    	for(int k = 0; k < desc1.rows; k++)
    	{
    		double dis_back = 0;
    		dis_back = (cv::sum(cv::abs(desc2.row(minid) - desc1.row(k))))[0];
    		if(dis_back < mindis_back)
    		{
    			mindis_back = dis_back;
    			minid_back = k;
    		}
    	}
    	std::vector<cv::DMatch> a;
    	if(minid_back == i && mindis < 200)
    	{
    		a.clear();
    		a.push_back(cv::DMatch(i,minid,0,mindis));
    		good.push_back(a);
    	}
    	else
    		cout << "feature " << i << " is not good" << endl;
    }
    cout << good.size() << " matches got." << endl;
    cv::drawMatches(img1, key1, img2,key2,good, outm);

    cv::namedWindow("out",0);
    cv::imshow("out",outm);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
