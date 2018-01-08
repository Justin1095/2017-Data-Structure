//Justin Seda
//CPSC 250 10am
//jseda1@live.esu.edu
//14 Feb. 2017
//This program will demonstrate the use of recursion.
#include<iomanip>
#include<iostream>
#include<string>

using namespace std;

//Function prototypes
int computeSum(const int anArray[], int n);//Computes the sum of the integers
int sum(int start, int end); //Given two integers, a start and an end then finds the sum of the integers
void writeBackward(string s);//Writes characters in given string backwards
void writeBackward2(string s);//Writes characters in given string backwards
void writeIntegers(int m, int n);//Given two numbers and writes out the integers
int sumOfSquares(int n); //Finds the sum of squares
void reverseDigits(int integer);//Reverse the integers
void writeLine(char ch, int n);//Writes a given character repeatedly to create a line
void writeBlock(char ch, int m, int n);//Writes m numbers of lines with n characters

int main()
{
	const int SIZE = 8; 
	int anArray[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	string s = "cat";

	//Calls and displays each function 
	//computeSum()
	cout << "1. computeSum(anArray, 5) returns " << computeSum(anArray, 5) << endl << "" << endl;  

	//sum()
	cout << "2. sum(2, 5) returns " << sum(2, 5) << endl << "" << endl; 

	//writeBackward()
	cout << "3. a. writeBackward(s) returns ";
	writeBackward(s);
	cout << endl << "" << endl;

	//writeBackward2()
	cout << "3. b. writeBackward2(s) returns ";//
	writeBackward2(s);
	cout << endl << "" << endl;

	//writeIntegers()
	cout << "4. writeIntegers(2, 5) returns ";
	writeIntegers(2, 5);
	cout << endl << "" << endl;

	//sumOfSquares()
	cout << "5. sumOfSquares(5) returns " << sumOfSquares(5) << endl << "" << endl;

	//reverseDigits()
	cout << "6. reverseDigits(1234) returns ";
	reverseDigits(1234);
	cout << endl << "" << endl;

	//writeLine()
	cout << "7. a. writeLine('*', 5) returns " << endl;
	writeLine('*', 5);
	cout << endl << "" << endl;

	//writeBlock()
	cout << "7. b. writeBlock('*', 5, 3) returns " << endl;
	writeBlock('*', 5, 3);
	cout << endl << "" << endl;

	system("pause");
	return 0;
}


/**
1. This function computes the sum of the integers in the array from the begin to the 
last number that is given.
*/
int computeSum(const int anArray[], int num)
{
	int result = 0;
	if (num == 1)
	{
		result = 1;
	}
	else
	{
		result = num + computeSum(anArray, num - 1);
	}
	return result;
}


/**
2. This function is given two integers, a start and an end then finds the sum of the
integers throughout the start and end.
*/
int sum(int start, int end)
{
	int result = 0;
	if (end > start)
	{
		result = start + sum(start + 1, end);
	}
	else
	{
		result = result + end;
	}
	return result;
}


/**
3. a. This function writes the characters in the given string backwards.
*/
void writeBackward(string s)
{
	int len = s.size();
	if (len == 1)
	{
		cout << s;
	}
	else
	{
		cout << s.substr(len - 1, 1);
		writeBackward(s.substr(0, len - 1));
	}
	return;
}


/**
3. b. This function writes the characters in the given string backwards, 
but minus the first character then displays the first character in the string.
*/
void writeBackward2(string s)
{
	int len = s.size();
	if (len == 0)
	{
		return;
	}
	else
	{
		writeBackward2(s.substr(len-(len-1), len));
		cout << s.substr(0, 1);

	}
	return;
}


/**
4. This function is given two numbers and writes out the integers throughout these two numbers.
*/
void writeIntegers(int m, int n)
{
	if (m > 0 && m <= n)
	{
		cout << m << ", ";
		writeIntegers(m + 1, n);
	}
	return;

}


/**
5. This function returns the sum of squares from 1 to the given number.
*/
int sumOfSquares(int n)
{
	int sum = 0;
	if (n > 0)
	{
		sum = n * n + sumOfSquares(n - 1);
	}
	return sum;
}


/**
6. This function reverse the given integers.
*/
void reverseDigits(int integer)
{
	int result = 0;
	if (integer > 0)
	{
		result = integer % 10;
		cout << result;
		reverseDigits(integer / 10);
	}
	return;
}


/**
7. a. This function writes a given character repeatedly to form a line of n characters.
*/
void writeLine(char ch, int n)
{
	if (n > 0)
	{
		cout << ch;
		writeLine(ch, n - 1);
	}
	return;
}


/**
7. b. This function uses writeLine to write m numbers of lines with n characters each.
*/
void writeBlock(char ch, int m, int n)
{
	if (m > 0)
	{
		writeLine(ch, n);
		cout << endl;

		writeBlock(ch, m - 1, n);
	}	
	return;
}