// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

namespace ccli {
    struct cliArg {
        const char* shortArg;
        const char* longArg;
    };
    bool hasCliArg(int argc, char* argv[], cliArg argument);
}
