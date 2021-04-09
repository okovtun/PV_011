#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

#define DEBUG	//Отладка

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
#if defined DEBUG
		cout << "DefaultConstructor:\t" << this << endl;
#endif // DEBUG
	}
	explicit Fraction(int integer)//explicit - явный
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "SingleArgumentConstructor:" << this << endl;
#endif // DEBUG
	}
	Fraction(double decimal)
	{
		decimal += 1e-15;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;//1000000000;
		numerator = decimal * denominator;
		reduce();
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

	//			Increment/Decrement
	Fraction& operator++()	//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//			Type cast operators:
	operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
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

////////////////////////			Comparison operators			///////////////////////////

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

///////////////////////				  Stream operators				///////////////////////////

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
//#define COMPAUND_ASSIGNMENTS
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS
#define TYPE_CONVERSIONS

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

#ifdef COMPAUND_ASSIGNMENTS
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
#endif // COMPAUND_ASSIGNMENTS

#ifdef INCREMENT_CHECK
	for (double i = .3; i < 10; i++)
		cout << i << tab;
	cout << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; i++)
		cout << i << tab;
	cout << endl;
#endif // INCREMENT_CHECK

#ifdef COMPARISON_OPERATORS
	int a = 2;
	cout << a << endl;

	Fraction A(1, 2);
	Fraction B(5, 11);

	/*if (A == B)
		cout << "Дроби равны!" << endl;
	else
		cout << "Дроби разные!" << endl;*/
	cout << delimiter << endl;
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << delimiter << endl;
	//cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;

	cout << A << endl;
	cout << B << endl;
#endif // COMPARISON_OPERATORS

#ifdef TYPE_CONVERSIONS

	//int a = 43;
	////Явное преобразование - explicit conversion:
	//cout << (char)a << endl;	//C-like style
	//cout << char(a) << endl;	//Functional style
	//
	////Неявное преобразование - implicit conversion
	//double b = 3.5;
	//a + b;//Здесь переменная 'a', типа int неявно преобразуется в 'double', поскольку второй операнд '+' - double
	//cout << typeid(a + b).name() << endl;
	////..., possible loss of data
	////char ==> int
	////int  ==> double

	//int a = 2;		//No conversion
	//double b = 3;	//От меньшего к бОльшему
	//int c = 5.0;	//От бОльшего к меньшему без потери данных
	//int d = 5.2;	//От бОльшего к меньшему с потерей данных

	//char e = 43;	//От бОльшего к меньшему без потери данных
	//char f = 555;	//От бОльшего к меньшему с потерей данных
	////truncation - урезание, усечение
	//cout << f << endl;

	//Fraction A = (Fraction)5;		//From int to Fraction - Single Argument Constructor
	Fraction A(5);	//explicit Constructor можно вызвать только так, и невозможно вызвать оператором =
	cout << A << endl;
	A = (Fraction)8;	//CopyAssignment
	cout << A << endl;
	Fraction B(3, 4, 5);
	double b = B;		
	cout << b << endl;
	.3;
	double c = 2.53698798798798709218403298403284456;
	Fraction C = 2.55;
	cout << C << endl;
	cout << UINT_MAX << endl;
#endif // TYPE_CONVERSIONS

}

/*
		TYPE CAST OPERATOR SYNTAX
operator type()
{
	.....
	.....
	return ...;
}
*/