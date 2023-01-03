// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>

namespace cstr {
    void to_lower(std::string &string);
    void trim(std::string &string);
    void wrap(std::string &string, const int &width);
    void capitalise(std::string &string);
    std::string capitaliseToNew(const std::string &string);
    int count_words(const std::string &string);
    int count(const std::string &str, const char &c);
    std::string int_to_string(int number, int numberOfDigits);
    std::string get_first_n_words(const std::string &string, const int &n);
}
