#include "keyboard_handler.h"
#include <iostream>

std::string KeyboardHandler::get_line() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}