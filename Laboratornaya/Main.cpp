#include "Stack.h"
//#include "Queue.h"
//#include "Classes_Functions.h"

int main()
{
	std::string str;
	std::getline(std::cin, str);

	TLex a(str);
	a.convert(str);
	
	
	return 0;
}