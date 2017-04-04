#include "TestOpencvKeypoints.h"

TestOpencvKeypoints::TestOpencvKeypoints()
{
    //ctor
}

TestOpencvKeypoints::~TestOpencvKeypoints()
{
    //dtor
}

void TestOpencvKeypoints::RunTests() const
{
    cv::Mat img1 = cv::imread("/home/xushen/Pictures/Webcam/image_6.png", cv::IMREAD_COLOR);
    cv::Mat img2 = cv::imread("/home/xushen/Pictures/Webcam/image_7.png", cv::IMREAD_COLOR);

    if(img1.empty() || img2.empty())
    {
        cout << "Error in reading images. Exit now." << endl;
        exit(-1);
    }

    std::vector<cv::KeyPoint> key1, key2;
    cv::Mat desc1, out1, desc2, out2, outm;
    cv::Ptr<cv::xfeatures2d::SIFT> fdetector1 = cv::xfeatures2d::SIFT::create(2000);
    cv::Ptr<cv::xfeatures2d::SIFT> fdetector2 = cv::xfeatures2d::SIFT::create(2000);
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

    cv::BFMatcher flm(cv::NORM_L1);
    flm.knnMatch(desc1, desc2,matches12,2);
    flm.knnMatch(desc2, desc1,matches21,2);

    for(std::vector<std::vector<cv::DMatch> >::iterator i = matches12.begin(); i != matches12.end(); i++)
    {
    	i->pop_back();
    }
    for(std::vector<std::vector<cv::DMatch> >::iterator i = matches21.begin(); i != matches21.end(); i++)
    {
    	i->pop_back();
    }

    for(std::vector<std::vector<cv::DMatch> >::iterator i = matches12.begin(); i != matches12.end(); i++)
    {
    	for(std::vector<std::vector<cv::DMatch> >::iterator j = matches21.begin(); j != matches21.end(); j++)
    	{
    		if((*i)[0].queryIdx == (*j)[0].trainIdx && (*j)[0].queryIdx == (*i)[0].trainIdx)
    		{
    			good.push_back(*i);
    		}
    	}
    }

    cv::drawMatches(img1, key1, img2,key2,good, outm);

    cv::namedWindow("out",0);
    cv::imshow("out",outm);
    cv::waitKey(0);
    cv::destroyAllWindows();




}
