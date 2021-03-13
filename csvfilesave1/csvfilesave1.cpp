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
#include <ctime>
#include <future>

namespace fs = std::filesystem;

//generate vector && Sin
void Test(std::vector<float>& v, int nvectorCount)
{
	for (int x = 0; x < nvectorCount; ++x)
	{
		//std::random_device rd; //random device - suffle
		//std::mt19937 g(rd());
		//std::shuffle(v.begin(), v.end(), g);
		v.push_back(float(sin(x))); // making sin(x) 
		std::cout << v[x] << std::endl;
	}
}
//time 생성 // 1) time : how to input time to path???
std::string Time()
{
	time_t Now = time(NULL); // get time now
	struct tm timeinfo;
	char time[255];
	localtime_s(&timeinfo, &Now); // struct connect time
	strftime(time, 255, "%Y:%m:%d:%H:%M:%S", &timeinfo); // datename? // max_data // expression // struct
	return std::string(time);
}
//Create Directory
std::string createDirectory()
{
	std::string path = "D:/data/"; //1)!! yyyymmddhhMMss_mmmuuunnn append

	fs::path p(path);

	if (!fs::exists(p))
	{
		if (fs::create_directory(path))
			std::cout << "Created a directory\n";
		else
		{
			throw;
			std::cerr << "Failed to create a directory\n";
		}
	}
	else
		std::cout << "a directory already exists";
	return path;
}

//Create csvfile
int createCSVFile(std::vector<float> v, std::string path, std::string filename)
{
	std::ofstream out(path + filename);
	//std::string s;
	if (out.is_open()) //2) vector : how to input vector to string ???
	{
		out << v[0];
		out.close();
	}
	else std::cout << "unable to open file";
	return 0;
}

//Create Random
//int createRandom()
//{
//	std::random_device rd;
//	std::mt19937 g(rd());
//	std::uniform_int_distribution<> die(1, 10000);
//
//	for (int count = 1; count <= 10000; ++count)
//	{
//		std::cout << die(g) << "\t";
//
//	}
//	return 0;
//}

//Create Vector
//int createVector()
//{
//	std::vector<float> v; //vector
//	for (int i = 0; i < 10000; ++i)
//		v.push_back(float(i));
//	for (int i = 0; i < v.size(); ++i)
//		std::cout << v[i] << std::endl;
//
//	return 0;
//}

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
	std::cout << "vector<float> " << nvectorCount << "개 파일 " << nfileCount << "개씩" << std::endl;
	std::vector<float> v;

	auto start = std::chrono::high_resolution_clock::now();		// chronometry
	Test(v, nvectorCount);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dur = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
	std::cout << "vector 생성시간" << dur.count() << "ns" << std::endl;


	//디렉토리 생성
	std::string path = createDirectory();


	///////////////example
	std::string filename = "sync0000.csv";
	createCSVFile(v, path, filename);
	/////////////////////

	//3) making file in difference type
	auto start1 = std::chrono::high_resolution_clock::now();
	//!!동기 파일생성
	/*for (int i = 0; i < std::stoi(Size); i++) {
		futures.push_back(std::async(std::launch::async, []() {

			WriteToFile_Async(FileMutex, File, "a");

			}));*/
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::cout << "sync 파일 저장시간" << std::chrono::duration_cast<std::chrono::nanoseconds>(finish1 - start1).count() << "ns" << std::endl;

	auto start2 = std::chrono::high_resolution_clock::now();
	//!! thread 파일생성
	auto finish2 = std::chrono::high_resolution_clock::now();
	std::cout << "thread 파일 저장시간" << std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2).count() << "ns" << std::endl;

	auto start3 = std::chrono::high_resolution_clock::now();
	//!! thread 파일생성
	auto finish3 = std::chrono::high_resolution_clock::now();
	std::cout << "async 파일 저장시간" << std::chrono::duration_cast<std::chrono::nanoseconds>(finish3 - start3).count() << "ns" << std::endl;

	return 0;
}