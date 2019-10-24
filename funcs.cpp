#include <cctype>

#include "funcs.h"

string removeLeadingSpaces(const string& line) {
	int cnt = 0;

	for (char c : line)
		if (isspace(c))
			cnt++;
		else
			return line.substr(cnt);


	return "";
}

int countChar(const string& line, char c) {
	int cnt = 0;

	for (char ch : line)
		if (ch == c)
			cnt++;

	return cnt;
}

string indent(const string& line, int cnt) {
	string res;

	for (int i = 0; i < cnt; ++i)
		res += "\t";

	return res + line;
}