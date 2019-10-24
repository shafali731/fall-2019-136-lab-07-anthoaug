#include <fstream>
#include <cctype>

#include "funcs.h"

using std::ifstream;

void removeLeadingSpaces(string& line) {
	int cnt = 0;

	for (char c : line)
		if (isspace(c))
			cnt++;
		else {
			line = line.substr(cnt);
			return;
		}
}

int countChar(const string& line, char c) {
	int cnt = 0;

	for (char ch : line)
		if (ch == c)
			cnt++;

	return cnt;
}

void indent(string& line, int cnt) {
	string res;

	for (int i = 0; i < cnt; ++i)
		res += "\t";

	line = res + line;
}

string formatFile(const string& filename) {
	ifstream input(filename);
	string line, res;
	int ind = 0;

	while (getline(input, line)) {
		removeLeadingSpaces(line);

		ind -= countChar(line, '}');

		indent(line, ind);

		res += line + "\n";

		ind += countChar(line, '{');
	}

	return res;
}
