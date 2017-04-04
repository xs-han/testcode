/*
 * TestBinFileIO.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: xushen
 */

#include "TestBinFileIO.h"
#include <fstream>

TestBinFileIO::TestBinFileIO() {
	// TODO Auto-generated constructor stub

}

TestBinFileIO::~TestBinFileIO() {
	// TODO Auto-generated destructor stub
}

void OpenBinFile(const string & filename)
{
	cout << "The current file opened is: " << filename;
	int header[5];
	fstream MySiftFile;
	MySiftFile.open(filename.c_str(), ios::in | ios::binary);

}

void TestBinFileIO::RunTests() const
{
	OpenBinFile("a.sift");
}
