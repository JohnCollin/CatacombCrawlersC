//
// Created by cjohnson on 7/12/20.
//

#include <ctime>
#include <iomanip>
#include "LogElement.h"

cccgame::LogElement::LogElement(std::string logElementName, std::ostream &associativeOstream)
		: logElementName{ logElementName }, associativeOstream{ associativeOstream } {}

std::ostream &cccgame::LogElement::operator<<(const char *message)
{
	FormatTimeAndLog(message);

	return this->associativeOstream;
}

void cccgame::LogElement::FormatTimeAndLog(const char *message) const
{
	time_t currentTime = time(nullptr);
	tm currentTimeFormat = *localtime(&currentTime);

	this->associativeOstream << std::put_time(&currentTimeFormat, "[%T ");

	this->associativeOstream << this->logElementName << "] " << message;
}
