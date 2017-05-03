/*
 * TestOpencvMatxCons.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: xushen
 */

#include "TestOpencvMatxCons.h"

TestOpencvMatxCons::TestOpencvMatxCons() {
	// TODO Auto-generated constructor stub

}

TestOpencvMatxCons::~TestOpencvMatxCons() {
	// TODO Auto-generated destructor stub
}

void TestOpencvMatxCons::RunTests() const
{
	float a[3][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			a[i][j] = 3*i + j;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			cout << a[i][j] << ", ";
		cout << endl;
	}

	cv::Matx33d m;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			m(i,j) = a[i][j];
	cout << m << endl;

	cv::Matx33d m2;
	m2 = cv::Matx33d(a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
	cout << m2 << endl;

	cv::Matx31d m3;
	for(int i = 0; i < 3; i++)
	{
		m3(i) = i;
	}
	cout << m3 << endl;
	cout << m2 * m3 << endl;

    cv::Matx31d t(1,2,3);
    cv::Matx31d t2;
    t2 = t;
    t(2) = 0;
    cout << "t is: " << t << endl;
    cout << "t2 is: " << t2 << endl;
}
