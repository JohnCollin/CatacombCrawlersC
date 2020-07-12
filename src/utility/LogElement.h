//
// Created by cjohnson on 7/12/20.
//

#ifndef CATACOMBCRAWLERSC_LOGELEMENT_H
#define CATACOMBCRAWLERSC_LOGELEMENT_H

#include <iosfwd>

namespace cccgame
{
	class LogElement
	{
	public:
		explicit LogElement(std::string logElementName, std::ostream& associativeOstream);

		std::string logElementName;
		std::ostream& associativeOstream;

		std::ostream &operator<<(const char* message);

	private:
		void FormatTimeAndLog(const char* message) const;
	};
}

#endif //CATACOMBCRAWLERSC_LOGELEMENT_H
