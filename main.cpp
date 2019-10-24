#include <iostream>
#include <list>

#include "funcs/funcs.h"

using std::cout;
using std::list;
using std::cin;


int main() {
	list<string> lines;
	string line, res;

	res = format(cin);

	cout << res;
}