/**
 * A file that contains static methods for string manipulation.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
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

#endif /* UTILITY_H_ */
