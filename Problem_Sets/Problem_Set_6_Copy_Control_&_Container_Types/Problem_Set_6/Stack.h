#pragma once
#include "List.h"
#include <stdexcept>

template<class T>
class Stack
{
private:
	List<T> fElements;
public:

	bool isEmpty() const
	{
		return fElements.isEmpty();
	}

	int size() const
	{
		return fElements.size();
	}

	void push(const T& aItem)
	{
		fElements.push_back(aItem);
	}

	void pop()
	{
		if (size() >= 1)
		{
			fElements.remove(fElements[size() - 1]); // remove the last element
		}
	}

	const T& top() const
	{
		if (size() >= 1)
		{
			return fElements[size() - 1];
		}
		else
		{
			T* result = new T();
			return *result;
		}
	}
};