//============================================================================
// Name        : CSC450PortfoilioMilestoneThreads.cpp
// Author      : Brandon Bacher
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mtx; // mutex for synchronization
bool threadOneFinished = false;

void countUp() {
    for (int i = 1; i <= 20; ++i) {
        mtx.lock(); // lock mutex for thread safety
        std::cout << "Count up: " << i << std::endl;
        mtx.unlock(); // Unlock mutex
    }

    threadOneFinished = true;
}

void countDown() {
    while (!threadOneFinished) { // waiting for thread to finish

    }

    for (int i = 20; i >= 0; --i) {
        mtx.lock(); // lock mutex for thread safety
        std::cout << "Count down: " << i << std::endl;
        mtx.unlock();
    }
}

int main() {
    std::thread t1(countUp);
    std::thread t2(countDown);

    t1.join();
    t2.join();

    return 0;
}
