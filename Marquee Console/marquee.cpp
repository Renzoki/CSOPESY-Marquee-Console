#include "marquee.h"
#include "display_handler.h"
#include <chrono>
#include <iostream>

std::atomic<bool> running{ false };

Marquee::Marquee(const std::string& initial_text, int initial_speed)
    : text(initial_text), speed_ms(initial_speed), console(GetStdHandle(STD_OUTPUT_HANDLE)) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(console, &info);
    width = info.srWindow.Right - info.srWindow.Left + 1;
}

Marquee::~Marquee() {
    stop();
}

void Marquee::start() {
    if (running) return;
    running = true;
    animation_thread = std::thread(&Marquee::animate, this);
}

void Marquee::stop() {
    running = false;
    if (animation_thread.joinable()) {
        animation_thread.join();
    }
    DisplayHandler::clear_screen();
}

void Marquee::set_text(const std::string& new_text) {
    text = new_text;
}

void Marquee::set_speed(int new_speed) {
    if (new_speed > 0) speed_ms = new_speed;
}

void Marquee::animate() {
    size_t offset = 0;
    std::string padded = std::string(width, ' ') + text + std::string(width, ' ');  // Pad both sides

    while (running) {
        std::string frame = padded.substr(offset % padded.length(), width);
        DisplayHandler::set_cursor_position(0, 0);

        DWORD written;
        FillConsoleOutputCharacterA(console, ' ', width, { 0, 0 }, &written);
        WriteConsoleOutputCharacterA(console, frame.c_str(), static_cast<DWORD>(frame.length()), { 0, 0 }, &written);

        offset = (offset + 1) % (text.length() + 2 * width);

        std::this_thread::sleep_for(std::chrono::milliseconds(speed_ms));
    }
}