/*
 * TestArrayandPointer.cpp
 *
 *  Created on: Mar 14, 2017
 *      Author: xushen
 */

#include "TestArrayandPointer.h"

TestArrayandPointer::TestArrayandPointer() {
	// TODO Auto-generated constructor stub

}

TestArrayandPointer::~TestArrayandPointer() {
	// TODO Auto-generated destructor stub
}

void TestStaticArray(int a[])
{
	a[0] = 1;
}

void TestDynamicArray(int * a)
{
	a[0] = 1;
}

void TestArrayandPointer::RunTests() const
{
	int a[3] = {0,0,0};
	cout << a[0] << a[1] << a[2] << endl;
	TestStaticArray(a);
	cout << a[0] << a[1] << a[2] << endl;

	int * p = new int[3];
	for(int i = 0; i < 3; i++)
	{
		p[i] = i;
	}
	cout << p[0] << p[1] << p[2] << endl;
	TestDynamicArray(p);
	cout << p[0] << p[1] << p[2] << endl;

	int * b = a;

}
