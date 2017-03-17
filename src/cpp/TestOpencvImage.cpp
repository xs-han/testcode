#include "../header/TestOpencvImage.h"

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
    cv::Mat img1 = cv::imread("/home/xushen/Pictures/Webcam/image_6.png", cv::IMREAD_COLOR);
    cv::namedWindow("img1",0);
    cv::imshow("img1", img1);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
