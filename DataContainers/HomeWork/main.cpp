#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define DELIMETER "\n----------------------------------\n"

class Element
{
	int Data; // �������� ��������
	Element* pNext; // ��������� �� ��������� �������
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

int Element::count = 0; // ������������� ����������� ����������

class ForwardList
{
	unsigned int size;
	Element* Head; // ��������� �� ��������� ������� ������
public:
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr; // nullptr � Head��������,��� ������ ����
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head != nullptr)
		{
			Element* New = Head->pNext;
			delete Head;
			Head = New;
		}
		cout << "LDestructor:\t" << this << endl;
	}

	// Adding elements:
	void push_front(int Data)
	{
		//        Element* New= new Element(Data);
		//        New->pNext=Head;
		//        Head=New;
		Head = new Element(Data, Head);
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

	void insert(int index, int Data)
	{

		if (index > Element::count)return;
		if (index == 0)
		{
			push_front(Data);
			return;;
		}
		else
		{
			Element* New = new Element(Data);
			Element* Temp = Head;
			for (int i = 0; i < index - 1; i++)
				Temp = Temp->pNext;
			New->pNext = Temp->pNext;
			Temp->pNext = New;
		}
		size++;
	}

	// Removing elements:

	void pop_front()
	{

		if (Head == nullptr)return;
		//1.���������� ����� ���������� ��������
		Element* erase_element = Head;
		// 2.��������� ������� �� ������
		Head = Head->pNext;
		//3.������� ������� �� ������
		delete erase_element;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr) //������� �� �������������� ��������
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;//������� ��������� ������� �� ������
		Temp->pNext = nullptr; // �������,��� ��� ����� ������
		size--;
	}

	void erase(int index)
	{
		if (index >= size)return;
		if (index == 0)
		{
			pop_front();
			return;;
		}
		if (index == size - 1)
		{
			pop_back();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)      //�������,��� ����� ����� ������ �������,���� � ��������,�� ����� ���� �����
			Temp = Temp->pNext;
		Element* erase_element = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete erase_element;
		size--;
	}
	// Methods

	void print()const
	{
		//        // ��� ����,����� ������ �� ������ �����: �������� � ����
		//        Element* Temp = Head; // Temp - ��������. �������� - ���������,��� ������ �������� ����� �������� ������ � ��������� ��������� ������
		//        while(Temp != nullptr)
		//        {
		//            cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//            Temp = Temp->pNext; //������� �� ��������� �������
		//        }
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << DELIMETER << endl;
		cout << "� ������ " << size << " ���������\n";
		cout << "����� ���������� " << Element::count << " ���������\n";
		cout << DELIMETER << endl;
	}

};



//#define ADDING_ELEMENTS_CHECK
int main()
{
	setlocale(LC_ALL, "");
	int n;
	int index;
	cout << "������� ������ ������: "; cin >> n;
	cout << DELIMETER << endl;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		// list.push_back(rand()%100);
	}
	//    list.print();
	//    list.pop_front();
	//    list.print();
	//    list.pop_back();
	//    list.print();
	cout << DELIMETER << endl;
	list.print();
	cout << DELIMETER << endl;
	//    cout << "�������  ������ ���������� ��������: "; cin >> index;
	//    list.erase(index);
	//    list.print();
	cout << DELIMETER << endl;
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	list.push_front(222);
	list.print();
#ifdef ADDING_ELEMENTS_CHECK
	cout << "�������  ������ ������������ ��������: "; cin >> index;
	cout << "������� ����������� ��������: "; cin >> value;
	//list.push_back(value);
	list.insert(index, value);
	list.print();

	ForwardList list2;
	cout << "������� ������ ������: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list2.push_back(rand() % 100);
	}
	list2.print();
#endif
	return 0;
}
