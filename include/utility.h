/*
 * utility.h
 *
 *  Created on: 2013-03-03
 *      Author: capncanuck
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// TODO comment
string &rtrim(string &s);

// http://www.cplusplus.com/faq/sequences/strings/split/
// puts the results in an already constructed vector
// TODO document
vector<string> &split(const string &s, char delim, vector<string> &elems);

//returns a new vector
// TODO document
vector<string> split(const string &s, char delim);

#endif /* UTILITY_H_ */
