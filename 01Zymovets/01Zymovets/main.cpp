#include "String.h"
#include "StringPrinter.h"
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using namespace Zymovets01_String;


int main(void)
{
	String s = "123123";
	cout << (string("asd") + s + "asd") << endl;

	std::vector<String> toSort 
	{
		"child",
		"chi",
		"adsa",
		"abava",
		"children",
		"chi",
		"baddu"
	};

	std::sort(toSort.begin(), toSort.end(), [](const String& a, const String& b) { return a < b; });

	for (size_t i = 0u; i < toSort.size(); ++i)
	{
		cout << toSort[i] << endl;
	}
}