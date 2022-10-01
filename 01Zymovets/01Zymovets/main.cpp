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
	cout << string("asda") + String("sada") + "asdas" << endl;
	string a = s;

	s = "asda";
	s += "asda";
	s += string("asda");
	s + 'a';

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

	std::sort(toSort.begin(), toSort.end(), std::less<String>());

	for (size_t i = 0u; i < toSort.size(); ++i)
	{
		cout << toSort[i] << endl;
	}
}