/*
 * TestOpencvVideoCapture.h
 *
 *  Created on: Mar 29, 2017
 *      Author: xushen
 */

#ifndef HEADER_TESTOPENCVVIDEOCAPTURE_H_
#define HEADER_TESTOPENCVVIDEOCAPTURE_H_

#include "TestOpencv.h"

/*
 *
 */
class TestOpencvVideoCapture: public TestOpencv {
public:
	TestOpencvVideoCapture();
	void RunTests() const;
	virtual ~TestOpencvVideoCapture();
};

#endif /* HEADER_TESTOPENCVVIDEOCAPTURE_H_ */
