#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
	for (int x = 0; x < 10000; ++x)
	cout << sin(x) << endl;

	return 0;
}
// -1 < sin(x) < 1