#include<iostream>
#include<thread>
using namespace std;
using namespace std::literals::chrono_literals;

bool stop = false;

void hello()
{
	while (!stop)
	{
		cout << "Hello";
		std::this_thread::sleep_for(1s);	//Приостанавливает выполнение кода на 1 секунду.
	}
}

void world()
{
	while (!stop)
	{
		cout << "World";
		std::this_thread::sleep_for(1s);	//Приостанавливает выполнение кода на 1 секунду.
	}
}

void main()
{
	std::thread thread_hello(hello);
	std::thread thread_world(world);
	
	std::cin.get();	//Ожидает нажатия Enter;
	stop = true;

	thread_world.join();
	thread_hello.join();
}