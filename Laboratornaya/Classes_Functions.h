/*#pragma once
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>
class TLex
{
	Queue temp;
	std::string s;
public:
	TLex(std::string _s)
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
	Queue& convert(char *str)
	{
		int st = 0;
		int i = 0;
		char c;
		char op[] = "+-**//*()";

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
					temp.push(new TOperand(atoi(s.c_str))); 
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
			temp.push(new TOperand(atoi(s.c_str)));
		}
		return temp;
	}
};


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
	//virtual operator int() const = 0;

};

class TOperand: public TValue
{
	int val;
public:
	TOperand(int _val = 0) : val(_val) {}
	int GetPrior()
	{
		return -1;
	}
};

class TOperator: public TValue
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
};*/