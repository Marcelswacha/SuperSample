#include <thread>
#include <iostream>
#include "utility/hello.h"

int main(int argc, char** argv)
{

	std::thread t1([&]{
		std::cout << "Sample" << std::endl; 
		printSample();
	});

	t1.join();

	return 0;
}
