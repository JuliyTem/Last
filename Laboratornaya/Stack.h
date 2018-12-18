#pragma once
#include <iostream>
#include <string>
//#include "Queue.h"
//#include "Classes_Functions.h"

class TValue
{
public:
	TValue() {}
	~TValue() {}
	//virtual int prior() = 0;
	//virtual int GetPrior() = 0;
	//virtual void print(std::ostream &os) = 0;
	//virtual bool operator ==(const TValue & b) { return true; };
	//friend std::ostream & operator<<(std::ostream &os, TValue &v);
	//virtual operator int() const = 0;*/

};

class TOperand : public TValue
{
	int val;
public:
	TOperand(int _val = 0) : val(_val) {}
	int GetPrior()
	{
		return -1;
	}
};

class TOperator : public TValue
{
	int prior;
	char f;
public:
	TOperator(char c)
	{
		if ((c == '(') || (c == ')'))
		{
			prior = 0;
			f = c;
		}
		if ((c == '+') || (c == '-'))
		{
			prior = 1;
			f = c;
		}
		if ((c == '*') || (c == '/'))
		{
			prior = 2;
			f = c;
		}
	}
	int GetPrior()
	{
		return prior;
	}
};

class Stack
{
	TValue **p;
	int index, size;
public:
	Stack(int _size = 0) : size(_size), index(-1)
	{
		p = new TValue*[size];
	}
	Stack(const Stack &b)
	{
		size = b.size;
		index = b.index;
		p = new TValue*[size];
		for (int i = 0; i < index + 1; i++)
		{
			p[i] = b.p[i];
		}
	}
	~Stack()
	{
		 delete[] p;
	}
	bool is_empty()
	{
		return(index == -1);
	}
	bool is_full()
	{
		return(index == size - 1);
	}
	void push(TValue* val)
	{
		if (is_full()) throw - 1;
		index++;
		p[index] = val;
	}
	TValue* pop()
	{
		if (is_empty()) throw - 1;
		index--;
		return(p[index + 1]);
	}
	Stack &operator=(const Stack &b)
	{
		if (&b == this) return *this;
		delete[]p;
		size = b.size;
		index = b.index;
		p = new TValue*[size];
		for (int i = 0; i < index + 1; i++)
		{
			p[i] = b.p[i];
		}
		return *this;
	}
	void Show()
	{
		std::cout << "\n|";
		for (int i = 0; i < index + 1; i++)
		{
			std::cout << "" << p[i];
		}
	}
};

class Queue
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
		delete[] * p;
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
};

class TLex
{
	Queue temp;
	std::string s;
public:
	TLex(std::string _s = "")
	{
		s = _s;
	};
	int pos(char *s, char c)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == c) return c;
			i++;
		}
		return -1;
	}
	Queue& convert(std::string str)
	{
		int st = 0;
		int i = 0;
		char c;
		char op[] = "+-*/()";

		while (str[i] != '\0')
		{
			c = str[i];
			i++;
			if (st == 0)
			{
				if (c == ' ') {}
				if (pos(op, c) >= 0)
				{
					temp.push(new TOperator(c));
				}
				if ((c >= '0') && (c <= '9'))
				{
					s = c;
					st = 1;
				}
			}
			if (st == 1)
			{
				if ((c >= '0') && (c <= '9'))
				{
					s += c;
				}
				if (c == ' ')
				{
					temp.push(new TOperand(atoi(s.c_str())));
					st = 0;
				}
				if (pos(op, c) >= 0)
				{
					temp.push(new TOperand(atoi(s.c_str())));
					temp.push(new TOperator(c));
					st = 0;
				}
			}
		}
		if (st == 1)
		{
			temp.push(new TOperand(atoi(s.c_str())));
		}
		return temp;
	}
};