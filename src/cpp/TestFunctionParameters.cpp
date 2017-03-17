/*
 * TestFunctionParameters.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: xushen
 */

#include "/home/xushen/workspace/Tests/src/header/TestFunctionParameters.h"

TestFunctionParameters::TestFunctionParameters():m_test(0) {
	// TODO Auto-generated constructor stub
	// cout << "Default cons is running." << endl;
}

TestFunctionParameters::TestFunctionParameters(int a)
{
	cout << "Reloaded cons is running." << endl;
	this->m_test = a;
}

TestFunctionParameters::~TestFunctionParameters() {
	// TODO Auto-generated destructor stub
}

void TestFunctionParameters::RunTests() const
{
	int a = 2;
	int * p = new int(4);
	this->testfunciton(a, p);
}

void TestFunctionParameters::testfunciton(int a, int * p) const
{
	cout << "The number a is " << a << endl;
	if(p == NULL)
	{
		cout << "p is NULL" << endl;
	}
	else
	{
		cout << "p is not NULL. " << "*p is " << *p << endl;
	}
	cout << "member test is " << m_test << endl;
	return;
}
