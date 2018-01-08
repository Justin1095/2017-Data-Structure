//Justin Seda
//Hancds-on 8
//CPSC 250 10am
//jseda1@live.esu.edu
//16 April 2017
#include<iomanip>
#include<iostream>

using namespace std;

int getParent(int index);
int getLeftChild(int index);
int getRightChild(int index);
void swap(int& item1, int& item2);
void heapify(int A[], int index, int size);
void build_heap(int A[], int size);
void printArray(int A[], int size);
void heapInsert(int A[], int &size, int Item);

int main()
{

	const int SIZE = 15;
	 int  hSize = 10;	//the heap size
	int A[SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

	cout << "Print Array A:" << endl;
	printArray(A, hSize);

	cout << endl << endl << "Parent of the node 5 is the node " << getParent(5) << endl;
	cout << "Left child of the node 3 is the node " << getLeftChild(3) << endl;
	cout << "Right child of the node 3 is the node " << getRightChild(3) << endl << endl;

	cout << "Calling Heapify A, 1 " << endl;
	heapify(A, 1, hSize);
	printArray(A, hSize);

	cout << endl << endl << "Build heap " << endl << "Print Heap A: " << endl;
	build_heap(A, hSize);
	printArray(A, hSize);

	cout << endl << endl << "After inserting the number 20 into the heap A: " << endl;
	heapInsert(A, hSize, 20);
	printArray(A, hSize);

	cout << endl << endl << "After inserting the number 17 into the heap A: " << endl;
	heapInsert(A, hSize, 17);
	printArray(A, hSize);
	cout << endl << endl;

	system("pause");
}


int getParent(int index)
// Purpose: calculates the index of a node's parent node
// Post: integer value returned to caller
{
	return (index - 1 )/ 2;
}


int getLeftChild(int index)
// Purpose: calculates the index of node's left child
// Post: integer value returned to caller
{
	return (2 * index) + 1;
}


int getRightChild(int index)
// Purpose: calculates the index of a node's right child
// Post: integer value returned to the user
{
	return (2 * index) + 2;

}


void swap(int& item1, int& item2)
// Purpose: exchanges two values
// Post: item1 = old item2 and item2 = old item1, results 
//       returned through reference parameter
{
	int temp;

	temp = item1;
	item1 = item2;
	item2 = temp;
}


void heapify(int A[], int index, int size)
{
	int biggest;
	int left = getLeftChild(index);
	int right = getRightChild(index);

	if (left < size && A[left] > A[index])
	{
		biggest = left;
	}
	else
	{
		biggest = index;
	}

	if (right < size && A[right] > A[biggest])
	{
		biggest = right;
	}

	if (biggest != index)
	{
		swap(A[index], A[biggest]);
		heapify(A, biggest, size);
	}
}


void build_heap(int A[], int size)
{
	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(A, i, size);
	}
}
 

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << ", ";
	}
}


void heapInsert(int A[], int &size, int Item)
{
	size++;
	int index = size - 1;

	while (index > 0 && A[getParent(index)] < Item)
	{
		A[index] = A[getParent(index)];
		index = getParent(index);
	}

	A[index] = Item;
} 