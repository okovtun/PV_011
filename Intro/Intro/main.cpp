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
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator+=\t" << this << endl;
		return *this;
	}

	//			Increment/Decrement
	Point& operator++()//Prefix increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)//Postfix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}

	/*Point operator+(const Point& other)const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "Operator + " << this << endl;
		return result;
	}*/

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

Point operator+(const Point& left, const Point& right)
{
	Point result;	//Default construtor
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result
	(
		left.get_x() - right.get_x(), 
		left.get_y() - right.get_y()
	);
	cout << "Global minus" << endl;
	return result;
}
Point operator*(const Point& left, const Point& right)
{
	cout << "Global multiply" << endl;
	return Point
	(
		left.get_x()*right.get_x(),
		left.get_y()*right.get_y()
	);
}
Point operator/(const Point& left, const Point& right)
{
	cout << "Global divide" << endl;
	return Point
	(
		left.get_x()/right.get_x(),
		left.get_y()/right.get_y()
	);
}

ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
}

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
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS

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

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point();
#endif

	//			Operators overloading
	/*
	--------------------------------------
	operator@
	1. Перегрузить можно только существующие операторы:
		+  - перегружается;
		++ - перегружается;
		*  - перегружается;
		** - НЕ перегружается;
	2. Не все существующие операторы можно перегрузить.
	   Не перегружаются:
	   :: - Scope operator (оператор разрешения видимости);
	   ?: - Тернарный оператор;
	   .  - Point operator (оператор прямого доступа);
	   .* - 
	   #  - Preprocessor directive
	   ## - Preprocessor concatenation "Hello" + "World" = "HelloWorld"
	3. Перегруженные операторы сохраняют приоритет;
	4. Невозможно переопределить поведение операторов со встроенными типами.
	
	Операторы можно перегружать как в классе, так и за классом.
	--------------------------------------
	*/

#ifdef ARITHMETICAL_OPERATORS
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	A.print();
	B.print();
	Point C = A + B;
	C.print();
	(A - B).print();
	(A*B).print();
	(A / B).print();
	A.print();
	B.print();
#endif // ARITHMETICAL_OPERATORS

	Point A(2, 3);
	Point B(3, 4);
	A += B;	//Неявный вызов оператора
	A.print();
	A.operator+=(B);//Явный вызов оператора
	A.print();
	operator/(A, B).print();//Явный вызов глобального оператора
	A++;
	A.print();
	cout << A << endl;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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