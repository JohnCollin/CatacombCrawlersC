//
// Created by cjohnson on 7/12/20.
//

#include "Logger.h"

cccgame::LogElement cccgame::Logger::info = cccgame::LogElement("INFO", std::cout);
cccgame::LogElement cccgame::Logger::warn = cccgame::LogElement("WARN", std::cout);
cccgame::LogElement cccgame::Logger::error = cccgame::LogElement("ERROR", std::cerr);