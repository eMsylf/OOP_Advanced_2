#pragma once
#include <iostream>
#include <vector>
#include <list>

template<typename T>
class CustomQueue
{
private:
	std::vector<T> queue;

public:
	CustomQueue();

	void put(T value);
	T get();
	int size();
	void print();
};

template<typename T>
inline CustomQueue<T>::CustomQueue()
{
	
}

template<typename T>
inline void CustomQueue<T>::put(T value)
{
	queue.push_back(value);
}

template<typename T>
inline T CustomQueue<T>::get()
{
	T gottenValue = queue[0];
	for (size_t i = 0; i+1 < queue.size(); i++)
	{
		queue[i] = queue[i+1];
	}
	queue.pop_back();
	return gottenValue;
}

template<typename T>
inline int CustomQueue<T>::size()
{
	int length = 0;
	for (size_t i = 0; i < queue.size(); i++)
	{
		length++;
	}
	return length;
}

template<typename T>
inline void CustomQueue<T>::print()
{
	std::cout << "==== Print Queue ====" << std::endl;
	for (size_t i = 0; i < queue.size(); i++)
	{
		std::cout << i << ": " << queue[i] << std::endl;
	}
	std::cout << "==== Queue End ====" << std::endl;
}
