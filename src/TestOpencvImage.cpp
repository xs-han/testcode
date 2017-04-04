#include "TestOpencvImage.h"

TestOpencvImage::TestOpencvImage()
{
    //ctor
}

TestOpencvImage::~TestOpencvImage()
{
    //dtor
}

void TestOpencvImage::RunTests() const
{
    cv::Mat img1 = cv::imread("/mnt/hgfs/Shared/MediaSoc/dataset/sequences/KeyFrames/000000.jpg", cv::IMREAD_COLOR);
    std::vector<cv::KeyPoint> key;
    cv::Mat desc;
    cv::Ptr<cv::xfeatures2d::SIFT> fde = cv::xfeatures2d::SIFT::create(2000,8);
    fde->detectAndCompute(img1,cv::Mat(),key,desc,false);
    cv::namedWindow("img1",0);
    cv::imshow("img1", img1);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
