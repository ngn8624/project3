#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>
#include <chrono>
#include <future>
#include <thread>
#include <iterator>
#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
	ofstream outfile; //outfile
	outfile.open("data.csv", ios::in | ios::out);

	vector<float> v; //vector
	for (int i = 0; i < 10000; ++i)
		v.push_back(i);

	const auto sta = std::chrono::steady_clock::now();		// chronometry
																																																																																										
	std::random_device rd; //random
	std::mt19937 g(rd());
	std::shuffle(v.begin(), v.end(), g);

	std::ostringstream oss; //string

	if (!v.empty())
	{
		std::copy(v.begin(), v.end()-1,
			std::ostream_iterator<float>(oss, ",\n"));
		oss << v.back();
	}
	std::cout << oss.str() << std::endl;

	outfile << oss.str() << endl;
	outfile << endl;

	const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
	cout << dur.count() << endl;

	outfile.close();

	return 0;
}
// outfile - vector - random - chronometry - string 