#include<iostream>
using namespace std;

//Объектно-Ориентированное программирование (ООП)
//на языке C++
//(членов - members)

#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//			Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Methods
	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
};
//Создавая структуру или класс мы создаем новый тип данных
//			CLASS - это тип данных
//			STRUCT- это тоже тип данных
//Объекты класса или структуры являются переменными соответствующего типа.

void function(Point* p)
{
	cout << p->get_x() << tab << p->get_y() << endl;
}

//#define INTRO

void main()
{
	setlocale(LC_ALL, "");
#ifdef INTRO
	//type name;
	int a;	//Объявляем переменную 'a' типа 'int' 
	Point A;//Объявляем переменную 'A' типа 'Point'
			//Создаем объект 'A' структуры 'Point'
			//Создаем экземпляр 'A' структуры 'Point'
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;

	Point* pA = &A;	//pA - pointer to 'A'
	cout << pA->get_x() << tab << pA->get_y() << endl;
	//cout << (*pA).x << tab << (*pA).y << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(pA) << endl;

	{
		//Безымяная область видимости внутри функции main().
		//Class obj;
	}
	//Здесь объекта obj уже не будет  
#endif // INTRO

	Point A;	//Default constructor
	A.print();
	//Single argument constructor
	Point B(2, 3);
	B.print();
}

/*
-------------------------------------------------
. или ->
.  - Оператор прямого доступа (Point operator) для доступа к полям по имени объекта.
-> - Оператор косвенного доступа (Arrow operator) для доступа к полям по адресу объекта.
this - Указатель на объект для которого вызывается метод.
-------------------------------------------------
*/

/*
1. Encapsulation;
	Модификаторы доступа:
		private:	закрытые поля, доступные только внутри класса.
		public:
		protected:
	get/set-методы:
	get (взять) - дают доступ на чтение
	set (задать, установить) - дают доступ на запись
2. Inheritance;
3. Polymorphism;
*/

/*
	Constructor - это метод, который создает объект, а именно выделяет память под объект, и инициализирует его поля;
	Destructor  - это метод, который уничтожает объект по истечении его времени жизни;
	~ - tilda
	operator = ;

	Default constructor - это конструктор, который может быть вызван без параметров.
	Это иожет быть конструктор без параметров, или же конструктор с параметрами,
	каждый параметр которого имеет значение по умолчанию.
*/