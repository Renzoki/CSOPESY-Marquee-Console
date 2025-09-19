#include "config.h"
#include <iostream>
#include <string>
#include <atomic>
#include "keyboard_handler.h"
#include "marquee.h"
#include "command_interpreter.h"
#include "display_handler.h"

int main() {
    DisplayHandler::clear_screen();
    std::cout << PROJECT_NAME << " - Type 'help' for commands." << std::endl << std::endl;

    Marquee marquee;
    CommandInterpreter interpreter(marquee);

    while (true) {
        std::cout << "> ";
        std::string input = KeyboardHandler::get_line();
        if (input == "exit") break;
        interpreter.process(input);
    }

    return 0;
}