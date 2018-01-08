//Justin Seda
//Hancds-on 9
//CPSC 250 10am
//jseda1@live.esu.edu
#include<iomanip>
#include<iostream>

using namespace std;

const int  CAPACITY = 10;

void initTable(int data[]);
void printTable(int data[]);
int hash_function(int key);
void hashInsert(int data[], int key);
bool key_occurs(int data[], int search_key);

int main()
{	
	int data[CAPACITY] = {};
	int Arr[8] = { 10, 22, 11, 31, 24, 88, 38, 21 };

	initTable(data);

	cout << "Part 1: Hash Table" << endl;
	for (int i = 0; i < 8; i++)
	{
		hashInsert(data, Arr[i]);
	}
	printTable(data);

	cout << endl << "Part 2: Checking numbers in the hash table" << endl;

	key_occurs(data, 11);
	key_occurs(data, 31);
	key_occurs(data, 23);

	system("pause");
}


void initTable(int data[])
{
	for (int i = 0; i < CAPACITY; i++)
	{
		data[i] = -1;
	}
}


void printTable(int data[])
{
	for (int i = 0; i < CAPACITY; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}


int hash_function(int key)
{
	return (key % CAPACITY);
}


void hashInsert(int data[], int key)
{
	int hash = hash_function(key);
	int i = 0;
	while( i < CAPACITY )
	{
		if ((data[hash + i]) == -1)
		{
			data[hash + i] = key;
			break;
		}
		i++;
	}
}


bool key_occurs(int data[], int search_key)
{
	int i = 0;
	while ( i < CAPACITY)
	{
		if (data[i] == search_key)
		{
			cout << search_key << " is found"<< endl;
			return true;
		}
		i++;
	}
	cout << search_key << " is not found" << endl;
	return false;
}
