#include <iostream>
#include <windows.h>
#include "../globalHeaders/menu_functions.h"
#include "../globalHeaders/timer.h"
#include "../globalHeaders/items.h"

void getCursorPosition();

void gamePhase1();

void gamePhase2();

void gamePhase3();

void keyPress(char key); // Remhove the namespace

void setCursorPositionWithErrorHandling(int x, int y);


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
    setCursorPositionWithErrorHandling(960, 540);
    for (int i = 0; i < 1; ++i) {
        // Phase 1: Pioneers and Base Construction
        // Pioneers
        // Select Soldier
        mouseDrag(993, 684, 1058, 655);
        Sleep(500);
        mouseClick();
        // Change Map
        setCursorPositionWithErrorHandling(137, 31);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        Sleep(200);
        // Send Soldier
        setCursorPositionWithErrorHandling(1410, 353);
        Sleep(500);
        rMouseClick();
        // Original Map
        keyPress('H');
        // Add Pioneers
        menu(3, 2);
        setCursorPositionWithErrorHandling(187, 550);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        Sleep(500);
        // Select Pioneers
        globe();
        // Change Map
        Sleep(500);
        setCursorPositionWithErrorHandling(137, 31);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Set Pioneer Street
        Sleep(500);
        setCursorPositionWithErrorHandling(112, 643);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // First Point
        setCursorPositionWithErrorHandling(994, 780);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Second Point
        setCursorPositionWithErrorHandling(1410, 353);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        mouseClick();
        // Original Map
        keyPress('H');
        // Building
        Sleep(5000);
        // Small House 1
        menu(1, 4);
        item('A', 1);
        setCursorPositionWithErrorHandling(954, 448);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Small House 2
        item('A', 1);
        setCursorPositionWithErrorHandling(876, 381);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Medium House 1
        item('B', 1);
        setCursorPositionWithErrorHandling(1179, 450);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Medium House 2
        item('B', 1);
        setCursorPositionWithErrorHandling(1065, 395);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Medium House 3
        item('B', 1);
        setCursorPositionWithErrorHandling(979, 262);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // First Smelter
        Sleep(500);
        menu(1, 1);
        item('B', 3);
        setCursorPositionWithErrorHandling(1196, 593);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Second Smelter
        Sleep(500);
        item('B', 3);
        setCursorPositionWithErrorHandling(1324, 541);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Third Smelter
        Sleep(500);
        item('B', 3);
        setCursorPositionWithErrorHandling(1453, 495);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // First Tower
        Sleep(500);
        menu(1, 3);
        item('A', 1);
        setCursorPositionWithErrorHandling(586, 522);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // First Toolsmith
        Sleep(500);
        menu(1, 1);
        item('B', 5);
        setCursorPositionWithErrorHandling(1204, 713);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Second Toolsmith
        menu(1, 1);
        item('B', 5);
        setCursorPositionWithErrorHandling(1332, 657);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Second Tower
        Sleep(500);
        menu(1, 3);
        item('A', 1);
        setCursorPositionWithErrorHandling(1477, 604);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        // Third Tower
        item('A', 1);
        setCursorPositionWithErrorHandling(778, 279);
        Sleep(200); // Changed from Sleep(100)
        mouseClick();
        Sleep(10000);
        // First Big House
        menu(1, 4);
        item('A', 2);
        setCursorPositionWithErrorHandling(1293, 397);
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
    setCursorPositionWithErrorHandling(137, 31);
    Sleep(500);
    mouseClick();
    // Gem Tower
    menu(1, 3);
    item('A', 1);
    setCursorPositionWithErrorHandling(1405, 343);
    Sleep(100);
    mouseClick();
    // Send Pioneers above mountain
    // Change Map
    setCursorPositionWithErrorHandling(141, 25);
    Sleep(500);
    mouseClick();
    Sleep(500);
    // Select Pioneers
    globe();
    // Move Pioneers
    setCursorPositionWithErrorHandling(1183, 91);
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
    setCursorPositionWithErrorHandling(142, 22);
    Sleep(500);
    mouseClick();
    Sleep(500);
    // Build Harbor
    menu(1, 4);
    item('B', 3);
    setCursorPositionWithErrorHandling(1109, 197);
    Sleep(200);
    mouseClick();
    // Select Pioneers
    globe();
    // Move Pioneers
    setCursorPositionWithErrorHandling(952, 95);
    Sleep(500);
    rMouseClick();
    // Wait for space to free to build Harbor and move Pioneers
    Sleep(23000);
    // Move Pioneers
    setCursorPositionWithErrorHandling(964, 215);
    Sleep(500);
    rMouseClick();
    // Wait for space to free to build Shipyard
    Sleep(47500);
    // Build Shipyard
    menu(1, 3);
    item('B', 4);
    setCursorPositionWithErrorHandling(964, 207);
    Sleep(200);
    mouseClick();
    // Send Pioneers to clear sea access
    globe();
    setCursorPositionWithErrorHandling(981, 156);
    Sleep(200);
    rMouseClick();
    Sleep(10500);
    setCursorPositionWithErrorHandling(983, 381);
    Sleep(200);
    rMouseClick();
}
