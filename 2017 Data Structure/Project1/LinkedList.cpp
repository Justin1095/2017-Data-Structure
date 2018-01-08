//Justin Seda
//CPSC 250 10am
//jseda1@live.esu.edu
//31 Jan. 2017
//This program will demonstrate the use of a linked list.
#include "LinkedList.h"

// Constructor - Initializes head to NULL 
LinkedList::LinkedList()
{
	head = NULL; 
}


//Destructor - deletes all of the nodes in the list 
LinkedList::~LinkedList()
{
	ListNode *pointNode; // The node pointer, used to traverse the list 
	ListNode *nextNode; //goes to the next node

	pointNode = head;  //make pointNode's position to the head 
	while (pointNode != NULL) // while the pointNode isn't equal to null then 
	{
		nextNode = pointNode->next; //save the pointer to the next node
		delete pointNode; //and delete the node

		pointNode = nextNode; //pointNode's position becomes the next node
	}
}


//appendNode - add a node to the end of the list
void LinkedList::appendNode(int number)
{
	ListNode *pointNode;
	ListNode *nNode; // points to new node

	nNode = new ListNode;
	nNode->next = NULL;
	nNode->value = number;
	//The above code will allocate the new node then store the number in it.

	if (!head) //No nodes in list, then the newNode will be the head
		head = nNode;
	else //If there's a node in the list then make the head the pointNode
	{
		pointNode = head;
		while (pointNode->next)//After that, searches for the last node
		{
			pointNode = pointNode->next;
		}
		pointNode->next = nNode; //Makes the last node into newNode
	}
}


//insertNode - insert a node into the list
void LinkedList::insertNode(int number)
{
	ListNode *pointNode, *nNode;
	ListNode *preNode = NULL; //the previous node

	nNode = new ListNode;
	nNode->value = number;
	//The above code will allocate the new node then store the number in it.

	if (!head) //No nodes in list, then the nNode will be the head
	{
		head = nNode;
		nNode->next = NULL;
	}
	else //insert a new node
	{
		preNode = NULL;
		pointNode = head;
		
		while (pointNode != NULL && pointNode->value < number) //goes past all the nodes whose value is less then the number
		{
			preNode = pointNode;
			pointNode = pointNode->next;
		}

		if (preNode == NULL) //insert a new node before all the other nodes if it's the 1st
		{
			head = nNode;
			nNode->next = pointNode;
		}
		else //if not, insert it after the preNode
		{
			preNode->next = nNode;
			nNode->next = pointNode;
		}
	}
}


//deleteNode - remove a node from a linked list
void LinkedList::deleteNode(int number)
{
	ListNode *pointNode, *preNode;

	preNode = NULL;
	if (!head) //do nothing if list is empty
		return;
	if (head->value == number) //looks if the first node is number
	{
		pointNode = head->next;
		delete head;

		head = pointNode; 
	}
	else 
	{
		pointNode = head; 
		while ( pointNode->value != number && pointNode != NULL)// past all nodes if their value is not equal to the number
		{
			preNode = pointNode;
			pointNode = pointNode->next;
		}
		if (pointNode) //This will connect the preNode to the node after pointNode, then deletes it
		{
			preNode->next = pointNode->next;
			delete pointNode;
		}
	}
}


//displayList - this will display the list 
void LinkedList::displayList()  
{
	ListNode *pointNode = head;

	while (pointNode)
	{
		cout << pointNode->value;
		cout << "" << endl;
		pointNode = pointNode->next;
	}
}


//search - this will search through the list
int LinkedList::search(int number)
{
	ListNode *pointNode = head;
	int countNum = 1;

	while (pointNode)
	{
		if (pointNode->value != number)
		{
			pointNode = pointNode->next;
			countNum++;
		}
		else
		{
			return countNum;
		}
	}
	return 0;
}