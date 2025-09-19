#pragma once
#include "config.h"
#include <string>
#include <atomic>
#include <thread>
#include <windows.h>

extern std::atomic<bool> running;

class Marquee {
private:
    std::string text;
    int speed_ms;
    HANDLE console;
    int width;
    std::thread animation_thread;

    void animate();

public:
    Marquee(const std::string& initial_text = DEFAULT_TEXT, int initial_speed = DEFAULT_SPEED);
    ~Marquee();
    void start();
    void stop();
    void set_text(const std::string& new_text);
    void set_speed(int new_speed);
};