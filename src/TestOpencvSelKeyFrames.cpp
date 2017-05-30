#include "TestOpencvSelKeyFrames.h"

using namespace std;
using namespace cv;

TestOpencvSelKeyFrames::TestOpencvSelKeyFrames()
{

}

TestOpencvSelKeyFrames::~TestOpencvSelKeyFrames()
{

}

void TestOpencvSelKeyFrames::RunTests() const
{
    cout << "This example is utilized for SelKeyFrames.cpp" << endl;
}

void TestOpencvSelKeyFrames::GetAllFiles(string InputDir, string OutputDir)
{
    if(*(InputDir.end()-1) != '/')
        InputDir += "/";
    if(*(OutputDir.end()-1) != '/')
        OutputDir += "/";
    inputDir = InputDir; outputDir = OutputDir;
    system(("rm -rf " + outputDir + "*").c_str());
    allFiles.clear();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(inputDir.c_str())) != NULL)
    {
        cout << "Oper dir: " << inputDir << endl;
        while ((ent = readdir (dir)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 &&
               strcmp(ent->d_name, "..") !=0)
            allFiles.push_back(ent->d_name);
        }
        std::sort(allFiles.begin(), allFiles.end());
        for(auto f = allFiles.begin(); f != allFiles.end(); f++ )
        {
            cout << "Get file: " << *(f) << endl;
        }
        closedir (dir);
    }
    else
    {
        /* could not open directory */
        cerr << "The input directory cannot be open." << endl;
        exit(-1);
    }
}

void TestOpencvSelKeyFrames::CalcKeyFrames(int noctaves, int npoints, double factor, string d)
{
    refFrame = imread(inputDir + allFiles[0]);
    cv::Ptr<cv::Feature2D> fdetector;
    if(d == "sift")
        fdetector = cv::xfeatures2d::SIFT::create(npoints, noctaves);
    else if(d == "surf")
        fdetector = cv::xfeatures2d::SURF::create(npoints, noctaves, 6);
    else
        {cout << "error in descs" << endl; exit(-1);}
    fdetector->detectAndCompute(refFrame,cv::Mat(),refKey,refDesc,false);
    //refMatches = npoints;

    for(int i = 0; i < (int) allFiles.size(); i++)
    {
        cout << "handling: " << allFiles[i] << endl;
        Mat crtFrame = imread(inputDir + allFiles[i]);
        vector<KeyPoint> crtKey;
        Mat crtDesc;
        cv::Ptr<cv::Feature2D> fdetector2;
        if(d == "sift")
            fdetector2 = cv::xfeatures2d::SIFT::create(npoints, noctaves);
        else if(d == "surf")
            fdetector2 = cv::xfeatures2d::SURF::create(npoints, noctaves, 6);
        else
            {cout << "error in descs" << endl; exit(-1);}
        fdetector2->detectAndCompute(crtFrame,cv::Mat(),crtKey,crtDesc,false);

        int nmatches = GetNumMatches(refDesc, crtDesc);
        if(nmatches < refDesc.rows * factor || i == 0)
        {
            if(imwrite((outputDir + allFiles[i]), crtFrame))
            {
                cout << "Saving " << allFiles[i] << " with " << crtDesc.rows << " descs." << endl;
            }
            else
            {
                cout << "Output error." << endl;
                exit(-2);
            }
            refFrame = crtFrame.clone();
            refDesc = crtDesc.clone();
        }
    }

}

void TestOpencvSelKeyFrames::CalcKeyFramesOrb(int noctaves, int npoints, double factor)
{
    refFrame = imread(inputDir + allFiles[0]);
    cv::Ptr<cv::Feature2D> fdetector = cv::ORB::create(npoints, 1.2f, noctaves);
    fdetector->detectAndCompute(refFrame,cv::Mat(),refKey,refDesc,false);

    for(int i = 0; i < (int) allFiles.size(); i++)
    {
        cout << "handling: " << allFiles[i] << endl;
        Mat crtFrame = imread(inputDir + allFiles[i]);
        vector<KeyPoint> crtKey;
        Mat crtDesc;
        cv::Ptr<cv::Feature2D> fdetector = cv::ORB::create(npoints, 1.2f, noctaves);
        fdetector->detectAndCompute(crtFrame,cv::Mat(),crtKey,crtDesc,false);
        cout << crtDesc << endl;
        int nmatches = GetNumMatches(refDesc, crtDesc);
        if(nmatches < refDesc.rows * factor || i == 0)
        {
            if(imwrite((outputDir + allFiles[i]), crtFrame))
            {
                cout << "Saving " << allFiles[i] << endl;
            }
            else
            {
                cout << "Output error." << endl;
                exit(-2);
            }
            refFrame = crtFrame.clone();
            refDesc = crtDesc.clone();
        }
    }
}

int TestOpencvSelKeyFrames::GetNumMatches(const Mat &desc1, const Mat &desc2)
{
    std::vector<std::vector<cv::DMatch> > matches12, matches21, good;

    for(int i = 0; i < desc1.rows; i++)
    {
        double mindis = 10000;
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

        double mindis_back = 10000;
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
        if(minid_back == i/* && mindis < 10000*/)
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
    return (int)good.size();
}
