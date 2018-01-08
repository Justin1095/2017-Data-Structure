//Justin Seda
//CPSC 250 10am
//jseda1@live.esu.edu
//13 April 2017
//This program will design a BinarySearchTree class to create a binary tree that holds different values. 
//The class contains functions for inserting, finding, deleting, Binary Search Tree Sort, pre-order, in-order and post-order traversals.  

//myBST.cpp

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree BSTree; //BinarySearchTree 
	int const SIZE = 9;//the array's size
	int B[SIZE] = { 7, 1, 4, 6, 13, 3, 7, 14, 10 };//items in the array

	//Insert
	cout << "Inserting nodes 7, 3, 10, 1, 6, 14, 4, 7, 13 sequentially" << endl << endl;
	BSTree.insert(BSTree.root, 7);//insert 7
	BSTree.insert(BSTree.root, 3);//insert 3
	BSTree.insert(BSTree.root, 10);//insert 10
	BSTree.insert(BSTree.root, 1);//insert 1
	BSTree.insert(BSTree.root, 6);//insert 6
	BSTree.insert(BSTree.root, 14);//insert 14
	BSTree.insert(BSTree.root, 4);//insert 4
	BSTree.insert(BSTree.root, 7);//insert 7
	BSTree.insert(BSTree.root, 13);//insert 13

	//Traversal
	cout << "Here are the values in the tree (in-order traversal):" << endl;
	BSTree.inOrder(BSTree.root);//inorder
	cout << endl <<endl;
	cout << "Here are the values in the tree (pre-order traversal):" << endl;
	BSTree.preOrder(BSTree.root);//preorder
	cout << endl << endl;
	cout << "Here are the values in the tree (post-order traversal):" << endl;
	BSTree.postOrder(BSTree.root);//postorder
	cout << endl << endl;

	//Deleting
	cout << "Deleting 6..." << endl;
	BSTree.deleteItem(BSTree.root, 6);//deletes 6
	cout << "Deleting 13..." << endl;
	BSTree.deleteItem(BSTree.root, 13);//deteles 13
	
	//New inorder with removal of 6 and 13
	cout << endl << "Now, here are the nodes (in order traversal):" << endl;
	BSTree.inOrder(BSTree.root);//inorder
	cout << endl << endl << endl;

	//Search
	int num = 14;//searches for 14
	bool result = BSTree.treeSearch(BSTree.root, num);//treeSearch

	//checks if the item is in the tree and replys back
	if (result == true)
	{
		cout << "Yes, " << num << " is in the binary tree" << endl;
	}
	else
	{
		cout << "No, " << num << " is in the binary tree" << endl;
	}
	cout << endl;

	//Min
	int min = BSTree.min(BSTree.root);//min
	cout << "The minimum value in the tree is " << min << endl;
	cout << endl;

	//BSTsort
	BinarySearchTree newBST;//new BinarySearchTree

	cout << "BST Sort: The result of BST Sort for node values is:" << endl;
	newBST.BSTsort(newBST.root, B, SIZE);//BSTsort 
	cout << endl;

	system("pause");
}