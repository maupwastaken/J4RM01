#include <iostream>
#include <windows.h>
#include "../globalHeaders/menu_functions.h"
#include "../globalHeaders/timer.h"
#include "../globalHeaders/items.h"

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
    return 0;
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
        menu(3, 2);
        setCursorPositionWithErrorHandling(187, 550);
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(500);

        // Select Pioneers
        globe();
        setCursorPositionWithErrorHandling(972, 572);
        rMouseClick();
        Sleep(200);
        mouseClick();

        // Building
        Sleep(500);

        // Small House 1
        menu(1, 4);
        item('A', 1);
        setCursorPositionWithErrorHandling(1193, 470);
        Sleep(200);
        mouseClick();
        Sleep(500);

        // Small House 2
        item('A', 1);
        setCursorPositionWithErrorHandling(985, 433);
        Sleep(200);
        mouseClick();
        Sleep(500);

        // Small House 3
        item('A', 1);
        setCursorPositionWithErrorHandling(1114, 399);
        Sleep(200);
        mouseClick();

        //Turn Pioneers Into Settlers
        menu(3,2);
        setCursorPositionWithErrorHandling(185, 621);
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(200);
        mouseClick();
        Sleep(500);

        // Building Medium House 1
        Sleep(1500);
        menu(1, 4);
        item('B', 1);
        Sleep(500);
        setCursorPositionWithErrorHandling(1317, 421);
        Sleep(200);
        mouseClick();

        // Changing Settlers Settings
        Sleep(3000);
        menu(3, 2);
        lesssettlers(); //-5%
        lesssettlers();
        lesssettlers();
        Sleep(200);
        morebuilders(); //+5%
        morebuilders();
        Sleep(200);
        lessshovelers(); //-5%
        lessshovelers();
        lessshovelers();
        lessshovelers();
        lessshovelers();
        Sleep(200);

        // Making Pioneers For Towers
        menu(3, 2);
        setCursorPositionWithErrorHandling(187, 550);
        Sleep(200);
        mouseClick();
        setCursorPositionWithErrorHandling(546, 553);
        Sleep(500);
        rMouseClick();
        Sleep(200);
        mouseClick();
        Sleep(500);

        menu(3, 2);
        setCursorPositionWithErrorHandling(187, 550);
        Sleep(200);
        mouseClick();
        setCursorPositionWithErrorHandling(813, 230);
        Sleep(500);
        rMouseClick();
        Sleep(200);
        mouseClick();

        menu(3, 2);
        setCursorPositionWithErrorHandling(187, 550);
        Sleep(200);
        mouseClick();
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        keybd_event(VK_LEFT,0 ,0 ,0);
        Sleep(100);
        setCursorPositionWithErrorHandling(527, 407);
        Sleep(500);
        rMouseClick();
        Sleep(200);
        mouseClick();


        //Building Medium House 2
        Sleep(10000); //Other Buildings Need Time To Finish
        keyPress('H');
        menu(1, 4);
        item('B', 1);
        Sleep(500);
        setCursorPositionWithErrorHandling(1244, 324);
        Sleep(200);
        mouseClick();

        //Building Towers
        Sleep(10000);
        menu(1, 3);
        item('A', 1);
        setCursorPositionWithErrorHandling(562, 554); //Tower Between Forest And Stone
        Sleep(200);
        mouseClick();
        Sleep(3000);
        item('A', 1);
        setCursorPositionWithErrorHandling(830, 238); //Tower Towards Forest
        Sleep(200);
        mouseClick();
        Sleep(200);
        item('A', 1);
        setCursorPositionWithErrorHandling(1510, 572); //Tower Towards Mountain
        Sleep(200);
        mouseClick();

        //Sending Pioneers For Tower-Street


        //Building Big House 1
        Sleep(3500);
        menu(1, 4);
        item('A', 2);
        setCursorPositionWithErrorHandling(1058, 350);
        Sleep(200);
        mouseClick();

    }

    while (!timer.isElapsed(180)) {

    }
    gamePhase2();
};

void gamePhase2(){

}

