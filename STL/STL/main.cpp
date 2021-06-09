#include<iostream>
#include<array>
#include<vector>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_VECTOR_INSERT
//#define VECTOR_SWAP
#define STL_VECTOR_ERASE

template<typename T>void vector_properties(const vector<T>& vec);
template<typename T>void print_vector(const vector<T>& vec);
template<typename T>void reverse_print_vector(const vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		//cout << arr[i] << tab;
		cout << arr.at(i) << tab;
	}
	cout << endl;
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	cout << *arr.data() << endl;

	arr.fill(123);
	for (int i : arr)
		cout << i << tab;
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	vec.push_back(55);
	/*cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "Max size: " << vec.max_size() << endl;*/
	vector_properties(vec);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	vec.reserve(45);
	//vec.shrink_to_fit();
	vector_properties(vec);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << delimiter << endl;
	vec.assign({ 1024, 2048, 3072 });
	print_vector(vec);
	vector_properties(vec);
#endif // STL_VECTOR

#ifdef STL_VECTOR_INSERT
	int index;
	int count;
	int value;
	do
	{
		cout << "Введите индекс добавляемого элемента: "; cin >> index;
		if (index > vec.size())cout << "Давай меньше, а то упадет))\n";
	} while (index > vec.size());
	cout << "Введите количество добавляемых элементов: "; cin >> count;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	vector<int>::iterator position = vec.begin() + index;
	//vec.insert(position, count, value);
	vec.insert(vec.begin() + index, count, value);
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	vector_properties(vec);

	vec.insert(vec.begin() + 8, vec.begin() + 2, vec.begin() + 5);
	for (int i : vec)cout << i << tab; cout << endl;
	vector_properties(vec);
#endif // STL_VECTOR_INSERT

	/*cout << delimiter << endl;
	vec.insert(vec.begin() + 5, { 1024, 2048, 3072, 4096 });
	print_vector(vec);
	vector_properties(vec);
	cout << "Этот вектор занимает: " << sizeof(vec) << " Байт" << endl;
	cout << delimiter << endl;
	vector<double> vec2;
	cout << "Пустой вектор занимает: " << sizeof(vec2) << " Байт" << endl;*/

#ifdef VECTOR_SWAP
	vector<int> vec1 = { 3,5,8,13,21 };
	vector<int> vec2 = { 34,55,89 };
	print_vector(vec1);
	print_vector(vec2);
	vec1.swap(vec2);
	print_vector(vec1);
	print_vector(vec2);
#endif // VECTOR_SWAP

#ifdef STL_VECTOR_ERASE
	vector<int> vec = { 3, 5, 8, 13, 21, 34, 55 };
	print_vector(vec);
	reverse_print_vector(vec);
	/*int index;	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	vector<int>::iterator position = vec.begin() + index;
	vec.erase(vec.begin() + index);*/
	int index_start, index_end;
	cout << "Введите начало удаляемого диапазона: "; cin >> index_start;
	cout << "Введите конец удаляемого диапазона: "; cin >> index_end;
	vec.erase(vec.begin() + index_start, vec.begin() + index_end);
	print_vector(vec);
	vector_properties(vec);
#endif // STL_VECTOR_ERASE

}

template<typename T>void vector_properties(const vector<T>& vec)
{
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "Max size: " << vec.max_size() << endl;
}

template<typename T>void print_vector(const vector<T>& vec)
{
	cout << typeid(vec.begin()).name() << endl;
	//for (int i : vec)cout << i << tab; cout << endl;
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

template<typename T>void reverse_print_vector(const vector<T>& vec)
{
	for (vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		cout << *it << tab;
	cout << endl;
}