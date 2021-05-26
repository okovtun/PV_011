#pragma once
#include"Iterator.h"

template<typename T>class ForwardList
{
	unsigned int size;
	Element<T>* Head;	//”казатель на начальный элемент списка
public:
	unsigned int get_size()const;
	const Element<T>* getHead()const;

	Iterator<T> begin();
	Iterator<T> end();
	//			Constructors:
	ForwardList();
	ForwardList(const std::initializer_list<T>& il);
	ForwardList(const ForwardList<T>& other);
	ForwardList(ForwardList<T>&& other)noexcept;
	~ForwardList();

	//			Operators:
	ForwardList<T>& operator=(const ForwardList<T>& other);
	ForwardList<T>& operator=(ForwardList<T>&& other);

	T& operator[](int index);

	//			Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(int Index, T Data);

	//			Removing elements:
	void pop_front();
	void pop_back();

	//			Methods:
	void print()const;
};