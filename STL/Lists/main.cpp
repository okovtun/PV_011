#include<iostream>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>inline void list_properties(const std::list<T>& lst)
{
	cout << "Size:    " << lst.size() << endl;
	cout << "MaxSize: " << lst.max_size() << endl;
}
template<typename T>void print_list(const std::list<T>& lst)
{
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}



class list_wrapper
{
	std::list<int> lst;
};

bool more_than_10(const int& value)
{
	return value > 10;
}

void main()
{
	setlocale(LC_ALL, "");
	//list - это контейнер, который хранит данные в виде двусв€зного списка
	cout << more_than_10 << endl;
	std::list<int> lst = { 3, 5, 8, 13, 21};
	cout << "Empty list size: " << sizeof(list_wrapper) << endl;
	list_properties(lst);
	print_list(lst);
	lst.push_front(2);
	lst.push_back(34);
	for (int i : lst)cout << i << tab; cout << endl;
	list_properties(lst);

	/*int index;
	int value;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	std::list<int>::iterator position = lst.begin();
	for (int i = 0; i < index; i++)position++;
	lst.insert(position, value);*/
	//print_list(lst);
	lst.resize(20);
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		//cout << *it << tab;
		*it = rand() % 10;
	}
	cout << endl;
	/*lst.resize(25);
	lst.remove(0);
	lst.remove_if(more_than_10);*/
	for (int i : lst)cout << i << tab; cout << endl;
	lst.unique();
	for (int i : lst)cout << i << tab; cout << endl;

	/*for (int i = 0; i < lst.size(); i++)
	{
		cout << lst[i] << tab;
	}
	cout << endl;*/
}