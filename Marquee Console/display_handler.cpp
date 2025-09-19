#include "display_handler.h"

void DisplayHandler::clear_screen() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(console, &info);
    DWORD size = info.dwSize.X * info.dwSize.Y;
    FillConsoleOutputCharacter(console, ' ', size, coord, &written);
    SetConsoleCursorPosition(console, coord);
}

void DisplayHandler::set_cursor_position(short x, short y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

int DisplayHandler::get_console_width() {
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.srWindow.Right - info.srWindow.Left + 1;
}