#include "TestOpencvMat.h"

TestOpencvMat::TestOpencvMat()
{
    //ctor
}

TestOpencvMat::~TestOpencvMat()
{
    //dtor
}

void TestOpencvMat::RunTests() const
{
    cv::Mat m;
    m.push_back(cv::Mat(3,1,CV_32F,2));
    cout << "m is " << m << endl;

    cv::Mat h = cv::Mat::eye(3,3,CV_32F);
    cout << "h is " << h << endl;

    cout << "h * m is:" << h * m << endl;
    cout << "h * 2 is:" << h * 2 << endl;
    cout << "h + 2 is:" << h + 2 << endl;
    cout << "max(h,2) is:" << cv::max(h,2) << endl;

    // Mat copy
    cv::Mat m1 = cv::Mat::zeros(4,4,CV_32F);
    cv::Mat m2 = m1.clone();
    cout << "m1 is: \n" << m1 << endl;
    cout << "m2 is: \n" << m2 << endl;

    m1.at<float>(3,3) = 1;
    cout << "m1 is: \n" << m1 << endl;
    cout << "m2 is: \n" << m2 << endl;

}
