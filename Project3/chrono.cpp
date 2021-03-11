#include <iostream>
#include <chrono>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

void Test()
{
	for (int x = 0; x < 10000; ++x)
		cout << sin(x) << endl;
}
int main()
{
	const auto sta = std::chrono::steady_clock::now();		// chronometry
	Test();
	const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
	cout << dur.count() << endl;

	return 0;
}