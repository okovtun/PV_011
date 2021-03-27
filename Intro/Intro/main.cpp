#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
	/*Point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
		//Конструктор с одним параметром отвечает за преобразование типов.
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		//other - это другой объект. 
		//Это объект, точную копию которого мы создаем
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
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
void function(Point obj)
{
	cout << obj.get_x() << tab << obj.get_y() << endl;
}

//#define INTRO
//#define CONSTRUCTORS_CHECK

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

#ifdef CONSTRUCTORS_CHECK
	int a;
	Point A;	//Default constructor
	A.print();
	//Single argument constructor
	Point B(2, 3);
	B.print();

	Point C = 5;//Single argument constructor
	C.print();
	Point D(8);	//Single argument constructor
	D.print();
	int b(3);//Якобы для типа 'int' вызывается конструктор с одним параметром
	cout << int() << endl;	//Якобы, вызывается конструктор по умолчанию для типа 'int'
							//и возвращает значение по умолчанию для типа 'int'
							//так можно получить значение по усмолчанию для любого типа.
	Point E{ 13 };//Single argument constructor
	E.print();
	int c{ 5 };
	cout << c << endl;
	cout << int{} << endl;	//Значение по умолчанию для 'int'

	Point F = B;	//CopyConstructor;
	F.print();
	Point G;	//Default constructor
	G = F;	//CopyAssignment (operator=)    
#endif // CONSTRUCTORS_CHECK

	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point();
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