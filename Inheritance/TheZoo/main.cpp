#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Animal
{
public:
	virtual ~Animal() {}
	virtual void sound()const = 0;	//Чисто-виртуальный метод (Pure-virtual function), 
								//благодаря которому класс является абстрактным.
};

class Cat :public Animal
{
	//Это тоже абстрактный класс, так как не реализует чисто виртуальный метод.
};

class Tiger :public Cat
{
	~Tiger()
	{

	}
	void sound()const
	{
		cout << "Ррррр" << endl;
	}
};

class HomeCat :public Cat
{
	~HomeCat()
	{

	}
	void sound()const
	{
		cout << "Мяу" << endl;
	}
};

class Dog :public Animal
{
	~Dog()
	{

	}
	void sound()const
	{
		cout << "Гав" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");

	//Animal a;
	//Cat tom;
	//Dog rax;

	//1. Generalization:
	Animal* zoo[] =
	{
		new HomeCat,
		new Dog,
		new Tiger,
		new Dog,
		new HomeCat
	};

	//2. Specialisation:
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
}