#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream

int main() {
	std::ostringstream oss;
	oss << "one: " << 1;
	std::string s = oss.str();
	std::cout << s << '\n';
	return 0;
}