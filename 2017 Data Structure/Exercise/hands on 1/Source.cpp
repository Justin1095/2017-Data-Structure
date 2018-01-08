// Justin Seda
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;


//Function prototypes
int binarySearch(const int anArray[], int first, int last, int target);
int fact(int n);
int iterativeRabbit(int n);
int rabbit(int n);
void writeArrayBackward(const char anArray2[], int first, int last);
void writeBackward(string s);
void writeBackwardIterative(string s);
int sumUpTo(int n); 

int main()
{-
	const int SIZE = 8;
	int anArray[SIZE] = { 1, 5, 9, 12, 15, 21, 29, 31 };
	char anArray2[3] = { 'c','a','t' };
	char A, B, C;
	string s = "cat";

	cout << "1. Binary search with anArray" << endl;
	cout << "   Search for 9 returns " << binarySearch(anArray, 0, 8, 9) << endl;
	cout << "   Search for 6 returns " << binarySearch(anArray, 0, 8, 6) << endl << "" << endl;

	cout << "2. fact(3) returns " << fact(3) << endl << "" << endl;

	cout << "3. iterativeRabbit(6) returns " << iterativeRabbit(6) << endl << "" << endl;

	cout << "4. rabbit(6) returns " << rabbit(6) << endl << "" << endl;

	cout << "5. write writeArrayBackward(anArray2, 0, 2) returns ";
	writeArrayBackward(anArray2, 0, 2);
	cout << endl << "" << endl;

	cout << "6. writeBackward(s) returns ";
	writeBackward(s);
	cout << endl << "" << endl;

	cout << "7. writeBackwardIterative(s) returns ";
	writeBackwardIterative(s);
	cout << endl << "" << endl;

	cout << "8. sumUpTo(10) returns " << sumUpTo(10) << endl << "" << endl;

	system("pause");
	return 0;
}

int binarySearch(const int anArray[], int first, int last, int target)
/** Searches the array anArray[first] through anArray[last]
for a given value by using a binary search.
@pre  0 <= first, last <= SIZE - 1, where SIZE is the
maximum size of the array, and anArray[first] <=
anArray[first + 1] <= ... <= anArray[last].
@post  anArray is unchanged and either anArray[index] contains
the given value or index == -1.
@param anArray  The array to search.
@param first  The low index to start searching from.
@param last  The high index to stop searching at.
@param target  The search key.
@return  Either index, such that anArray[index] == target, or -1.
*/
{
	int index = 0;
	if (first > last)
	{
		index = -1;
	}
	else 
	{
		int mid = first + (last - first) / 2;
		if (target == anArray[mid])
		{
			index = mid;
		}
		else if (target < anArray[mid])
		{
			index = binarySearch(anArray, first, mid - 1, target);
		}
		else 
		{
			index = binarySearch(anArray, mid + 1, last, target);
		}

	}
	return index;
}

int fact(int n)
/** Computes the factorial of the nonnegative integer n.
@pre  n must be greater than or equal to 0.
@post  None.
@return  The factorial of n; n is unchanged. */
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact(n - 1);
	}
}

int iterativeRabbit(int n)
/** Iterative solution to the rabbit problem. */
{
	int current = 1;
	int previous = 1;
	int next = 1;

	for(int i = 3; i <=  n; i++)
	{
		next = current + previous;
		previous = current;
		current = next;
	}
	return next;
}

int rabbit(int n)
/** Computes a term in the Fibonacci sequence.
@pre n  is a positive integer.
@post  None.
@param n  The given integer.
@return  The nth Fibonacci number. */
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return rabbit(n - 1) + rabbit(n - 2);
	}
}


void writeArrayBackward(const char anArray2[], int first, int last)
/** Writes the characters in an array backward.
@pre  The array anArray contains size characters, where size >= 0.
@post  None.
@param anArray  The array to write backward.
@param first  The index of the first character in the array.
@param last  The index of the last character in the array. */
{
	if (first <= last)
	{
		 cout << anArray2[last];
		writeArrayBackward(anArray2, first, last - 1);
	}
}

void writeBackward(string s)
/** Writes a character string backward.
@pre  The string s to write backward.
@post  None.
@param s  The string to write backward. */
{
	int length = s.size();
	if (length > 0)
	{
		cout << s.substr(length - 1, 1);
		writeBackward(s.substr(0, length - 1));
	}
}

void writeBackwardIterative(string s)
/** Iterative version. */
{
	int length = s.size();
	while (length > 0)
	{
		cout << s.substr(length - 1, 1);
		length--;
	}
}

int sumUpTo(int n)
/** Computes the sum of the integers from 1 through n.
@pre  n > 0.
@post  None.
@param n  A positive integer.
@return  The sum 1 + 2 + . . . + n. */
{
	int sum = 0;
	if (n == 1)
	{
		sum = 1;
	}
	else
	{
		sum = n + sumUpTo(n - 1);
	}
	return sum;
}

//Test your functions with followings :
//

