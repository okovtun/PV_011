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
};
//Создавая структуру или класс мы создаем новый тип данных
//			CLASS - это тип данных
//			STRUCT- это тоже тип данных
//Объекты класса или структуры являются переменными соответствующего типа.

void function(Point* p)
{
	cout << p->get_x() << tab << p->get_y() << endl;
}

void main()
{
	setlocale(LC_ALL, "");
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