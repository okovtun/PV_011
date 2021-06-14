#include<iostream>
#include<fstream>	//ofstream/ifstream
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//cout << "HelloWorld";
	ofstream fout;	//Создаем поток
	fout.open("File.txt", ios_base::app);	//Открываем поток
	fout << "HelloWorld" << endl;
	//ПОТОКИ ОБЯЗАТЕЛЬНО НУЖНО ЗАКРЫВАТЬ:
	fout.close();	//Закрываем поток
	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	ifstream fin;	//Создаем поток
	fin.open("File.txt");	//Открываем поток
	const int n = 256;
	char buffer[n] = {};
	if (fin.is_open())
	{
		while (!fin.eof())	//end of file
		{
			//fin >> buffer;
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		cout << "Error: File not found" << endl;
	}
	fin.close();			//Закрываем поток  
#endif // READ_FROM_FILE

	ofstream fout;
	ifstream fin;
	fout.open("Copy.txt");
	fin.open("File.txt");

	const int n = 256;
	char buffer[n] = {};

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, n);
			fout << buffer << endl;
		}
	}
	else
	{
		cout << "Error: File not found" << endl;
	}

	fin.close();
	fout.close();
	system("notepad Copy.txt");
}