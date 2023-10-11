#include <iostream>
#include <windows.h>
#include "../globalHeaders/menu_functions.h"
#include "../globalHeaders/timer.h"
#include "../globalHeaders/items.h"

void getCursorPosition();

void gamePhase1();

void keyPress(char key); // Remove the namespace

Timer timer;

namespace cursor {
    int x;
    int y;
}

int main() {
    Sleep(1000);
    timer.start();
    gamePhase1();
    return 0;
}

void getCursorPosition() {
    POINT cursorPos;

    while (true) {
        if (GetCursorPos(&cursorPos)) {
            int x = cursorPos.x;
            int y = cursorPos.y;

            std::cout << "Current mouse cursor position: X = " << x << ", Y = " << y << std::endl;
            Sleep(500);
        } else {
            std::cerr << "Failed to get cursor position." << std::endl;
        }
    }
}

// Function definition
void keyPress(char key) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    // Press the specified key
    input.ki.wVk = key;
    input.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &input, sizeof(INPUT));

    // Release the specified key
    input.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &input, sizeof(INPUT));
}

void gamePhase1() {
    Sleep(1000);
    // Starting by centering cursor for a Full HD Display
    SetCursorPos(960, 540);
    for (int i = 0; i < 1; ++i) {

    }
}