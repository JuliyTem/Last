/*#pragma once
#include <iostream>
#include "Stack.h"
#include "Classes_Functions.h"
/*class Queue
{
	int size, top, end;
	TValue **p;
public:

	Queue(int _size = 0) : size(_size), top(0), end(size - 1)
	{
		p = new TValue*[size];
	}
	Queue(const Queue &b)
	{
		size = b.size;
		top = b.top;
		end = b.end;
		p = new TValue*[size];

		int i = top;
		while (i != end + 1)
		{
			p[i] = b.p[i];
			i = (i + 1) % size;
		}
	}
	~Queue()
	{
		delete[] *p;
	}
	bool is_empty()
	{
		return((end + 1) % size == top);
	}
	bool is_full()
	{
		return((end + 2) % size == top);
	}
	void push(TValue* val)
	{
		if (is_full()) throw - 1;
		end = (end + 1) % size;
		p[end] = val;
	}
	TValue* pop()
	{
		if (is_empty()) throw - 1;
		int k = top;
		top = (top + 1) % size;
		return (p[k]);
	}
	Queue &operator=(const Queue &b)
	{
		if (&b == this) return *this;
		delete[]p;
		size = b.size;
		top = b.top;
		end = b.end;
		p = new TValue*[size];

		int i = top;
		while (i != end + 1)
		{
			p[i] = b.p[i];
			i = (i + 1) % size;
		}
		return *this;
	}
	void show()
	{
		int i = top;
		std::cout << "\n|";
		while (i != end + 1)
		{
			std::cout << p[i];
			i = (i + 1) % size;
		}

	}
};*/
