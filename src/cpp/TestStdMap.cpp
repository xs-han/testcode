/*
 * TestStdMap.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: xushen
 */

#include "../header/TestStdMap.h"
//#include <string>
#include <map>

TestStdMap::TestStdMap() {
	// TODO Auto-generated constructor stub

}

TestStdMap::~TestStdMap() {
	// TODO Auto-generated destructor stub
}

void TestStdMap::RunTests() const
{
	cout << "This is test run of std map." << endl;
	std::map<string, double> m;
	m["cha"] = 3;
	m["che"] = 5;
	m["chz"] = 7;
	std::map<string, double>::iterator it = m.begin();
	for(it = m.begin(); it != m.end(); it++)
	{
		cout << "Map: " << it->first << " ==> " << it->second << endl;
	}
	cout << "Test bounds functions:" << endl;
	it = m.lower_bound("ch1");
	cout << "Map: lower bound:" << it->first << " ==> " << it->second << endl;
	it = m.upper_bound("ch2.5");
	cout << "Map: upper bound:" << it->first << " ==> " << it->second << endl;
}
