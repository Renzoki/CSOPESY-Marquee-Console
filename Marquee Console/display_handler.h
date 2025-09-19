#pragma once
#include <windows.h>

class DisplayHandler {
public:
    static void clear_screen();
    static void set_cursor_position(short x, short y);
    static int get_console_width();
};