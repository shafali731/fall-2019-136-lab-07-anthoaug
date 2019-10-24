#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "tests/doctest.h"
#include "funcs/funcs.h"

TEST_CASE ("bad-code-1") {
	string ideal =
		"int main(){\n"
		"    // Hi, I'm a program!\n"
		"    int x = 1; \n"
		"    for(int i = 0; i < 10; i++) {\n"
		"        cout << i;\n"
		"        cout << endl;\n"
		"    } \n"
		"}     "
	;

	CHECK(formatFile("bad-code/bad-code-1") == ideal);
}

TEST_CASE ("bad-code-2") {
	string ideal =
	"int main(){\n"
	"    // Hi, I'm a program!\n"
	"    int x = 1; \n"
	"    for(int i = 0; i < 10; i++) {\n"
	"        cout << i;\n"
	"        cout << endl;\n"
	"    } \n"
	"}     "
	;

	CHECK(formatFile("bad-code/bad-code-2") == ideal);
}

TEST_CASE ("bad-code-3") {
	string ideal =
		"#include <fstream>\n"
		"#include <cctype>\n"
		"\n"
		"#include \"funcs/funcs.h\"\n"
		"\n"
		"using std::ifstream;\n"
		"\n"
		"void removeLeadingSpaces(string& line) {\n"
		"\tint cnt = 0;\n"
		"\n"
		"\tfor (char c : line)\n"
		"\t\tif (isspace(c))\n"
		"\t\t\tcnt++;\n"
		"\t\telse {\n"
		"\t\t\tline = line.substr(cnt);\n"
		"\t\t\treturn;\n"
		"\t\t}\n"
		"}\n"
		"\n"
		"int countChar(const string& line, char c) {\n"
		"\tint cnt = 0;\n"
		"\n"
		"\tfor (char ch : line)\n"
		"\t\tif (ch == c)\n"
		"\t\t\tcnt++;\n"
		"\n"
		"\treturn cnt;\n"
		"}"
	;

	CHECK(formatFile("bad-code/bad-code-3") == ideal);
}