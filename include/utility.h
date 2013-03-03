/*
 * utility.h
 *
 *  Created on: 2013-03-03
 *      Author: capncanuck
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>
#include <sstream>
#include <vector>

using namespace std;

// http://www.cplusplus.com/faq/sequences/strings/split/
// puts the results in an already constructed vector
vector<string> &split(const string &s, char delim, vector<string> &elems);

//returns a new vector
vector<string> split(const string &s, char delim);

#endif /* UTILITY_H_ */
