#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

namespace Zymovets01_String
{
	String::String(const size_t size) :
		_size(size),
		_chrs(new String::_Char_t[size + 1])
	{
		_chrs[size] = '\0';
	}

	void String::copy_elems_from(const char* const source)
	{
		strcpy(_chrs, source);
	}

	String::String(const String::_Char_t* chrs) :
		//_size(strlen(chrs)),
		//_chrs(new String::_Char_t[_size + 1])
		String(strlen(chrs))
	{
		copy_elems_from(chrs);
	}

	String::String(const std::string& str) :
		//_size(str.size()),
		//_chrs(new String::_Char_t[str.size() + 1])
		String(str.size())
	{
		copy_elems_from(str.c_str());
	}

	String::String(const String& str) :
		//_size(str.size()),
		//_chrs(new String::_Char_t[str.size() + 1])
		String(str.size())
	{
		copy_elems_from(str._chrs);
	}

	String::String(String&& str) noexcept :
		_size(str.size()),
		_chrs(str._chrs)
	{
		str._chrs = nullptr;
		str._size = 0u;
	}

	String::~String()
	{
		delete[] _chrs;
		_chrs = nullptr;
		_size = 0u;
	}

	bool operator== (const String& a, const String& b)
	{
		for (size_t i = 0u; i < a.size(); ++i)
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
		for (size_t i = 0; i < std::min(a.size(), b.size()); ++i)
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
		
		for (size_t i = 0u; i < res.size(); ++i)
		{
			res[i] = i < a.size()
				? a[i]
				: b[i - a.size()];
		}

		return std::move(res);
	}

	
}
