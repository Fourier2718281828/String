#include "String.h"
#include "StringPrinter.h"
#include <iostream>
#include <algorithm>
#include <vector>
using _STD cout;
using _STD endl;
using namespace Zymovets01_String;


int main(void)
{
	//Constructors, assignment :
	{
		cout << "1. Constructors & assignment" << endl;
		cout << "Calling all the constructors :" << endl;
		String a;							cout << "Created : " << '\"' << a << '\"' << endl;
		String b = "String";				cout << "Created : " << '\"' << b << '\"' << endl;
		String c = 's';						cout << "Created : " << '\"' << c << '\"' << endl;
		String d(std::string("string"));	cout << "Created : " << '\"' << d << '\"' << endl;
		String e(b);						cout << "Created : " << '\"' << e << '\"' << endl;
		String f = _STD move(a);			cout << "Created : " << '\"' << f << '\"' << endl;

		cout << "Notice: String(nullptr) is forbidden by String(std::nullptr_t) = delete!" << endl;
		//String(nullptr);

		cout << endl;

		cout << "Copy-Assignment :" << endl;
		b = c;					cout << "Result : " << '\"' << b << '\"' << endl;
		cout << "Move-Assignment :" << endl;
		c = _STD move(e);		cout << "Result : " << '\"' << c << '\"' << endl;
	}
	//Converting operators :
	cout << endl;
	{
		cout << "2. The converting operators are implemented to be explicit." << endl;
		cout << "Creating Strings to convert : " << endl;
		String a = "abc";
		cout << "Created : " << '\"' << a << '\"' << endl;
		cout << "As const char* : " << '\"' << static_cast<const char*>(a) << '\"' << endl;
		cout << "As std::string : " << '\"' << static_cast<std::string>(a) << '\"' << endl;
	}
	//operator[] :
	{
		cout << endl;
		cout << "3. operator[]" << endl;
		cout << "Creating a String :" << endl;
		String str = "str";
		cout << "Created : " << str << endl;
		cout << "Iterating over it via operator[] : " << endl;
		for (size_t i = 0u; i < str.size(); ++i)
		{
			cout << str[i] << ' ';
		}
		cout << endl << "When exceeding the index limit : " << endl;

		using BadStr = String::BadString;

		try
		{
			str[str.size()];
		} 
		catch (const BadStr& bs)
		{
			switch (bs.type())
			{
			case BadStr::Type::IndexOutOfBounds:
				cout << bs.what() << endl;
			default:
				break;
			}
		}

		str[0] = 'B';
		cout << "Assigning str[0] = 'B';  str = " << str << endl;
	}

	//Additional methods :
	{
		cout << endl;
		cout << "4. Methods size(), empty(), clear()" << endl;
		String str("some_str");
		cout << "String created : " << '\"' << str << '\"' << endl;
		cout << "str.size() = " << str.size() << endl;
		cout << _STD boolalpha << "str.empty() = " << str.empty() << endl;
		cout << "str.clear();" << endl;
		str.clear();
		cout << "str = " << '\"' << str  << '\"' << ", str.empty() = " << str.empty() << endl;
	}
	//operator+ and operator+= :
	{
		cout << endl;
		cout << "5. operator+ and operator+= : " << endl;
		cout << "Operator+ calls moving constructor to move the local result :" << endl;
		cout << "String(\"abc\") + String(\"def\"): " << endl;
		cout << "Result = " << String("abc") + String("def") << endl;

		cout << endl;
		cout << "When trying to mix types : " << endl;
		cout << "String(\"abc\") + \"cde\" = " << endl << String("abc") + "cde" << endl;
		cout << "\"cde\" + String(\"abc\") = " << endl << "cde" + String("abc") << endl;
		cout << "String(\"abc\") + std::string(\"cde\") = " << endl << String("abc") + std::string("cde") << endl;
		cout << "std::string(\"cde\") + String(\"abc\") = " << endl << std::string("cde") + String("abc") << endl;
		cout << endl;
		cout << endl;
		String str1("abc"), str2("def");
		cout << "str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"." << endl;
		cout << "str1 += str2 :" << endl;
		str1 += str2;
		cout << "str2 += \"some\" :" << endl;
		str2 += "some";
		cout << "str1 += std::string(\"some\") :" << endl;
		str1 += std::string("some");
		cout << "str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"." << endl;
	}

	//Cmp operators :
	cout << endl;
	cout << "String(\"abc\") != String(\"cde\") = " << endl << (String("abc") != String("cde")) << endl;
	cout << "String(\"abc\") == \"abc\" = " << endl << (String("abc") == String("abc")) << endl;

	cout << endl << "Now create a vector of Strings (a tone of copies) :" << endl;
	std::vector<String> toSort 
	{
		"bcd",
		"abcd",
		"ab",
		"abc",
		"abc",
		"defgas",
		"dabc"
	};
	auto pringToSort = [&toSort]()
	{
		cout << "toSort :" << endl;
		for (size_t i = 0u; i < toSort.size(); ++i)
		{
			cout << toSort[i] << endl;
		}
	};
	cout << endl;
	pringToSort();
	cout << endl;
	cout << "Now sort it using std::sort (some moves):" << endl;
	_STD sort(toSort.begin(), toSort.end(), std::less<String>());
	cout << endl;
	pringToSort();
}