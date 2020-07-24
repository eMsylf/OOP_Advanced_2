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
		queue[0] = queue[1];
	}
	queue.pop_back();
	return gottenValue;
}

template<typename T>
inline int CustomQueue<T>::size()
{
	return 0;
}
