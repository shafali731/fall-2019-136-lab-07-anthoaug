#ifndef FALL_2019_136_LAB_07_ANTHOAUG_FUNCS_H
#define FALL_2019_136_LAB_07_ANTHOAUG_FUNCS_H

#include <string>

using std::string;

string removeLeadingSpaces(const string& line);

int countChar(const string& line, char c);

string indent(const string& line, int cnt);

#endif