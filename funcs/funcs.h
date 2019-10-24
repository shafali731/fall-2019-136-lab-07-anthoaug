#ifndef FALL_2019_136_LAB_07_ANTHOAUG_FUNCS_H
#define FALL_2019_136_LAB_07_ANTHOAUG_FUNCS_H

#include <istream>
#include <string>
#include <list>

using std::istream;
using std::string;
using std::list;

void removeLeadingSpaces(string &line);

int countChar(const string& line, char c);

void indent(string& line, int cnt);

string format(istream& source);

#endif