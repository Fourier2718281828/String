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
		using _Char_t  = char;
		using _Size_t  = size_t;
	private:
		_Size_t		_size;
		_Char_t*	_chrs;
	private:
		explicit String(const _Size_t size);
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
		inline explicit operator std::string() const;
		inline explicit operator const _Char_t*() const;
	public:
		inline String& operator= (const String&) &;
		inline String& operator= (String&&)	& noexcept;
		inline String& operator+= (const String&) &;
	public:
		inline _Char_t  operator[] (const _Size_t i) const;
		inline _Char_t& operator[] (const _Size_t i);
		inline _Size_t size() const noexcept;
		inline bool empty()   const noexcept;
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
	public:
		using string_t = std::string;
	public:
		enum class Type
		{
			IndexOutOfBounds,
		};
	private:
		const string_t _message;
		const Type        _type;
	public:
		BadString(const Type type, const string_t& str = "") :
			_message(str), _type(type) {}

		~BadString() = default;

		inline const string_t what() const noexcept
		{
			return _message;
		}

		inline Type type() const noexcept
		{
			return _type;
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

	inline String& String::operator+= (const String& str) &
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
	inline String::_Char_t String::operator[] (const _Size_t i) const
	{
		using BS_Type = BadString::Type;
		if (i >= size())
			throw BadString(BS_Type::IndexOutOfBounds, "Index out of bounds.");
		return _chrs[i];
	}

	inline String::_Char_t& String::operator[] (const _Size_t i)
	{
		using BS_Type = BadString::Type;
		if (i >= size())
			throw BadString(BS_Type::IndexOutOfBounds, "Index out of bounds.");
		return _chrs[i];
	}

	inline String::_Size_t String::size() const noexcept
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