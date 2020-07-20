#define _CRT_SECURE_NO_WARNINGS
#include "ThreadsTutorial.h"

int ThreadsTutorial::GetRandom(int max)
{
    srand(time(NULL));
    return rand() % max;
}

void ThreadsTutorial::ExecuteThread(int id)
{
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);

    std::cout << "Thread: " << id << " Sleep Time: " << std::ctime(&sleepTime) << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    std::cout << "Thread: " << id << " Sleep Time: " << std::ctime(&sleepTime) << std::endl;
}
