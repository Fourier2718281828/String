#include "String.h"
#include "StringPrinter.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using namespace Zymovets01_String;


int main(void)
{
	String s = "123123";
	cout << (string("asd") + s + "asd") << endl;
}