// Stek.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template<typename T>
class Stek
{
private:
	T* _array;
	unsigned int _size;
	unsigned int Index;
public:
	Stek();
	Stek(unsigned int size);
	~Stek();
	bool Add(T data);
	bool Del();
	T Get();
};

/** Stek<T>::Stek() */
template<typename T>
Stek<T>::Stek()
{
	_size = Index = 0;
	_array = nullptr;
}

/** Stek<T>::Stek(unsigned int size) */
template<typename T>
Stek<T>::Stek(unsigned int size)
{
	_size = size;
	Index = 0;
	_array = new T[size];
	for (int i = 0; i < size; i++)
		_array[i] = 0;
}

/** Stek<T>::~Stek() */
template<typename T>
Stek<T>::~Stek()
{
	delete[]_array;
}

/** bool Stek<T>::Add(T data) */
template<typename T>
bool Stek<T>::Add(T data)
{
	if (Index >= _size)
		return false;
	_array[Index] = data;
	Index++;
	return true;
}

/** bool Stek<T>::Del() */
template<typename T>
bool Stek<T>::Del()
{
	if (Index <= 0)
		return false;
	_array[--Index] = 0;
	return true;
}

/** T Stek<T>::Get() */
template<typename T>
T Stek<T>::Get()
{
	int temp = 0;
	if (Index != 0)
		temp = Index - 1;
	return _array[temp];
}

/** vector<string> &split(const string &s, char delim, vector<string> &elems) */
vector<string> &split(const string &s, char delim, vector<string> &elems)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

/** vector<string> split(const string &s, char delim) */
vector<string> split(const string &s, char delim)
{
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

/** int main(int argc, char* argv[]) */
int main(int argc, char* argv[])
{
	unsigned int maxSize;
	cout << "Size of Stek = ";
	cin >> maxSize;
	Stek<int> Stek(maxSize);
	int N;
	cout << "N = ";
	cin >> N;
	vector<string> expressions;
	string expression;
	int i = 0;
	int size;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (i < N && i >= 0)
	{
		cout << i + 1 << ">>";
		getline(cin, expression);
		expressions = split(expression, ' ');
		size = expressions.size();
		if (size == 0)
		{
			cout << "The expression is not correct. Try again.\n";
			i--;
		}
		else if (expressions[0] == "add")
		{
			if (size == 2)
			{
				if (!Stek.Add(stoi(expressions[1])))
				{
					cout << "Stek os full. Try again\n";
					i--;
				}
			}
			else
			{
				cout << "The expression is not correct. Try again.\n";
				i--;
			}
		}
		else if (expressions[0] == "del")
		{
			if (size == 1)
			{
				if (!Stek.Del())
				{
					cout << "Stek is empty. Try again\n";
					i--;
				}
			}
			else
			{
				cout << "The expression is not correct. Try again.\n";
				i--;
			}
		}
		else if (expressions[0] == "get")
		{
			if (size == 1)
				cout << Stek.Get() << endl;
			else
			{
				cout << "The expression is not correct. Try again.\n";
				i--;
			}
		}
		else
		{
			cout << "The operation is not correct. Try again.\n";
			i--;
		}
		i++;
	}
	system("pause");
	return 0;
}

