#include <iostream>
#include "AllTests.h"

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        cerr << "Usage: selKeyFrames InputDir OutputDir";
        exit(-1);
    }
    string inputDir = argv[1], outputDir = argv[2];
    TestOpencvSelKeyFrames tosk;

    tosk.GetAllFiles(inputDir, outputDir);
    tosk.CalcKeyFrames(6,3000,0.5);
}
