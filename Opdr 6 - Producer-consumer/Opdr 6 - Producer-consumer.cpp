#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>

int counter = 0;
int loopCounter = 0;

int productionIterations = 500;
bool done = false;
std::queue<int> goods;

//std::condition_variable condition;
//std::lock_guard<std::mutex> lock;
std::mutex mutex;

void producer() {
    for (int i = 0; i < productionIterations; ++i) {
        mutex.lock();
        goods.push(i);
        counter++;
        loopCounter++;
        mutex.unlock();
    }

    done = true;
}

void consumer() {
    while (!done) {
        while (!goods.empty()) {
            mutex.lock();
            goods.pop();
            counter--;
            loopCounter++;
            mutex.unlock();
        }
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);
    producerThread.join();
    consumerThread.join();
    //producer();
    //consumer();

    std::cout << "Net: " << counter << std::endl
        << "Goods queue size: " << goods.size() << std::endl
        << "Loops: " << loopCounter << " out of the target " << productionIterations * 2 << std::endl;
}
