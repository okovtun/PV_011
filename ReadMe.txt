https://github.com/okovtun/PV_011.git
https://www.youtube.com/watch?v=zMb82o-Ii-A&list=PLeqyOOqxeiIMwmLcO3eRNlHpInInqbfv1&index=1

////////////////////////////////////////////////////////////////////////////
///////////////					  UML						////////////////
////////////////////////////////////////////////////////////////////////////

https://www.yworks.com/products/yed

TODO:
1. В классе Car индикатор LOW FUEL подсветить красным цветом;
2. По нажатии на клавишу s машина должна тормозить;
https://github.com/okovtun/PS_VS_PU_35/blob/driving/Car/Car/main.cpp

DONE:
1. В класс Car добавить метод control(), который позволит управлять машиной;
2. В методе control() обеспечить запуск и остановку двигателя;
3. При запуске и холостом ходе двигателя обеспечить минимальный расход топлива;

DONE:
1. Установить программу: https://www.visual-paradigm.com/download/community.jsp
2. Ознакомиться с задачей: https://www.codewars.com/kata/578b4f9b7c77f535fc00002f
3. Нарисовать задачу в прогрмме;
4. По нарисованной диаграмме написать C++ код;
5. Прислать ссылку на репозиторий с диагрммой и кодом.

TOREAD:
http://cplusplus.com/reference/regex/		Regular expressions
http://cplusplus.com/doc/tutorial/classes2/	MoveMethods
http://cplusplus.com/doc/tutorial/classes/	UNIFORM INITIALIZATION

https://www.youtube.com/watch?v=lMGo-9tKb90

////////////////////////////////////////////////////////////////////////////
///////////////					  Files						////////////////
////////////////////////////////////////////////////////////////////////////

TODO:
1. В файле https://github.com/okovtun/PV_011/blob/master/STL/Files/Task/201%20RAW.txt 
   поменять местами столбики с IP-адресом и MAC-адресом;
2. Из тогоже файла сделать файл вида:
   https://github.com/okovtun/PV_011/blob/master/STL/Files/Task/201.dhcpd

////////////////////////////////////////////////////////////////////////////
///////////////						STL						////////////////
////////////////////////////////////////////////////////////////////////////

TOREAD:
http://cplusplus.com/reference/stl/

TODO:
Решить последнюю задачу (на Бинарное дерево): https://github.com/okovtun/PV_011/blob/master/STL/Task/DZ_ST_C%2B%2B_05.pdf

DONE:
1. Вызвать метод erase() для Вектора;		DONE
2. Написать функцию reverse_print_vector(), которая выводит вектор в обратном направлении; DONE
3. Создать объект list, и вставить в него значение по указанному индексу: DONE
   http://cplusplus.com/reference/list/list/;

////////////////////////////////////////////////////////////////////////////
///////////////				  DATA CONTAINERS				////////////////
////////////////////////////////////////////////////////////////////////////

//////////////////////			BinaryTree			////////////////////////

TODO:
1. Написать метод avg(), который возвращает среднее ариметическое элементов дерева;	DONE
2. Написать метод erase(), который удаляет заданное значение из дерева;
3. Обспечить вызов методов из функции main() без передачи в них корня дерева;		DONE

//////////////////////		BidirectionalList		////////////////////////

TODO:
В классе List реализовать класс ReverseIterator, для обращения к элементам списка 
в обратном порядке (от Хвоста до Головы), а также добавить методы rbegin() и rend(),
которые возвращают ReverseIterator.

DONE:
1. Оптимизировать методы добавления элентов в список, а именно, саму процедуру добавления		DONE
	можно описать одним выражением;
2. Написать конструктор, который может создать список заданного размера и перегрузить оператор [];
3. CopyMethods;			DONE
4. MoveMethods;			DONE

/////////////////////////		ForwardList		////////////////////////////

DONE:
1. Сделать обращение к элементам списка через []	DONE
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << list[i] << tab;
	}
2. Выражение Temp = Temp->pNext заменить на Temp++	DONE
3. Этот проверочный код должен заработать:
	ForwardList list = { 3, 5, 8, 13, 21 };
	for(int i:list)
	{
		cout << i << tab;
	}
	cout << endl;

DONE:
В класс ForwardList добавить методы:
1. CopyMethods;		DONE
2. MoveMethods;		DONE
3. Operator+ который выполняет конкатенацию двух списков;	DONE
4. Hardcore: этот проверочный код должен заработать:	DONE
	ForwardList list = { 3, 5, 8, 13, 21 };	DONE
	list.print();
	

----------------------------------------------------------------------
	void erase(int index);				DONE

	void push_back(int Data);			DONE
	void insert(int index, int Data);	DONE



////////////////////////////////////////////////////////////////////////////
///////////////			INHERITANCE & POLYMORPHISM			////////////////
////////////////////////////////////////////////////////////////////////////

DONE:
В проект Academy добавить:
1. Класс Teacher;
2. Класс Graduate - Дипломник;
Для каждого класса написать проверочный код.

DONE:
В ветке separated разделить класс Fraction на файлы.

DONE:
1. В классе String  перегрузить оператор [], и с его помощью упростить оператор +;
2. Перегрузить оператор +=;

DONE:
Реализовать класс Fraction, описывающий простую дробь. 1/2; 2(3/4)
1. В классе реализовать все обязательные методы;			TODO:CopyAssignment
2. Реализовать методы:
	- void to_proper();	//преобразует дробь в правильную - числитель < знаменателя		DONE
	- void to_improper();//преобразует дробь в неправильную - числитель > знаменателя	DONE
	- void reduce();	//Сокращает дробь	https://www.webmath.ru/poleznoe/formules_12_7.php
3. Перегрузить арифметические операторы: +, -, *, /;		DONE
4. Перегрузить составные присваивания: +=, -=, *=, /=;		DONE
5. Increment/Decrement (++/--);								DONE
6. Перегрузить операторы сравнения: ==, !=, >, <, >=, <=;

http://cplusplus.com/doc/tutorial/typecasting/

DONE:
0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. В классе Point реализовать МЕТОД ??? distance(???), 
   который вычисляет расстояние до указанной точки;
2. Реализовать ФУНКЦИЮ ??? distance(???), которая 
   вычисляет расстояние между двумя точками;