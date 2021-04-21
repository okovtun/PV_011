#include<iostream>
#include<string>
using namespace std;

class Human
{
	string last_name;	//
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		if (age >= 15 && age <= 100)
			this->age = age;
		else
			this->age = 0;
	}

	//			Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()const
	{
		cout << last_name << " " << first_name << ", " << age << " лет" << endl;
	}
};

class Student :public Human
{
	string speciality;
	double rating;
	unsigned int semester;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	double get_rating()const
	{
		return rating;
	}
	unsigned int get_semester()const
	{
		return semester;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_rating(double rating)
	{
		if (rating > 0 && rating <= 5)
			this->rating = rating;
		else
			this->rating = 0;
	}
	void set_semester(unsigned int semester)
	{
		if (semester <= 5)
			this->semester = semester;
		else
			this->semester = 0;
	}
	//			Constructor:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, double rating, unsigned int semester
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_rating(rating);
		set_semester(semester);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()const
	{
		Human::info();
		cout << "Курс: " << semester << ", Специальность: " << speciality << ", успеваемость: " << rating << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Human vasily("Тупенко", "Василий", 18);
	vasily.info();*/

	Student vasily("Тупенко", "Василий", 18, "Программирование", 4.2, 1);
	vasily.info();
}