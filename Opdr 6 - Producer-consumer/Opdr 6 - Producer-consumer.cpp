#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>

int counter = 0;
bool done = false;
std::queue<int> goods;

std::condition_variable condition;
std::mutex mutex;
//std::lock_guard<std::mutex> lock;

void producer() {
    for (int i = 0; i < 500; ++i) {
        mutex.lock();
        goods.push(i);
        counter++;
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
            mutex.unlock();
        }
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    condition.notify_all();
    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter 
        << std::endl
        << "Goods queue size: " << goods.size()
        << std::endl;
}
