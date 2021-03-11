#include <iostream>
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<> die(1, 10000);

	for (int count = 1; count <= 10000; ++count)
	{
		std::cout << die(g) << "\t";

	}
	return 0;
}