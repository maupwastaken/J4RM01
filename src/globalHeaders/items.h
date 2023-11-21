#include <iostream>

void globe();

void pioneerStreet();

void moresettlers();

void lesssettlers();

void moreshovelers();

void lessshovelers();

void morebuilders();

void lessbuilders();

void globe() {
    menu(3, 2);
    SetCursorPos(116, 542);
    Sleep(200);
    mouseClick();
}



void moresettlers() {
    SetCursorPos(27, 385);
    Sleep(200);
    mouseClick();
}


void lesssettlers() {
    SetCursorPos(27, 399);
    Sleep(200);
    mouseClick();
}



void moreshovelers() {
    SetCursorPos(27, 424);
    Sleep(200);
    mouseClick();
}


void lessshovelers() {
    SetCursorPos(27, 439);
    Sleep(200);
    mouseClick();
}


void morebuilders() {
    SetCursorPos(27, 456);
    Sleep(200);
    mouseClick();
}

void lessbuilders() {
    SetCursorPos(26, 465);
    Sleep(200);
    mouseClick();
}

void pioneerStreet(int x1, int y1, int x2, int y2) {
    setCursorPositionWithErrorHandling(112, 643);
    Sleep(200);
    mouseClick();
    Sleep(200);
    setCursorPositionWithErrorHandling(x1, y1);
    Sleep(200);
    mouseClick();
    setCursorPositionWithErrorHandling(x2, y2);
    Sleep(200);
    mouseClick();
}