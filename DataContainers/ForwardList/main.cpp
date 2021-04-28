#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Pointer to next - Указатель на следующий элемент
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}

	friend class ForwardList;
};

int Element::count = 0;	//Инициализация статической переменной

class ForwardList
{
	unsigned int size;
	Element* Head;	//Указатель на начальный элемент списка
public:
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;	//nullptr в Head означает что список пуст.
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index > Element::count)return;
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			Temp = Temp->pNext;
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//			Removing elements:
	void pop_front()
	{
		Element* erase_element = Head;	//1) Запоминаем адрес удаляемого элемента:
		Head = Head->pNext;		//2) Исключаем элемент из списка:
		delete erase_element;//3) Удаляем элемент из памяти
		size--;
	}
	void pop_back()
	{
		//1) Доходим до предпоследнего элемента
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
			Temp = Temp->pNext;
		delete Temp->pNext;//2) Удаляем последний элемент из памяти
		Temp->pNext = nullptr;//3) Говорим, что это конец списка
		size--;
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
		cout << "В списке " << size << " элементов\n";
		cout << "Общее количество элементов: " << Element::count << endl;
	}
};

//#define ADDING_ELEMENTS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.pop_front();
	list.pop_back();
	list.print();

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

}