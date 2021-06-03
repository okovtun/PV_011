#include<iostream>
using namespace std;

#define tab "\t"

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			/*this->Data = Data;
			this->pLeft = pLeft;
			this->pRight = pRight;*/
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class Tree;
	}*Root/*, someElement, *somePointer2element*/;	//Указатель на корневой элемент
public:
	const Element* getRoot()const
	{
		return Root;
	}
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		//Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		clear(Root);
		cout << "TDestructor:\t" << this << endl;
	}
	void insert(int Data, Element* Root)	//Здесь Element* Root - это указатель на ветку (поддерево)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)	//Если текущий элемент (Root) не имеет левого потомка
				Root->pLeft = new Element(Data); //создаем его
			else	//В противном случае, идем дальше
				insert(Data, Root->pLeft);
		}
		if (Data > Root->Data)
		{
			/*if (Root->pRight == nullptr)//Если текущий элемент (Root) не имеет правого потомка
			{
				Root->pRight = new Element(Data);
			}
			else
			{
				insert(Data, Root->pRight);
			}*/
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}

	int minValue(Element* Root)
	{
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)
	{
		/*if (Root->pRight == nullptr)return Root->Data;
		maxValue(Root->pRight);*/
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int size(Element* Root)
	{
		//Возвращает количество элементов дерева
		/*if (Root == nullptr)return 0;
		else return size(Root->pLeft) + size(Root->pRight) + 1;*/
		return Root == nullptr ? 0 : size(Root->pLeft) + size(Root->pRight) + 1;
	}
	int sum(Element* Root)
	{
		return Root ? sum(Root->pLeft) + sum(Root->pRight) + Root->Data : 0;
	}

	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;	//Количество элементов дерева
	cout << "Введите количество элементов: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	tree.print(tree.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве:  " << tree.minValue(tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue(tree.getRoot()) << endl;
	cout << "Количество элементов в дереве:  " << tree.size(tree.getRoot()) << endl;
	cout << "Сумма элементов дерева:         " << tree.sum(tree.getRoot()) << endl;
}