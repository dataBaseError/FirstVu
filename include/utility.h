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

/**
 * Removes all spaces from the right side of a string
 * http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
 *
 * @param s the string that needs spaces removed from the right
 * @return the trimmed string
 */
string &rtrim(string &s);

/**
 * Puts the results in an already constructed vector
 * http://www.cplusplus.com/faq/sequences/strings/split/
 *
 * @param s the remaining string
 * @param delim a delimiter where a string will be splitted
 * @param elems a collection of accumulated tokens
 * @return a new vector of strings
 */
vector<string> &split(const string &s, char delim, vector<string> &elems);

/*
 * Splits a string by a delimiter
 *
 * @param s a string separated by the delimiter
 * @param delim a delimiter where a string will be splitted
 * @return a new vector
 */
vector<string> split(const string &s, char delim);

#endif /* UTILITY_H_ */
