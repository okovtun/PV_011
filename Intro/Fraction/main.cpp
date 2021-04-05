#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "DefaultConstructor:\t" << this << endl;
#endif // DEBUG

	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "SingleArgumentConstructor:" << this << endl;
#endif // DEBUG

	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
#ifdef DEBUG
		cout << "Constructor:\t\t" << this << endl;
#endif // DEBUG

	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
#ifdef DEBUG
		cout << "Constructor:\t" << this << endl;
#endif // DEBUG

	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "CopyConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Fraction()
	{
#ifdef DEBUG
		cout << "Destructor:\t" << this << endl;
#endif // DEBUG

	}

	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG

		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		int a = 2;
		int b = 3;
		a = a * b;
		return *this = *this*other;
	}
	Fraction operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	/*Fraction operator*(const Fraction& other)const
	{
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		return Fraction
		(
			left.numerator*right.numerator,
			left.denominator*right.denominator
		);
	}*/

	//			Methods:
	Fraction to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
		/*Fraction copy = *this;
		copy.integer += copy.numerator / copy.denominator;
		copy.numerator %= copy.denominator;
		return copy;*/
	}
	Fraction to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
		/*Fraction copy = *this;
		copy.numerator += copy.integer* copy.denominator;
		copy.integer = 0;
		return copy;*/
	}
	Fraction& reduce()
	{
		if (numerator == 0)return *this;
		//https://www.webmath.ru/poleznoe/formules_12_7.php
		int more, less, rest;
		//1) Определяем кто больше, числитель или знаменатель
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		//2) Вычисляем наибольший общий делитель (НОД - GCD):
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//Greatest Common Divisor - Наибольший общий делитель
		//3) Сокращаем дробь:
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);//Функция swap меняет местами две переменные
		return inverted;
	}
	void print()const
	{
		cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator
	(
		left.get_numerator()*right.get_denominator() +
		right.get_numerator()*left.get_denominator()
	);
	result.set_denominator(left.get_denominator()*right.get_denominator());
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator()*right.get_denominator() - right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	{
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	}.to_proper();*/
	return left * right.inverted();
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}

#define delimiter "\n--------------------------------------------\n"
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;	//Default constructor
	A.print();
	cout << A << endl;
	double b = 5;
	cout << b << endl;
	Fraction B = 5;
	B.print();
	cout << B << endl;
	Fraction C(1, 2);
	C.print();
	cout << C << endl;
	Fraction D(3, 4, 5);
	D.print();
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS
	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	cout << A << endl;
	cout << B << endl;
	cout << delimiter << endl;
	Fraction C = A * B;
	cout << delimiter << endl;
	cout << C << endl;
	cout << delimiter << endl;
	cout << A << endl;
	cout << B << endl;
	/*cout << delimiter << endl;
	C = A - B;
	cout << delimiter << endl;
	cout << C << endl;*/

	cout << A / B << endl;
#endif // ARITHMETICAL_OPERATORS

	double a = 2;
	double b = 3;
	a *= 3;
	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	cout << A << endl;
	cout << B << endl;
	A *= B;
	cout << A << endl;
	cout << delimiter << endl;
	A /= B;
	cout << delimiter << endl;
	cout << A << endl;
	cout << A - A << endl;
}