// csvfilesave.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <filesystem>
#include <iostream>
#include <math.h>
#include <random>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>      // std::ostringstream
#include <windows.h>
namespace fs = std::filesystem;

//Sin 생성
void Test(std::vector<float>& v, int nvectorCount)
{
	for (int x = 0; x < nvectorCount; ++x)
		v.push_back(float(sin(x)));
}

//Create Directory
std::string createDirectory()
{
	std::string path;
	path = "C:/aaa"; //!! D:\data\yyyymmddhhMMss_mmmuuunnn 폴더생성
	
	fs::path p(path);
	//std::cout << p << std::boolalpha << fs::exists(p) << std::endl;

	if (!fs::exists(p))
	{
		if (fs::create_directory(path))
			return path;
		else
		{
			throw;
			return "ERROR";
		}
	}
	else
		return path;
	
}

//Create csvfile
int createCSVFile(std::vector<float> v, std::string filename, std::string path)
{
	std::ofstream out(path+filename);

	std::string s;
	if (out.is_open()) //!! vector에 있는거 전부 저장
	{
		out << v[0];
	}

	return 0;
}

//Create Random
int createRandom()
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

//Create Vector
int createVector()
{
	std::vector<float> v; //vector
	for (int i = 0; i < 10000; ++i)
		v.push_back(float(i));
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << std::endl;

	return 0;
}

//ostringstream
int ostringstream() {
	std::ostringstream oss;
	oss << "one: " << 1;
	std::string s = oss.str();
	std::cout << s << '\n';
	return 0;
}

int main()
{
	//vector 생성
	const int nfileCount = 200;
	const int nvectorCount = 10000;
	std::cout << "List<float> " << nvectorCount << "개 파일 " << nfileCount << "개씩" << std::endl;
	std::vector<float> v;

	auto sta = std::chrono::steady_clock::now();		// chronometry
	Test(v, nvectorCount);
	std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
	std::cout << "list 생성시간" << dur.count() << "ns" << std::endl; //!!nano시간 측정

	
	//디렉토리 생성
	std::string path = createDirectory();

	
	///////////////example
	createCSVFile(v, path, "sync00000.csv");
	/////////////////////


	sta = std::chrono::steady_clock::now();		// chronometry
	//!!동기 파일생성
	dur = std::chrono::steady_clock::now() - sta;
	std::cout << "sync 파일 저장시간"<<dur.count()<< "ns"<< std::endl; //!!nano시간 측정

	
	sta = std::chrono::steady_clock::now();		// chronometry
	//!! thread 파일생성
	dur = std::chrono::steady_clock::now() - sta;
	std::cout << "Thread 파일 저장시간" << dur.count() << "ns" << std::endl; //!!nano시간 측정
	
	
	sta = std::chrono::steady_clock::now();		// chronometry
	//!!비동기 파일생성
	dur = std::chrono::steady_clock::now() - sta;
	std::cout << "async 파일 저장시간" << dur.count() << "ns" << std::endl; //!!nano시간 측정
}