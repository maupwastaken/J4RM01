#include <iostream>
#include <Windows.h>
#include "menu_Functions.h"
#include "timer.h"

void getCursorPosition();
void gamePhase1();
void gamePhase2();
void gamePhase3();
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
    //getCursorPosition();
    // gamePhase1(); // Uncomment when you want to use it
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
    for (int i = 0; i < 1 ; ++i) {
        // Phase 1: Pioneers and Base Construction
        // Pioneers
        // Select Soldier
        mouseDrag(993, 684, 1058, 655);
        Sleep(500);
        mouseClick();
        // Change Map
        SetCursorPos(137, 31);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        Sleep(200);
        // Send Soldier
        SetCursorPos(1410, 353);
        Sleep(500);
        rMouseClick();
        // Original Map
        keyPress('H');
        menu(3, 2);
        SetCursorPos(187, 550);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        Sleep(500);
        SetCursorPos(116, 542);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Change Map
        Sleep(500);
        SetCursorPos(137, 31);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Set Pioneer Street
        Sleep(500);
        SetCursorPos(112, 643);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        SetCursorPos(994, 780);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        SetCursorPos(1410, 353);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        mouseClick();
        keyPress('H');
        Sleep(5000);
        // Small House 1
        menu(1, 4);
        item('A', 1);
        SetCursorPos(954, 448);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Small House 2
        item('A', 1);
        SetCursorPos(876, 381);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Medium House 1
        item('B', 1);
        SetCursorPos(1179, 450);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Medium House 2
        item('B', 1);
        SetCursorPos(1065, 395);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Medium House 3
        item('B', 1);
        SetCursorPos(979, 262);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // First Smelter
        Sleep(500);
        menu(1, 1);
        item('B', 3);
        SetCursorPos(1196, 593);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Second Smelter
        Sleep(500);
        item('B', 3);
        SetCursorPos(1324, 541);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Third Smelter
        Sleep(500);
        item('B', 3);
        SetCursorPos(1453, 495);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // First Tower
        Sleep(500);
        menu(1, 3);
        item('A', 1);
        SetCursorPos(586, 522);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // First Toolsmith
        Sleep(500);
        menu(1, 1);
        item('B', 5);
        SetCursorPos(1204, 713);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Second Toolsmith
        menu(1, 1);
        item('B', 5);
        SetCursorPos(1332, 657);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Second Tower
        Sleep(500);
        menu(1, 3);
        item('A', 1);
        SetCursorPos(1477, 604);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Third Tower
        item('A', 1);
        SetCursorPos(778, 279);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        Sleep(10000);
        // First Big House
        menu(1, 4);
        item('A', 2);
        SetCursorPos(1293, 397);
        Sleep(200);
        mouseClick();

    }

    while (!timer.isElapsed(180)) {

    }
    gamePhase2();
}

void gamePhase2() {
    // Change Map View
    Sleep(500);
    SetCursorPos(137, 31);
    Sleep(500);
    mouseClick();
    // Gem Tower
    menu(1,3);
    item('A', 1);
    SetCursorPos(1405, 343);
    Sleep(100);
    mouseClick();
    // Send Pioneers above mountain
    SetCursorPos(141, 25);
    Sleep(500);
    mouseClick();
    Sleep(500);
    menu(3, 2);
    SetCursorPos(116, 542);
    Sleep(200); // Changed from Sleep(100)
    mouseClick();
    SetCursorPos(1183, 91);
    Sleep(500);
    rMouseClick();
    Sleep(200);
    keyPress('H');
    while (!timer.isElapsed(255)) {

    }
    gamePhase3();
}

void gamePhase3() {
    // Change Map
    SetCursorPos(142, 22);
    Sleep(500);
    mouseClick();
    Sleep(500);
    // Build Harbor
    menu(1, 4);
    item('B', 3);
    SetCursorPos(1109, 197);
    Sleep(200);
    mouseClick();
    // Select Pioneers
    Sleep(500);
    menu(3, 2);
    SetCursorPos(116, 542);
    Sleep(200); // Changed from Sleep(100)
    mouseClick();
    // Move Pioneers
    SetCursorPos(952, 95);
    Sleep(500);
    rMouseClick();
     // Wait for space to free to build Harbor and move Pioneers
    Sleep(23000);
    // Move Pioneers
    SetCursorPos(964, 215);
    Sleep(500);
    rMouseClick();
    // Wait for space to free to build Harbor
    Sleep(43000);
    Sleep(500);
    // Build Harbor
    menu(1, 3);
    item('B', 4);
    Sleep(200);
    SetCursorPos(964, 207);
    Sleep(200);
    mouseClick();

}
