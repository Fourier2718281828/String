#ifndef _ZYMOVETS01_STRING_
#define _ZYMOVETS01_STRING_
#include <string>
#include <iostream>

/******************************************************************************
*	���� ���������� �������� ����� String ������� 
*	����� ������� ���� char, ��������� �������� 
*	����� �� ������������� �������� ������ � �����.
*	̳�������� ���� �������� ���������� ������������, 
*	� ���� ���� �����������, ���������� � ���������������, 
*	���������� � ��������� ��������� =; ������������ +; 
*	������� ��������� +=; ��������� ==, !=, <,>,<=,>=;  
*	�������� � ����������� [], �������� �� ���� char* 
*	� string � �������� STL.
*	
*	������� ����������� ��������� ��������� ������� �������� ��� ������� 
*	�������� ����� String, ����� string � �������� STL �� �-�������.
*	
*	�� ����� ���� ��������� �� �������, ��� ��������� �������� 
*	����������� ����������� ����������� ����� String.h
* 
* Author:	Ruslan Zymovets (SE)
* Date	:	28.09.2022
******************************************************************************/


namespace Zymovets01_String
{
	class String
	{
	public:
		using _Char_t = char;
	private:
		size_t		_size;
		_Char_t*	_chrs;
	private:
		explicit String(const size_t size);
		void copy_elems_from(const _Char_t* const);
	public:
		String();
		String(const _Char_t*);
		String(const _Char_t);
		String(const std::string&);
		String(const String&);
		String(String&&) noexcept;
		~String();
	public:
		inline operator std::string() const;
		inline explicit operator const _Char_t*() const;
	public:
		inline String& operator= (const String&) &;
		inline String& operator= (String&&)			& noexcept;
		inline String& operator+= (const String&)	& noexcept;
	public:
		inline const _Char_t& operator[] (const size_t i) const;
		inline		 _Char_t& operator[] (const size_t i);
		inline size_t size() const noexcept;
		inline bool empty() const noexcept;
		inline void clear();
	public:
		class BadString;
		friend String operator+(const String&, const String&);
	};

	bool operator==	(const String&, const String&);
	bool operator!=	(const String&, const String&);
	bool operator<	(const String&, const String&);
	bool operator>	(const String&, const String&);
	bool operator<=	(const String&, const String&);
	bool operator>=	(const String&, const String&);

	String operator+(const String&, const String&);



	class String::BadString
	{
	private:
		const std::string _message;
	public:
		BadString(const std::string str) :
			_message(str) {}

		~BadString() = default;

		inline std::string what() const noexcept
		{
			return _message;
		}
	};

	inline String::operator std::string() const
	{
		return std::string(_chrs);
	}

	inline String::operator const _Char_t* () const
	{
		return _chrs;
	}

	inline String& String::operator= (const String& str) &
	{
		if (this == &str)
		{
			return *this;
		}

		delete[] _chrs;
		_chrs = new _Char_t[str.size() + 1];
		copy_elems_from(str._chrs);
		_size = str.size();

		return *this;
	}

	inline String& String::operator= (String&& str)	& noexcept
	{
		if (this == &str)
		{
			return *this;
		}

		_size = str.size();
		delete[] _chrs;
		_chrs = str._chrs;
		
		str._chrs = nullptr;
		str._size = 0u;

		return *this;
	}

	inline String& String::operator+= (const String& str) & noexcept
	{
		return *this = *this + str;
	}

	/*
		It would be better not to check for exceeding the allowed index limits
		in operator[] and make an alternative pair of methods at(), which would 
		perform the check. This would improve the effectiveness of operator[]
		and allow to trace any necessary leaving the allowed index range 
		by exceptions thrown by methods at().

		I did not do that, as there has been no such a tendency within courses
		by VV.
	*/
	inline const String::_Char_t& String::operator[] (const size_t i) const
	{
		if (i >= size())
			throw BadString("Index out of bounds: " + i);
		return _chrs[i];
	}

	inline String::_Char_t& String::operator[] (const size_t i)
	{
		if (i >= size())
			throw BadString("Index out of bounds: " + i);
		return _chrs[i];
	}

	inline size_t String::size() const noexcept
	{
		return _size;
	}

	inline bool String::empty() const noexcept
	{
		return 0u == _size;
	}

	inline void String::clear()
	{
		*this = String();
	}
}
#endif // !_ZYMOVETS01_STRING_