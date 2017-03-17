/*
 * TestOpencv.h
 *
 *  Created on: Mar 8, 2017
 *      Author: xushen
 */

#ifndef HEADER_TESTOPENCV_H_
#define HEADER_TESTOPENCV_H_

#include "Tests.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

class TestOpencv: public Tests {
public:
	TestOpencv();
	virtual void RunTests() const;
	virtual ~TestOpencv();
};

#endif /* HEADER_TESTOPENCV_H_ */
