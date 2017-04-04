/*
 * TestFunctionParameters.h
 *
 *  Created on: Mar 5, 2017
 *      Author: xushen
 */

#ifndef HEADER_TESTFUNCTIONPARAMETERS_H_
#define HEADER_TESTFUNCTIONPARAMETERS_H_

#include "Tests.h"

class TestFunctionParameters:public Tests
{
public:
	TestFunctionParameters();
	TestFunctionParameters(int a);
	void RunTests() const;
	void testfunciton(int a, int * p = NULL) const;
	virtual ~TestFunctionParameters();
protected:
	int m_test;
};

#endif /* HEADER_TESTFUNCTIONPARAMETERS_H_ */
