#include<iostream>
#include<string>
#include<map>
#include<list>
//using std::cin;
//using std::cout;
//using std::endl;

#define tab "\t"

/*
---------------------------------------------------
Associative containers:map, set, multimap, multiset
---------------------------------------------------
*/

#define MAP

void main()
{
	setlocale(LC_ALL, "");
	//using namespace std;
#ifdef MAP
	//map - это ассоциативный контейнер, то есть, каждый элемент этого контейнера 
	//хранит пару "ключ-значение" (key-value).
	/*std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0,"Sunday"),
		std::pair<int, std::string>(1,"Monday"),
		std::pair<int, std::string>(2,"Tuesday"),
		std::pair<int, std::string>(3,"Wednesday"),
		std::pair<int, std::string>(4,"Thursday"),
		std::pair<int, std::string>(5,"Friday"),
		std::pair<int, std::string>(8,"Thursday"),
		std::pair<int, std::string>(6,"Saturday")
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		std::cout << it->first << tab << it->second << std::endl;
	}
	std::cout << std::endl;*/

	std::map<std::string, std::list<std::string>> dictionary =
	{
		std::pair<std::string, std::list<std::string>>("finite", {"ограниченный", "имеющий предел"}),
		std::pair<std::string, std::list<std::string>>("adjacent", {"примыкающий", "смежный", "соседний"}),
		std::pair<std::string, std::list<std::string>>("plot", {"карта", "план", "график", "сюжет"}),
		std::pair<std::string, std::list<std::string>>("incident", {"случайность", "происшествие"}),
		std::pair<std::string, std::list<std::string>>("splice", {"соединение", "сращивание"})
	};
	//std::cout << dictionary["finite"] << std::endl;
	std::cout << dictionary["finite"].front() << std::endl;
	dictionary["space"].assign({ "пространство", "космос", "пробел" });
	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		std::cout << it->first << ":";
		std::cout.width(20);
		//std::cout << std::left;
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			std::cout << *jt << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << dictionary.find("finite")->first << tab;;
	for (std::string i : dictionary.find("finite")->second)std::cout << i << tab; std::cout << std::endl;
#endif // MAP

}