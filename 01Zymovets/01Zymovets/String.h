#ifndef _ZYMOVETS01_STRING_
#define _ZYMOVETS01_STRING_
#include <string>

/******************************************************************************
*	Дати визначення власного класу String обробки 
*	рядків символів типу char, звертаючи особливу 
*	увагу на обґрунтованість вживання методів і утиліт.
*	Мінімальний набір операцій включатиме конструктори, 
*	в тому числі копіювальний, пересувний і конвертувальний, 
*	копіювальне і пересувне присвоєння =; конкатенацію +; 
*	суміщене присвоєння +=; порівняння ==, !=, <,>,<=,>=;  
*	селектор і модифікатор [], зведення до типів char* 
*	і string з бібліотеки STL.
*	
*	Зокрема передбачити можливість виконання змішаних операцій над рядками 
*	власного класу String, класу string з бібліотеки STL та С-рядками.
*	
*	На цьому етапі реалізація не потрібна, але необхідна перевірка 
*	синтаксичної правильності заголовного файлу String.h
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
		explicit String(const size_t size); //empty but not zero-sized 
		void copy_elems_from(const char* const);
	public:
		String(const _Char_t* = "");
		String(const std::string&);
		String(const String&);
		String(String&&) noexcept;
		~String();
	public:
		inline operator std::string() const; //const???
		inline operator const _Char_t*() const;
	public:
		inline String& operator= (const String&) &;
		inline String& operator= (String&&)			& noexcept;
		inline String& operator+= (const String&)	& noexcept;
	public:
		inline const _Char_t& operator[] (const size_t i) const;
		inline		 _Char_t& operator[] (const size_t i);
		inline size_t size() const noexcept;
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

		inline std::string what() const
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
		//strcpy(_chrs, str._chrs);
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
}
#endif // !_ZYMOVETS01_STRING_