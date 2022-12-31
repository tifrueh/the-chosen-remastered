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

    const long unsigned int begin = string.find_first_not_of(" ");
    const long unsigned int end = string.find_last_not_of(" ");
    const long unsigned int count = end + 1 - begin;

    if (string == ""){
        return;
    }
    else if (begin == std::string::npos) {
        string = "";
        return;
    }

    string = string.substr(begin, count);
}

void cstr::wrap(std::string &string, const int &width) {
    long unsigned int pos = 0;

    while ((pos + width) < string.size()) {
        pos = string.rfind(" ", pos + width);
        string.at(pos) = '\n';
    }
}

int cstr::count_words(const std::string &string) {
    int words = 0;
    long unsigned int begin = string.find_first_not_of(" ");
    long unsigned int end = string.find_first_of(" ", begin);

    if (string == "" || begin == std::string::npos) {
        return words;
    }

    while (begin != std::string::npos) {
        words++;
        begin = string.find_first_not_of(" ", end);
        end = string.find_first_of(" ", begin);
    }

    return words;   
}

int cstr::count(const std::string &str, const char &c) {
    int count = 0;
    for (auto it = str.begin(); it != str.end(); it++) {
        if (*it == c) {
            count++;
        }
    }

    return count;
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

std::string cstr::get_first_n_words(const std::string &string, const int &n) {

    long unsigned int begin = string.find_first_not_of(" ");
    long unsigned int end = string.find_first_of(" ", begin);

    if (string == "" || begin == std::string::npos || end == std::string::npos) {
        return string;
    }
    std::string out;

    for (int i = 0; i < n; i++) {
        if (begin == std::string::npos) {
            return out;
        }
        out.append(string.substr(begin, end - begin) + " ");
        begin = string.find_first_not_of(" ", end);
        end = string.find_first_of(" ", begin);
    }

    out.pop_back();

    return out;
}
