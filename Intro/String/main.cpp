#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------\n"

////////////////////////////////////////////////////////////////////////////////////////////
///////////////////		CLASS DECLARATION - ���������� ������			////////////////////

class String;
String operator+(const String& left, const String& right);

class String
{
	char* str;	//��������� �� ������ � ������������ ������
	int  size;	//������ ������ � ������.
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;

	//			Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);

	const char& operator[](int index)const;
	char& operator[](int index);

	//			Methods:
	void print()const;
};

///////////////////				  CLASS DECLARATION END					////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
///////////////////		CLASS DEFINITION - ����������� ������			////////////////////

const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size()const
{
	return size;
}

//			Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	strcpy(this->str, str);
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//strcpy(this->str, other.str);
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	//0) ��������� �� �������� �� ������ ������ ����� ��������
	if (this == &other)return *this;
	//1) ������� ������� ������ �������� �������
	delete[] this->str;
	//2)� ������ ����� ����������� ��� ����� ��������
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int index)const
{
	return this->str[index];
}
char& String::operator[](int index)
{
	return this->str[index];
}

//			Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
	//for (int i = 0; i < size; i++)cout << (int)str[i]; cout << endl;
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

///////////////////					CLASS DEFINITION END				////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();

	String str2 = "Hello";
	str2.print();
	cout << str2 << endl;

	String str3 = str2;	//CopyConstructor
	cout << "Str3:\t" << str3 << endl;

	String str4;
	str4 = str3;	//CopyAssignment
	cout << "Str4:\t" << str4 << endl;

	int a = 2;
	int b = 3;
	a = b;
	cout << a << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
#endif // ASSIGNMENT_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3;
	str3 = str1 + str2;	//�������� + ����� ��������� ������������ (�������) �����
	cout << delimiter << endl;
	cout << str3 << endl;

	String str4 = str3;
	cout << str4 << endl;

	/*cout << delimiter << endl;
	str1 += str2;
	cout << str1 << endl;
	cout << delimiter << endl;*/
#endif // OPERATOR_PLUS_CHECK

	//String str1;	//DefaultConstructor
	//String str2();	//���������� ������� str2, ������� ������ �� ���������,
	//				//� ���������� �������� ���� String.
	//String str3{};	//DefaultConstructor
	//String str4(5);	//SizeConstructor
	//String str5{ 8 };
	//String str6("Hello");
	//String str7{ "Hello" };
	//cout << str7 << endl;
	////String str8 = 16;	//������� �������������� int � String
}