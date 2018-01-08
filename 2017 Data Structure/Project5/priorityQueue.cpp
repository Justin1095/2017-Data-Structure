//Justin Seda
//CPSC 250 10am
//jseda1@live.esu.edu
//30 April 2017
//This program is a heap implementation of a priority queue ADT.
//priorityQueue.cpp

#include"priorityQueue.h"
#include<iostream>
#include<iomanip>

using namespace std;


//Constructor - Initializes size to NULL and data to new int[CAPACITY].
priorityQueue::priorityQueue()
{
	data = new int[CAPACITY];
	size = NULL;
}


//Destructor - deletes the data.
priorityQueue::~priorityQueue()
{
	delete data;
}


//getParent- finds the index of a node's parent node.
int priorityQueue::getParent(int index)
{
	return (index - 1) / 2;
}


//getLeftChild- finds the index of node's left child.
int priorityQueue::getLeftChild(int index)
{
	return (2 * index) + 1;
}


//getRightChild- finds the index of a node's right child.
int priorityQueue::getRightChild(int index)
{
	return (2 * index) + 2;

}


//swap- exchanges 2 given values.
void priorityQueue::swap(int& item, int& item2)

{
	int temp;

	temp = item;
	item = item2;
	item2 = temp;
}


//heapify - maintains the heap property.
void priorityQueue::heapify(int index)
{
	int min;
	int left = getLeftChild(index);
	int right = getRightChild(index);

	if (left < size && data[left] <  data[index])
	{
		min = left;
	}
	else
	{
		min = index;
	}

	if (right < size && data[right] < data[min])
	{
		min = right;
	}

	if (min != index)
	{
		swap(data[index], data[min]);
		heapify(min);
	}
}


//printArray- displays the priority queue.
void priorityQueue::printArray(int data[])
{

	for (int i = 0; i < size; i++)
	{
		cout << data[i] << ", ";
	}
}


//insert- inserts items into the priority queue.
void priorityQueue::insert(int item)
{

	size++;
	int index = size - 1;

	while (index > 0 && data[getParent(index)] > item)
	{
		data[index] = data[getParent(index)];
		index = getParent(index);
	}

	data[index] = item;

	cout << endl << "After inserting " << item << " the Priority Queue is:" << endl;
	printArray(data);
	cout << endl;
}


//extractMin- removes the smallest value in the priority queue.
int priorityQueue::extractMin()
{

	int min = data[0];
	data[0] = data[size - 1];
	size--;
	heapify(0);

	cout << endl << "After extracting the minimum value Priority Queue has" << endl;
	printArray(data);
	cout << endl;
	return min;
}


//empty- checks if the size is empty.
bool priorityQueue::empty() const
{	
	return size == NULL;
}


//min- finds the smallest value in the priority queue.
int priorityQueue::min() const
{
	return data[0];
}