#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Pointer to next - Указатель на следующий элемент
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}

	friend class List;
};

class List
{
	Element* Head;	//Указатель на начальный элемент списка
public:
	List()
	{
		this->Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}

	//			Methods:
	void print()const
	{
		//Для того чтобы ходить по списку нужны:
		//1)Итератор
		Element* Temp = Head;	//Temp - это итератор.
								//Итератор - это указатель, при помощи которого можно получить доступ
								//к элементам структуры данных.
		//2) Цикл:
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}