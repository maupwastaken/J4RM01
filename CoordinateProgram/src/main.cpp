#include <iostream>
#include <fstream>
#include <windows.h>
#include "coordinates.h"
#include <thread>
#include <atomic>
#include <chrono>
#include <iomanip>

std::atomic<bool> stopRequested(false);

bool isControlPressed() {
    return GetAsyncKeyState(VK_CONTROL) & 0x8000;
}

std::string getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H-%M-%S");
    return ss.str();
}

void monitorKeys() {
    std::string filename = "C:\\Users\\colin\\CLionProjects\\untitled2\\" + getCurrentDateTime() + ".txt";
    std::ofstream outputFile(filename, std::ios::app);
    auto lastWriteTime = std::chrono::high_resolution_clock::now();
    bool shiftPressed = false;

    while (!stopRequested) {
        if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            // The Shift key is pressed
            shiftPressed = true;
        } else {
            shiftPressed = false;
        }

        if (shiftPressed) {
            // The Shift key is pressed
            coordinates::counter++;
            auto currentTime = std::chrono::high_resolution_clock::now();
            if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWriteTime).count() >= 500) {
                // It has been 500ms since the last write and the cursor position has changed
                std::string textToWrite = "#" + std::to_string(coordinates::counter) +
                                          " X: " + std::to_string(coordinates::cords[0]) +
                                          " Y: " + std::to_string(coordinates::cords[1]);
                outputFile << textToWrite << std::endl;
                outputFile.flush();  // Flush the stream to ensure data is written immediately
                std::cout << "Data written to file: " << textToWrite << std::endl; // Log to console
                lastWriteTime = currentTime;
            }
        }

        if (isControlPressed()) {
            // The Control key is pressed
            stopRequested = true;
            std::cout << "Control key pressed. Stopping the program." << std::endl; // Log to console
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    outputFile.close();  // Close the file when done
    std::cout << "File closed. Program completed." << std::endl; // Log to console
}

void updateCursorPosition() {
    auto lastCursorPosition = coordinates::cords;

    while (!stopRequested) {
        getCursorPosition(); // Continuously update the cursor position
        // No sleep here, continuous checking

        // Check if the cursor position has changed
        if (coordinates::cords[0] != lastCursorPosition[0] || coordinates::cords[1] != lastCursorPosition[1]) {
            lastCursorPosition = coordinates::cords;
        }
    }
}

int main() {
    std::thread keyThread(monitorKeys);
    std::thread cursorThread(updateCursorPosition);

    keyThread.join();
    cursorThread.join();

    std::cout << "Cords have been written to the file." << std::endl; // Log to console

    return 0;
}


