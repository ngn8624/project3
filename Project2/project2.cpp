#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream out("test.csv");

	std::string s;
	if (out.is_open())
	{
		out << "sir, CTO, your best";
	}

	return 0;
}