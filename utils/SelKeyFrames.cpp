#include <iostream>
#include "AllTests.h"

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        cerr << "Usage: selKeyFrames InputDir OutputDir desc nps nocts factor";
        exit(-1);
    }
    string inputDir = argv[1], outputDir = argv[2];
    TestOpencvSelKeyFrames tosk;

    tosk.GetAllFiles(inputDir, outputDir);
    tosk.CalcKeyFrames(atoi(argv[5]),atoi(argv[4]),atoi(argv[6]),argv[3]);
}
