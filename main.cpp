#include <iostream>

#include "funcs/funcs.h"

using std::cout;

int main() {
	cout << formatFile("bad-code/bad-code-1");

	string ideal =
	"int main(){\n"
	"\t// Hi, I'm a program!\n"
	"\tint x = 1;\n"
	"\tfor(int i = 0; i < 10; i++) {\n"
	"\t\tcout << i;\n"
	"\t\tcout << endl;\n"
	"\t}\n"
	"}"
	;

	cout << std::endl << ideal;
}