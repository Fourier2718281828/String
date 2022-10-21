#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

#ifndef NDEBUG
#include "StringPrinter.h"
#include <iostream>
#endif // !NDEBUG

#define PRINT(s) \
_STD cout << s << _STD endl;


namespace Zymovets01_String
{
	String::String(const size_t size) :
		_size(size),
		_chrs(new String::_Char_t[size + 1])
	{
		_chrs[size] = '\0';
	}

	void String::copy_elems_from(const String::_Char_t* const source)
	{
		strcpy(_chrs, source);
	}

	String::String() :
		_size(0u),
		_chrs(new String::_Char_t[1]{'\0'})
	{
#ifndef NDEBUG
		PRINT("### String()")
#endif // !NDEBUG
	}

	String::String(const String::_Char_t* chrs) :
		String(strlen(chrs))
	{
		copy_elems_from(chrs);

#ifndef NDEBUG
		PRINT("### String(const String::_Char_t* chrs)")
#endif // !NDEBUG
	}

	String::String(const _Char_t ch) :
		_size(1u),
		_chrs(new String::_Char_t[2]{ch, '\0'})
	{
#ifndef NDEBUG
		PRINT("### String(const _Char_t ch)")
#endif // !NDEBUG
	}

	String::String(const std::string& str) :
		String(str.size())
	{
		copy_elems_from(str.c_str());

#ifndef NDEBUG
		PRINT("### String(const std::string& str)")
#endif // !NDEBUG
	}

	String::String(const String& str) :
		String(str.size())
	{
		copy_elems_from(str._chrs);

#ifndef NDEBUG
		PRINT("### String(const String& str)")
#endif // !NDEBUG
	}

	String::String(String&& str) noexcept :
		_size(str.size()),
		_chrs(str._chrs)
	{
		str._chrs = nullptr;
		str._size = 0u;

#ifndef NDEBUG
		PRINT("### String(String&& str)")
#endif // !NDEBUG
	}

	String::~String()
	{
		delete[] _chrs;
		_chrs = nullptr;
		_size = 0u;
	}
	 
	bool operator== (const String& a, const String& b) 
	{
		for (String::_Size_t i = 0u; i < a.size(); ++i)
		{
			if (a[i] != b[i]) return false;
		}

		return true;
	}

	bool operator!=	(const String& a, const String& b)
	{
		return !(a == b);
	}

	bool operator<	(const String& a, const String& b)
	{
		for (String::_Size_t i = 0; i < std::min(a.size(), b.size()); ++i)
		{
			if (a[i] != b[i])
			{
				return a[i] < b[i];
			}
		}

		return a.size() < b.size();
	}

	bool operator>	(const String& a, const String& b)
	{
		return b < a;
	}

	bool operator<=	(const String& a, const String& b)
	{
		return !(b < a);
	}

	bool operator>=	(const String& a, const String& b)
	{
		return !(a < b);
	}

	String operator+(const String& a, const String& b)
	{
		String res(a.size() + b.size());
		
		for (String::_Size_t i = 0u; i < res.size(); ++i)
		{
			res[i] = i < a.size()
				? a[i]
				: b[i - a.size()];
		}

		return std::move(res);
	}
}