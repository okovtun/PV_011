#include<iostream>
#include<fstream>
#include<string>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define WAL //Wake On LAN

void main()
{
	setlocale(LC_ALL, "Russian");

	string source_file_name;
	string destination_file_name;

	cout << "¬ведите им€ исходного файла: "; getline(cin, source_file_name);
	cout << "¬ведите им€ конечного файла: "; getline(cin, destination_file_name);


	//ofstream fout("201 ready.txt");
	//ifstream fin("201 RAW.txt");

	string IP;
	string MAC;

	//ofstream fout(destination_file_name);
	ifstream fin;
	fin.open(source_file_name.c_str());
	if (!fin.is_open())
	{
		ofstream fout(destination_file_name);
		//while (!fin.eof())
		while (fin >> IP >> MAC)
		{
			cout << MAC << tab << IP << endl;
			fout << MAC << tab << IP << endl;
		}
		fout.close();
		string cmd = "notepad" + destination_file_name;
		system(cmd.c_str());
	}
	else
	{
		cerr << "\nFile not found" << endl;
	}

	fin.close();

}

