#ifndef _ZYMOVETS01_STRING_PRINTER_
#define _ZYMOVETS01_STRING_PRINTER_
#include "String.h"
#include <ostream>

namespace Zymovets01_String
{
	inline std::ostream& operator<< (std::ostream& o, const String& s)
	{
		for (size_t i = 0u; i < s.size(); ++i)
		{
			o << s[i];
		}

		return o;
	}
}

#endif // !_ZYMOVETS01_STRING_PRINTER_