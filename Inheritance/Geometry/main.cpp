#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Shape
{
	std::string color;
public:
	Shape(const std::string color)
	{
		this->color = color;
	}
	virtual double area()const = 0;
	virtual double perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side > 0)this->side = side;
		else this->side = 1;
	}
	explicit Square(double side, const std::string& color = "white") :Shape(color)
	{
		set_side(side);
	}
	~Square()
	{

	}

	double area()const
	{
		return side * side;
	}
	double perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

class Rectangle

void main()
{
	setlocale(LC_ALL, "Russian");
	//Shape shape;
	Square square(5);
	cout << "Площадь:  " << square.area() << endl;
	cout << "Периметр: " << square.perimeter() << endl;
	square.draw();
}