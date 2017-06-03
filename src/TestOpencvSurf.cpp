#include "TestOpencvSurf.h"

TestOpencvSurf::TestOpencvSurf()
{

}

TestOpencvSurf::~TestOpencvSurf()
{

}

void TestOpencvSurf::RunTests() const
{
    cv::Mat img1 = cv::imread("/home/xushen/Desktop/Frames_line/000000.jpg", cv::IMREAD_COLOR);
    cv::Mat img2 = cv::imread("/home/xushen/Desktop/Frames_line/000001.jpg", cv::IMREAD_COLOR);

    if(img1.empty() || img2.empty())
    {
        cout << "Error in reading images. Exit now." << endl;
        exit(-1);
    }

    std::vector<cv::KeyPoint> key1, key2;
    cv::Mat desc1, out1, desc2, out2, outm;
    cv::Ptr<cv::Feature2D> fdetector1 = cv::xfeatures2d::SURF::create(500,8);
    cv::Ptr<cv::Feature2D> fdetector2 = cv::xfeatures2d::SURF::create(500,8);
    cv::Ptr<cv::Feature2D> fdesc1 = cv::xfeatures2d::SIFT::create(1000,8);
    cv::Ptr<cv::Feature2D> fdesc2 = cv::xfeatures2d::SIFT::create(1000,8);

    fdetector1->detect(img1,key1);
    fdetector2->detect(img2,key2);
    fdetector1->compute(img1,key1,desc1);
    fdetector2->compute(img2,key2,desc2);

    for(int i = 0; i < desc1.rows; i++)
        for(int j = 0; j < desc1.cols; j++)
            desc1.at<float>(i,j) = round(desc1.at<float>(i,j) * 256 + 256);

    for(int i = 0; i < desc2.rows; i++)
        for(int j = 0; j < desc2.cols; j++)
            desc2.at<float>(i,j) = round(desc2.at<float>(i,j) * 256 + 256);

    double mind = 0, maxd = 0;
    cv::minMaxLoc(desc1, &mind, &maxd);
    cout << mind << " , " <<maxd  << endl;
    cout << desc1.row(0) << endl;
    cv::minMaxLoc(desc2, &mind, &maxd);
    cout << mind << " , " <<maxd  << endl;
    cout << desc2.row(0) << endl;

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
        {
            //cout << "feature " << i << " is not good" << endl;
        }
    }
    cout << good.size() << " matches got." << endl;
    cv::drawMatches(img1, key1, img2,key2,good, outm);

    cv::namedWindow("out",0);
    cv::imshow("out",outm);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
