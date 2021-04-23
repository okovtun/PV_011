#include<iostream>
using namespace std;

class Weapon
{
public:
	virtual void damage() = 0;//Чисто виртуальный метод
};

class Firearms : public Weapon
{
	double caliber;
	int capacity;
	int distance;
};

class Pistol :Firearms
{
	string model;
public:
	void damage()
	{
		cout << "Пиу..." << endl;
	}
};

void main()
{
	//Weapon wp;
	//Firearms arm;
	Pistol de;
	de.damage();
}