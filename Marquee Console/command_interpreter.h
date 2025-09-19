#pragma once
#include <string>
#include "marquee.h"

class CommandInterpreter {
private:
    Marquee& marquee;
    void show_help();

public:
    CommandInterpreter(Marquee& m);
    void process(const std::string& command);
};