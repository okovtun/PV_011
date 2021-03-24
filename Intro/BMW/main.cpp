#include<iostream>
using namespace std;

class Car
{
	char* model;	//Модель автомобиля
	char* color;	//Цвет
	unsigned int power;	//Мощность 
	unsigned int max_speed;
	double price;
public:
	const char* get_model()const
	{
		return model;
	}
	const char* get_color()const
	{
		return color;
	}
	unsigned int get_power()const
	{
		return power;
	}
	unsigned int get_max_speed()const
	{
		return max_speed;
	}
	double get_price()const
	{
		return price;
	}
	void set_price(double price)
	{
		if (price >= 40000 && price <= 70000)
		{
			this->price = price;
		}
		else
		{
			this->price = 50000;
		}
	}

	//			Constructors:
	Car()
	{
		this->model = new char[20]{};
		strcpy(model, "BMW x1");
		this->color = new char[20]{};
		strcpy(color, "white");
		this->power = 100;
		this->max_speed = 200;
		this->price = 40000;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Car(const char* model, const char* color, unsigned int power, unsigned int max_speed, double price)
	{
		this->model = new char[strlen(model) + 1]{};
		this->color = new char[strlen(color) + 1]{};
		strcpy(this->model, model);
		strcpy(this->color, color);
		this->power = power;
		this->max_speed = max_speed;
		this->set_price(price);
		cout << "Constructor:\t\t" << this << endl;
	}
	~Car()
	{
		delete[] this->model;
		delete[] this->color;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Methods
	void info()const
	{
		cout << "Model:\t" << model << endl;
		cout << "Color:\t" << color << endl;
		cout << "Power:\t" << power << " h/p" << endl;
		cout << "Max speed:" << max_speed << " km/h" << endl;
		cout << "Price:\t" << price << " $\n";
	}
};
#define delimiter "\n-----------------------------------------\n"
void main()
{
	setlocale(LC_ALL, "");
	Car car1;	//Default constructor
	car1.info();
	cout << delimiter << endl;
	Car car2("BMW x2", "Black", 250, 230, 60000);
	car2.info();
	cout << delimiter << endl;
	Car car3;	//Default constructor
	car3.info();
}