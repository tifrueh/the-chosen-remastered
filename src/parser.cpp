// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <array>
#include "parser.hpp"
#include "customstring.hpp"

std::string cprs::parseCommand(const std::string &input, const std::string &command) {
    long unsigned int cmdPos = input.find(command + " ");
    long unsigned int cmdEnd = cmdPos + command.size();

    if (cmdPos == std::string::npos) {
        return input;
    }

    std::string out = input.substr(cmdEnd, input.size() - cmdEnd);
    cstr::trim(out);

    return out;
}

std::array<std::string, 2> cprs::parseCommand(const std::string &input, const std::string &command, const std::string &delimiter) {
    std::array<std::string, 2> out;
    long unsigned int cmdPos = input.find(command + " ");
    long unsigned int cmdEnd = cmdPos + command.size();
    
    long unsigned int delPos = input.find(" " + delimiter + " ") + 1;
    long unsigned int delEnd = delPos + delimiter.size();

    if (cmdPos == std::string::npos) {
        out[0] = input;
        return out;
    } 
    else if (delPos == std::string::npos) {
        out[0] = input.substr(cmdEnd, input.size() - cmdEnd);
        return out;
    }

    out[0] = input.substr(cmdEnd, delPos - cmdEnd);
    cstr::trim(out[0]);

    out[1] = input.substr(delEnd, input.size() - delEnd);
    cstr::trim(out[1]);

    return out;
}

bool cprs::isCommand(const std::string &input, const std::string &command) {
    int wordsInCommand = cstr::count_words(command);
    std::string inputCommand = cstr::get_first_n_words(input, wordsInCommand);
    bool isCommand = inputCommand == command;

    return isCommand;
}
