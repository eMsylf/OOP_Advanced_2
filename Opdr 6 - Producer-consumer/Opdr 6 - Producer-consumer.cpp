// Opdr 6 - Producer-consumer
// Example code provided by Edwin van Ouwerkerk Moria, modified by Bob Jeltes

#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>

int counter = 0;
int goodsProduced = 0;
int goodsConsumed = 0;
int loopCounter = 0;

int productionIterations = 2000000;
bool done = false;
std::queue<int> goods;

std::condition_variable cv;
std::mutex mtx;

void producer() {
    for (int i = 0; i < productionIterations; ++i) {
        std::lock_guard<std::mutex> lck(mtx);
        goods.push(i);
        counter++;
        loopCounter++;
        goodsProduced++;
        cv.notify_one();
    }
    done = true;
}

void consumer() {
    while (!done) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [] {return counter > 0; });
        while (!goods.empty()) {
            goods.pop();
            counter--;
            loopCounter++;
            goodsConsumed++;
        }
        lck.unlock();
        cv.notify_one();
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);
    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << std::endl
        << "Goods queue size: " << goods.size() << std::endl
        << "Loops completed: " << loopCounter << " out of the target " << productionIterations * 2 << std::endl
        << "Goods produced/consumed: " << goodsProduced << " / " << goodsConsumed << std::endl;

}
