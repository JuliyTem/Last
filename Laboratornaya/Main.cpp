#include "Classes and Functions.h"

int main()
{
	try
	{
		std::string str;
		std::getline(std::cin, str);

		TLex a(str);
		a.convert(str);
		a.Show();
		a.Checking();
		a.To_Polish();
		a.Count();

		return 0;
	}
	catch (int a)
	{
		if (a == -3) std::cout << "\n Nothing to count.";
		if (a == -1) std::cout << "\n Error.";
		if (a == -2) std::cout << "\n ')number' or ')(' or any without operation.";
	}
}