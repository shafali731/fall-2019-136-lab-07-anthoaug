#include <istream>
#include <string>
#include <cctype>

#include "funcs.h"

using std::istream;
using std::string;

bool there(string line, string word){
	int s= word.length();
	for(int i = 0; i<line.length()-s+2; i++){
		if(line.substr(i, s) == word){
			return true;
		}
	}
	return false;
}
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
	bool ifyes= false;
	int ind = 0;

	while (getline(source, line)) {
		removeLeadingSpaces(line);

		ind -= countChar(line, '}');

		if (ifyes){
			indent(line, ind+1);

			ifyes= false;
		}
		else{
			indent(line, ind);

			}

		res += line + "\n";
		if((there(line, "if") || there(line, "for")) && !there(line, "{")){
		//	ind +=1;
			ifyes = true;
		}

		ind += countChar(line, '{');
	}

	return res.substr(0, res.length() - 1);
}
