//
// Created by cjohnson on 7/12/20.
//

#ifndef CATACOMBCRAWLERSC_LOGGER_H
#define CATACOMBCRAWLERSC_LOGGER_H

#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include "LogElement.h"

#define linfo cccgame::Logger::info
#define lwarn cccgame::Logger::warn
#define lerr cccgame::Logger::error

#define en std::endl

namespace cccgame
{
	class Logger
	{
	public:
		static LogElement info;
		static LogElement warn;
		static LogElement error;
	};
}

#endif //CATACOMBCRAWLERSC_LOGGER_H
