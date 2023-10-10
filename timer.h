#include <chrono>
#include <thread>

class Timer {
public:
    Timer() : isRunning(false) {}

    void start() {
        isRunning = true;
        startTime = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        isRunning = false;
        endTime = std::chrono::high_resolution_clock::now();
    }

    bool isElapsed(int seconds) const {
        if (!isRunning) {
            return false;
        }
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
        return elapsed >= seconds;
    }

    int getElapsedSeconds() const {
        if (!isRunning) {
            return 0;
        }
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
        return elapsed;
    }

private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
    bool isRunning;
};

