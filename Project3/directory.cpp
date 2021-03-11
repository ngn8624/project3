#include <filesystem> //c+17 
#include <iostream>

namespace fs = std::filesystem;

int main()
{
	fs::path p("./a/c");
	std::cout << p << std::boolalpha << fs::exists(p) << std::endl;

	fs::create_directory("./a/c");
}
