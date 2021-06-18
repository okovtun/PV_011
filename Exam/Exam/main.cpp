#include<iostream>
using namespace std;

#define tab "\t"

void Fibonacci(int n, int a = 0, int b = 1)
{
	if (a > n)return;
	cout << a << tab;
	Fibonacci(n, b, a + b);
}

class Fibonacci
{
	static void Print(int n, int a, int b)
	{
		if (a > n)return;
		cout << a << tab;
		Print(n, b, a + b);
	}
public:
	static void Print(int n)
	{
		Print(n, 0, 1);
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите число: "; cin >> n;
	//Fibonacci(n, 50, 60);
	Fibonacci::Print(n);
}