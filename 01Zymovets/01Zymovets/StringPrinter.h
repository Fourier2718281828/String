#ifndef _ZYMOVETS01_STRING_PRINTER_
#define _ZYMOVETS01_STRING_PRINTER_
#include "String.h"
#include <ostream>

namespace Zymovets01_String
{
	inline std::ostream& operator<< (std::ostream& o, const String& s)
	{
		return o << static_cast<const char*>(s);
	}
}

#endif // !_ZYMOVETS01_STRING_PRINTER_