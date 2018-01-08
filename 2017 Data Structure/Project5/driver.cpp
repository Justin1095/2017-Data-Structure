//Justin Seda
#include "PriorityQueue.h"
#include<iomanip>
#include<iostream>
using namespace std;

int main()
{
	priorityQueue myqueue;

	if (myqueue.empty())
	{
		cout << "My priority Queue is empty" << endl;
	}
	else
	{
		cout << "My priority Queue is not empty" << endl;
	}

	myqueue.insert(59);
	myqueue.insert(41);
	myqueue.insert(25);
	myqueue.insert(12);
	myqueue.insert(91);
	myqueue.min();
	myqueue.extractMin();

	myqueue.insert(34);
	myqueue.insert(63);
	myqueue.extractMin();

	myqueue.insert(75);
	myqueue.insert(85);
	myqueue.extractMin();


	cout << endl;
	cout << "Minimum value is " << myqueue.min() << endl;

	system("pause");
	return 0;
}
