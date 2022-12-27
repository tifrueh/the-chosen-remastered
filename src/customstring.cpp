// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <algorithm>
#include "customstring.hpp"

void cstr::to_lower(std::string &string) {
    std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}

void cstr::trim(std::string &string) {

    const int begin = string.find_first_not_of(" ");
    const int end = string.find_last_not_of(" ");
    const int count = end - begin + 1;

    if (string == "" || begin == std::string::npos){
        return;
    }

    string = string.substr(begin, count);
}

std::string cstr::int_to_string(int number, int numberOfDigits) {
    std::string sNumber = std::to_string(number);
    int numberOfZeroes = numberOfDigits - sNumber.size();

    std::reverse(sNumber.begin(), sNumber.end());

    for (int i = 0; i < numberOfZeroes; i++) {
        sNumber.append("0");
    }

    std::reverse(sNumber.begin(), sNumber.end());

    return sNumber;
}
