#ifndef _ZYMOVETS01_STRING_
#define _ZYMOVETS01_STRING_
#include <string>

namespace Zymovets01_String
{
	class String
	{
	public:
		using _Char_t = char;
	private:
		_Char_t*	_chrs;
		size_t		_size;
	public:
		String(const char* = "");
		String(const std::string&);
		String(const String&)	noexcept;
		String(String&&)		noexcept;
		~String();
	public:
		inline operator std::string() const; //const???
		inline operator const char*() const;
	public:
		inline String& operator= (const String&)	& noexcept;
		inline String& operator= (const String&&)	& noexcept;
	public:
		inline String& operator+= (const String&)	& noexcept;
	public:
		inline const _Char_t& operator[] (const size_t i) const;
		inline		 _Char_t& operator[] (const size_t i);
		inline size_t size() const noexcept;
	};

	bool operator==	(const String&, const String&);
	bool operator!=	(const String&, const String&);
	bool operator<	(const String&, const String&);
	bool operator>	(const String&, const String&);
	bool operator<=	(const String&, const String&);
	bool operator>=	(const String&, const String&);

	String operator+(const String&, const String&);
}
#endif // !_ZYMOVETS01_STRING_