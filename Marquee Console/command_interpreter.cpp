#include "command_interpreter.h"
#include <iostream>
#include <sstream>

CommandInterpreter::CommandInterpreter(Marquee& m) : marquee(m) {}

void CommandInterpreter::process(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    if (cmd == "help") {
        show_help();
    }
    else if (cmd == "start_marquee") {
        marquee.start();
        std::cout << "Marquee started!" << std::endl;
    }
    else if (cmd == "stop_marquee") {
        marquee.stop();
        std::cout << "Marquee stopped!" << std::endl;
    }
    else if (cmd == "set_text") {
        std::string new_text;
        std::getline(iss, new_text);
        if (!new_text.empty() && new_text[0] == ' ') new_text = new_text.substr(1);
        if (!new_text.empty()) {
            marquee.set_text(new_text);
            std::cout << "Text set to: " << new_text << std::endl;
        }
        else {
            std::cout << "Usage: set_text <text>" << std::endl;
        }
    }
    else if (cmd == "set_speed") {
        int speed;
        iss >> speed;
        if (speed > 0) {
            marquee.set_speed(speed);
            std::cout << "Speed set to: " << speed << "ms" << std::endl;
        }
        else {
            std::cout << "Speed must be positive number" << std::endl;
        }
    }
    else if (cmd != "exit") {
        std::cout << "Unknown command. Type 'help'." << std::endl;
    }
}

void CommandInterpreter::show_help() {
    std::cout << "Commands:" << std::endl;
    std::cout << "  help - Display this help" << std::endl;
    std::cout << "  start_marquee - Start the marquee" << std::endl;
    std::cout << "  stop_marquee - Stop the marquee" << std::endl;
    std::cout << "  set_text <text> - Set marquee text" << std::endl;
    std::cout << "  set_speed <ms> - Set speed in ms" << std::endl;
    std::cout << "  exit - Terminate console" << std::endl;
}