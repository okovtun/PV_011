#include<iostream>
#include<string>
using namespace std;

#define delimiter "\n---------------------------------------\n"

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
		/*if (age >= 15 && age <= 100)
			this->age = age;
		else
			this->age = 0;*/
		this->age = age;
	}

	//			Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	virtual void info()const
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

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//			Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << speciality << ", опыт преподавания " << experience << " лет." << endl;
	}
};

class Graduate :public Student
{
	string topic;
public:
	const string& get_topic()const
	{
		return topic;
	}
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}

	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, double rating, unsigned int semester,
		const string& topic
	) :Student(
		last_name, first_name, age,
		speciality, rating, semester)
	{
		set_topic(topic);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()const
	{
		Student::info();
		cout << "Тема диплома: " << topic << endl;
	}
};

//Polymorphism (Многоформеность, poly - много, morphis - форма)

//#define INHERITANCE_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_BASICS
	/*Human vasily("Тупенко", "Василий", 18);
vasily.info();*/

	Student vasily("Тупенко", "Василий", 18, "Программирование", 4.2, 1);
	vasily.info();

	Teacher teacher("Einstein", "Albert", 142, "Astronomy", 120);
	teacher.info();

	Graduate grad("Pinkman", "Jessie", 25, "Chemistrie", 5, 5, "Methamphitamine distribution");
	grad.info();

	Human* p_vasily = &vasily;
	Human* p_teacher = &teacher;
	Human* p_grad = &grad;
#endif // INHERITANCE_BASICS

	/*Human* group[] =
	{
		&vasily,
		&teacher,
		&grad
	};*/

	Human* group[] =
	{
		new Student("Тупенко", "Василий", 18, "Программирование", 4.2, 1),
		new Student("Пилипенко", "Евгений", 25, "Программирование", 4.5, 2),
		new Teacher("Einstein", "Albert", 142, "Astronomy", 120),
		new Student("Montana", "Antonio", 30, "Cocaine diller", 4.8, 4),
		new Graduate("Pinkman", "Jessi", 25, "Chemistrie", 5, 5, "Methamphitamine distribution")
	};

	cout << delimiter << endl;
	cout << sizeof(group) << endl;
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		group[i]->info();	//virtual
		cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}