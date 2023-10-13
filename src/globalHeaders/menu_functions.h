#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
// Function declaration

int Home;
int nav;
char column;

void mouseScroll(int scrolls);
void menu(int Home, int nav);

void home();

void navigationMenu(int nav);

void item(char column, int row);

void mouseClick();

void rMouseClick();

void mouseDrag(int x1, int y1, int x2, int y2);

void pressKey(int key, int amount, int delay);

void place();

namespace menuvars {
    int xHome1 = 35;
    int xHome2 = 107;
    int xHome3 = 177;
    int yHome = 252;
    int xNav1 = 28;
    int xNav2 = 82;
    int xNav3 = 131;
    int xNav4 = 181;
    int yNav = 309;
    int Row1 = 352;
    int Row2 = 423;
    int Row3 = 492;
    int Row4 = 552;
    int Row5 = 617;
    int Row6 = 671;
    int A = 53;
    int B = 159;
}

void setCursorPositionWithErrorHandling(int x, int y) {
    BOOL returnValue = SetCursorPos(x, y);

    printf("INFO: setting cursor to %d, %d -> %d\n", x, y, returnValue);

    if (returnValue) {
        unsigned char errorCode = GetLastError();
        printf("ERROR: setting cursor to %d, %d failed with %d\n", x, y, errorCode);
    }
}

#include <windows.h>

void pressKey(int key, int amount, int delay = 200) {
    for (int i = 1; i < amount; i++) {
        keybd_event(key, 0, 0, 0);  // Key press
        keybd_event(key, 0, KEYEVENTF_KEYUP, 0);  // Key release
        Sleep(delay);
    }
}


void mouseClick() {
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void rMouseClick() {
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}

void mouseDrag(int x1, int y1, int x2, int y2) {
    SetCursorPos(x1, y2);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    Sleep(200);
    SetCursorPos(x2, y2);
    Sleep(200);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}


void SimulateMouseWheel(int scrollAmount) {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = 0;
    input.mi.dy = 0;
    input.mi.mouseData = scrollAmount;  // Use the provided scroll amount
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.time = 0;
    input.mi.dwExtraInfo = 0;

    SendInput(1, &input, sizeof(INPUT));
}

void item(char column, int row) {
    int yCoord;

    switch (row) {
        case 1:
            yCoord = menuvars::Row1;
            break;
        case 2:
            yCoord = menuvars::Row2;
            break;
        case 3:
            yCoord = menuvars::Row3;
            break;
        case 4:
            yCoord = menuvars::Row4;
            break;
        case 5:
            yCoord = menuvars::Row5;
            break;
        case 6:
            yCoord = menuvars::Row6;
            break;
        default:
            // Handle invalid row here
            return;
    }

    switch (column) {
        case 'A':
            SetCursorPos(menuvars::A, yCoord);
            break;
        case 'B':
            SetCursorPos(menuvars::B, yCoord);
            break;
        default:
            // Handle invalid column here
            break;
    }

    Sleep(250);
    mouseClick();
}

void menu(int home, int nav) {
    switch (home) {
        case 1: {
            SetCursorPos(menuvars::xHome1, menuvars::yHome);
            Sleep(250);
            mouseClick();
            Sleep(250);
            navigationMenu(nav);
            break;
        }
        case 2: {
            SetCursorPos(menuvars::xHome2, menuvars::yHome);
            Sleep(250);
            mouseClick();
            Sleep(250);
            navigationMenu(nav);
            break;
        }
        case 3: {
            SetCursorPos(menuvars::xHome3, menuvars::yHome);
            Sleep(250);
            mouseClick();
            Sleep(250);
            navigationMenu(nav);
            break;
        }
    }
}

void navigationMenu(int nav) {
    switch (nav) {
        case 1: {
            SetCursorPos(menuvars::xNav1, menuvars::yNav);
            Sleep(250);
            mouseClick();
            Sleep(250);
            break;
        }
        case 2: {
            SetCursorPos(menuvars::xNav2, menuvars::yNav);
            Sleep(250);
            mouseClick();
            Sleep(250);
            break;
        }
        case 3: {
            SetCursorPos(menuvars::xNav3, menuvars::yNav);
            Sleep(250);
            mouseClick();
            Sleep(250);
            break;
        }
        case 4: {
            SetCursorPos(menuvars::xNav4, menuvars::yNav);
            Sleep(250);
            mouseClick();
            Sleep(250);
            break;
        }
    }
}

void place() {

}
