#pragma once
#include<iostream>
#include<string>
#include<exception>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------\n"

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>class Element
{
	T Data;		//«начение элемента
	Element* pNext;	//Pointer to next - ”казатель на следующий элемент
	static int count;
public:
	const Element* getpNext()const;
	T getData()const;
	//				Constructors:
	Element(T Data, Element* pNext = nullptr);
	~Element();
	friend class Iterator<T>;
	friend class ForwardList<T>;
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};