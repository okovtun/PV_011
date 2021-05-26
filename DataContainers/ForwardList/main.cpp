#include"Element.h"
#include"Element.cpp"
#include"Iterator.h"
#include"Iterator.cpp"
#include"ForwardList.h"
#include"ForwardList.cpp"

//#define BASE_CHECK
//#define COPY_METHODS_CHECK
//#define OPERATOR_PLUS_CHECK
#define HARDCORE

#ifdef BASE_CHECK
//#define ADDING_ELEMENTS_CHECK
//#define REMOVING_CHECK  
#endif // BASE_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	//list.print();
	cout << "List ready" << endl;

#ifdef REMOVING_CHECK
	list.pop_front();
	list.pop_back();
	list.print();
#endif // REMOVING_CHECK

	int value;
	int index;
#ifdef ADDING_ELEMENTS_CHECK
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	//list.push_back(value);
	list.insert(index, value);
	list.print();

	ForwardList list2;
	cout << "Введите размер списка: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list2.push_back(rand() % 100);
	}
	list2.print();
	list.print();
#endif // ADDING_ELEMENTS_CHECK  
#endif // BASE_CHECK

#ifdef COPY_METHODS_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
	cout << delimiter << endl;;
	//ForwardList list2 = list;	//CopyConstructor
	ForwardList list2;	//DefaultConstructor
	list2 = list;//CopyAssignment (=)
	list2.print();
#endif // COPY_METHODS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.push_back(144);

	////////////////////////////////////////////////////////////
	cout << delimiter << endl;
	ForwardList list3;	//DefaultConstructor
	list3 = list1 + list2;
	list3.print();
	cout << delimiter << endl;
	////////////////////////////////////////////////////////////
#endif // OPERATOR_PLUS_CHECK

#ifdef HARDCORE
	int arr[] = { 3, 5, 8, 13, 21, 34, 55 };
	/*for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;*/
	/*for (int i : arr)//range-based for
	{
		cout << i << tab;
	}
	cout << endl;*/
	cout << sizeof(Element<int>) << endl;
	ForwardList<int> list = { 3, 5, 8, 13, 21 };
	//range-based for (Диапазонный фор, фор для контейнера, для структуры данных)
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	//list.print();
	/*try
	{
		for (int i = 0; i < list.get_size(); i++)
		{
			list[i] = rand() % 100;
		}
		for (int i = 0; i < 10; i++)
		{
			cout << list[i] << tab;
		}
	}
	catch (std::exception e)	//e - это просто имя параметра
	{
		std::cerr << e.what() << endl;	//Метод what() возвращает сообщение об ошибке.
	}*/


	ForwardList<double> dfl = { 2.5, 2.87, 3.14, 5.9 ,8.2 };
	for (double i : dfl)cout << i << tab; cout << endl;

	ForwardList<std::string> stih = { "Хорошо", "живет", "на", "свете", "Винни-Пух" };
	for (std::string i : stih)cout << i << tab; cout << endl;
#endif // HARDCORE

}