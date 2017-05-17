#ifndef TESTOPENCVSELKEYFRAMES_H
#define TESTOPENCVSELKEYFRAMES_H

#include <string>
#include <vector>
#include <dirent.h>
#include <TestOpencv.h>

using namespace std;
using namespace cv;

class TestOpencvSelKeyFrames : public TestOpencv
{
public:
    vector<string> allFiles;
    //int refMatches;
    Mat refFrame;
    vector<KeyPoint> refKey;
    Mat refDesc;
public:
    TestOpencvSelKeyFrames();
    ~TestOpencvSelKeyFrames();
    void RunTests() const;
    void GetAllFiles(string, string);
    void CalcKeyFrames(int noctaves = 16, int npoints = 3000, double factor = 0.3, string d = "sift");
    void CalcKeyFramesOrb(int noctaves = 8, int npoints = 1000, double factor = 0.3);
private:
    int GetNumMatches(const Mat & refDesc, const Mat & Desc);
    string inputDir;
    string outputDir;
};

#endif // TESTOPENCVSELKEYFRAMES_H
