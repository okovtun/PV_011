#pragma once

#include<iostream>
#include<exception>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------\n"

class ForwardList;

class Element
{
	int Data;		//«начение элемента
	Element* pNext;	//Pointer to next - ”казатель на следующий элемент
	static int count;
public:
	const Element* getpNext()const;
	int getData()const;
	//				Constructors:
	Element(int Data, Element* pNext = nullptr);
	~Element();
	friend class Iterator;
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};