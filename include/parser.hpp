// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <array>

namespace cprs {
    std::string parseCommand(const std::string &input, const std::string &command);
    std::array<std::string, 2> parseCommand(const std::string &input, const std::string &command, const std::string &delimiter);
    bool isCommand(const std::string &input, const std::string &command);
}
