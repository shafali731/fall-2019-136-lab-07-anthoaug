#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <fstream>

#include "../funcs/funcs.h"
#include "doctest.h"

using std::ifstream;

TEST_CASE ("bad-code-1") {
	string ideal =
		"int main(){\n"
		"\t// Hi, I'm a program!\n"
		"\tint x = 1;\n"
		"\tfor(int i = 0; i < 10; i++) {\n"
		"\t\tcout << i;\n"
		"\t\tcout << endl;\n"
		"\t}\n"
		"}";

	ifstream code("bad-code/bad-code-1");

	CHECK(format(code) == ideal);
}

TEST_CASE ("bad-code-2") {
	string ideal =
		"int main(){\n"
		"\t// Hi, I'm a program!\n"
		"\tint x = 1;\n"
		"\tfor(int i = 0; i < 10; i++) {\n"
		"\t\tcout << i;\n"
		"\t\tcout << endl;\n"
		"\t}\n"
		"}";

	ifstream code("bad-code/bad-code-2");

	CHECK(format(code) == ideal);
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
		"\tfor (char c : line) {\n"
		"\t\tif (isspace(c)) {\n"
		"\t\t\tcnt++;\n"
		"\t\t}\n"
		"\t\telse {\n"
		"\t\t\tline = line.substr(cnt);\n"
		"\t\t\treturn;\n"
		"\t\t}\n"
		"\t}\n"
		"}\n"
		"\n"
		"int countChar(const string& line, char c) {\n"
		"\tint cnt = 0;\n"
		"\n"
		"\tfor (char ch : line) {\n"
		"\t\tif (ch == c) {\n"
		"\t\t\tcnt++;\n"
		"\t\t}\n"
		"\t}\n"
		"\n"
		"\treturn cnt;\n"
		"}";

	ifstream code("bad-code/bad-code-3");

	CHECK(format(code) == ideal);
}