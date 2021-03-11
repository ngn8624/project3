#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<float> v; //vector
	for (int i = 0; i < 10000; ++i)
		v.push_back(i);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	return 0;
}
