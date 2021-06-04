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
		bool is_leaf()const
		{
			return pLeft == pRight;
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
	Tree(const initializer_list<int>& il) :Tree()
	{
		
	}
	~Tree()
	{
		clear(Root);
		cout << "TDestructor:\t" << this << endl;
	}
	void insert(const int& Data)
	{
		insert(Data, this->Root);
	}
	void erase(const int& Data)
	{
		erase(Data, Root);
	}
	int minValue()
	{
		return minValue(Root);
	}
	int maxValue()
	{
		return maxValue(Root);
	}
	int size()
	{
		return size(Root);
	}
	int sum()
	{
		return sum(Root);
	}
	double avg()
	{
		return avg(Root);
	}
	void print()
	{
		print(Root);
		cout << endl;
	}
	void clear()
	{
		clear(Root);
	}
private:
	void insert(const int& Data, Element* Root)	//Здесь Element* Root - это указатель на ветку (поддерево)
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
	void erase(const int& Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->is_leaf())
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Root->pLeft)
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
		/*if(Root)erase(Data, Root->pLeft);
		if(Root)erase(Data, Root->pRight);*/
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
	double avg(Element* Root)
	{
		return (double)sum(Root) / size(Root);
	}

	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}
	void clear(Element*& Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
		Root = nullptr;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;	//Количество элементов дерева
	//cout << "Введите количество элементов: "; cin >> n;
	Tree tree = {50, 25, 16, 32, 64, 55, 77};
	/*for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}*/
	/*tree.insert(50);

	tree.insert(25);
	tree.insert(16);
	tree.insert(32);
	tree.insert(11);
	tree.insert(18);
	tree.insert(30);
	tree.insert(36);
	
	tree.insert(64);
	tree.insert(55);
	tree.insert(80);
	tree.insert(54);
	tree.insert(58);
	tree.insert(77);
	tree.insert(85);*/

	tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве:  " << tree.minValue() << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue() << endl;
	cout << "Количество элементов в дереве:  " << tree.size() << endl;
	cout << "Сумма элементов дерева:         " << tree.sum() << endl;
	cout << "Среднее арифметическое элементов дерева:" << tree.avg() << endl;
	int value;
	cout << "Введите удаляемое значение: "; cin >> value;
	tree.erase(value);
	tree.print();
	tree.clear();
	cout << tree.getRoot() << endl;
	tree.print();
}