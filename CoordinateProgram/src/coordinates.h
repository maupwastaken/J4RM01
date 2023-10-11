#include "windows.h"
#include "iostream"

void getCursorPosition();

namespace coordinates {
    int counter;
    int cords[] = {0, 0};
}

void getCursorPosition() {
    POINT cursorPos;

    while (true) {
        if (GetCursorPos(&cursorPos)) {
            coordinates::cords[0] = cursorPos.x;
            coordinates::cords[1] = cursorPos.y;
            Sleep(500);
            break;
        } else {
            std::cerr << "Failed to get cursor position." << std::endl;
        }
    }
}

