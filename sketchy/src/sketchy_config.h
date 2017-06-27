/*
	main program definitions
*/

#ifndef __SKETCHY_CONFIG__
#define __SKETCHY_CONFIG__

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

class ConsoleLogger
{
	static void LogConsoleString(const char* aFormat, ...)
	{
		va_list lArgs;
		va_start(lArgs, aFormat);
		char lBuff[1024] = { 0 };
		sprintf(lBuff, aFormat, lArgs);
		std::wostringstream os_;
		os_ << lBuff << "\n";
		OutputDebugString(os_.str().c_str());
	}
}

#endif //__SKETCHY_CONFIG__