//Justin Seda
//CPSC 250 10am
//jseda1@live.esu.edu
//13 April 2017
//This program will design a BinarySearchTree class to create a binary tree that holds different values. 
//The class contains functions for inserting, finding, deleting, Binary Search Tree Sort, pre-order, in-order and post-order traversals.  

//BinarySearchTree.cpp

#include "BinarySearchTree.h"
#include<iomanip>
#include<iostream>

using namespace std;


//Constructor - Initializes root to NULL.
BinarySearchTree::BinarySearchTree()
{
	root = NULL;

}


//Destructor - deletes everythng inside the tree.
BinarySearchTree::~BinarySearchTree()
{
	delete root;
	root = NULL;
}


//insert - insert items into the tree.
void BinarySearchTree::insert(TreeNode *& tree, int item)
{
	if (tree == NULL)
	{
		TreeNode *newNode;
		newNode = new TreeNode;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->info = item;
		tree = newNode;
		return;
	}
	else if (item < tree->info)
	{
		insert(tree->left, item);
	}
	else
	{
		insert(tree->right, item);
	}
}


//treeSearch - searches for the item throughout the tree.
bool BinarySearchTree::treeSearch(TreeNode *node, int key)
{
	if (node == NULL)
	{
		return false;
	}
	else if (key == node->info)
	{
		return true;
	}
	
	if (key > node->info)
	{
		treeSearch(node->right, key);
	}
	else
	{
		treeSearch(node->left, key);
	}	
}


//deleteItem - removes the item in the node inside the tree.
void BinarySearchTree::deleteItem(TreeNode*& tree, int item)
{
	if (tree->info == item)
	{
		deleteNode(tree);
	}
	else if (tree->info < item)
	{
		deleteItem(tree->right, item);
	}
	else
	{
		deleteItem(tree->left, item);
	}

}


//deleteNode- removes entire node inside the tree.
void BinarySearchTree::deleteNode(TreeNode *& tree)
{
	TreeNode* tmp = tree;

	 if (tree->left == NULL || tree->right == NULL)
	{
		if (tree->right == NULL)
		{
			tree = tree->left;
			delete tmp;
		}
		else
		{
			tree = tree->right;
			delete tmp;
		}
	}
	else
	{
		int nTree = tree->info;
		getInorderSuccessor(tree, nTree);
		tree->info = nTree;
		deleteItem(tree, tree->info);
	}
}


//getInorderSuccessor - finds the successor for a node.
void BinarySearchTree::getInorderSuccessor(TreeNode* tree, int& item)
{
	if (tree->right != NULL)
	{
		item = min(tree->right); 
	}
}


//preOrder - traverses and displays the tree in preOrder.
void BinarySearchTree::preOrder(TreeNode *tree)
{
	if (tree != NULL)
	{
		cout << tree->info << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}


//inOrder - traverses and displays the tree in inOrder.
void BinarySearchTree::inOrder(TreeNode* tree)
{
	
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->info << " ";
		inOrder(tree->right);
	}
}


//postOrder - traverses and displays the tree in postOrder.
void BinarySearchTree::postOrder(TreeNode *tree)
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->info << " ";
	}
}


//empty - checks if the root is empty.
bool BinarySearchTree::empty() const
{
	return root == NULL;

}


//min - find the smallest item in the tree.
int BinarySearchTree::min(TreeNode * root)
{	
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->info;
}


//BSTsort - gets the array, insert each item in the array and sorts the items inorder.
void BinarySearchTree:: BSTsort(TreeNode* root, int B[], int size)
{
	for (int i = 0; i < size; i++)
	{
		insert(root, B[i]);
	}
	inOrder(root);
}
