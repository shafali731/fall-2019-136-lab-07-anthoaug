#include <istream>
#include <cctype>

#include "funcs.h"

using std::istream;

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

	if (line.empty())
		return;

	for (int i = 0; i < cnt; ++i)
		res += "\t";

	line = res + line;
}

string format(istream& source) {
	string line, res;
	int ind = 0;

	while (getline(source, line)) {
		removeLeadingSpaces(line);

		ind -= countChar(line, '}');

		indent(line, ind);

		res += line + "\n";

		ind += countChar(line, '{');
	}

	return res.substr(0, res.length() - 1);
}