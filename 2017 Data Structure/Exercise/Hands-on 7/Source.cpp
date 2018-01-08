//Justin Seda
//CPSC 250 10am
//Hancds-on 7
#include<iomanip>
#include<iostream>

using namespace std;


struct  TreeNode
{
	int info;
	TreeNode * left;
	TreeNode * right;
};

void preOrder(TreeNode*);
void inOrder(TreeNode*);
void postOrder(TreeNode*);

int main()
{
	TreeNode one, two, three, four, five, six, seven, eight, nine;
	TreeNode * root;
	root = &one;
	one.info = 2;
	one.left = &two;
	one.right = &three;
	two.info = 7;
	two.left = &four;
	two.right = &five;
	three.info = 5;
	three.left = NULL;
	three.right = &six;
	four.info = 2;
	four.left = NULL;
	four.right = NULL;
	five.info = 6;
	five.left = &seven;
	five.right = &eight;
	six.info = 9;
	six.left = &nine;
	six.right = NULL;
	seven.info = 5;
	seven.left = NULL;
	seven.right = NULL;
	eight.info = 11;
	eight.left = NULL;
	eight.right = NULL;
	nine.info = 4;
	nine.left = NULL;
	nine.right = NULL;
	cout << "Part 1" << endl << "The pre-order transversal looks like this:		";
	preOrder(root);
	cout << "" << endl << "The in-order transversal looks like this:		";
	inOrder(root);
	cout << "" << endl << "The post-order transversal looks like this:		";
	postOrder(root);
	cout << "" << endl;

	system("pause");
	return 0;
}

void preOrder(TreeNode* root)
{
	if (root != NULL)
	{
		cout << root->info << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(TreeNode* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->info << " ";
		inOrder(root->right);
	}
}

void postOrder(TreeNode* root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->info << " ";	
	}
} 