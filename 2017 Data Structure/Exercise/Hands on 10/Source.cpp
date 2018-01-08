//Justin Seda
//CPSC 250 10am
//Hancds-on 10
#include<iomanip>
#include<iostream>

using namespace std;


struct  Node
{
	int small;
	int large;
	Node* left;
	Node* middle;
	Node* right;
};

void inOrder(Node*);

int main()
{
	Node one, two, three, four, five, six, seven, eight, nine, ten, eleven;
	Node* root;

	root = &one;
	one.small = 50;
	one.large = 90;
	one.left = &two;
	one.middle = &three;
	one.right = &four;

	two.small = 20;
	two.large = NULL;
	two.left = &five;
	two.middle = NULL;
	two.right = &six;

	three.small = 70;
	three.large = NULL;
	three.left = &seven;
	three.middle = NULL;
	three.right = &eight;

	four.small = 120;
	four.large = 150;
	four.left = &nine;
	four.middle = &ten;
	four.right = &eleven;

	five.small = 10;
	five.large = NULL;
	five.left = NULL;
	five.middle = NULL;
	five.right = NULL;

	six.small = 30;
	six.large = 40;
	six.left = NULL;
	six.middle = NULL;
	six.right = NULL;

	seven.small = 60;
	seven.large = NULL;
	seven.left = NULL;
	seven.middle = NULL;
	seven.right = NULL;

	eight.small = 80;
	eight.large = NULL;
	eight.left = NULL;
	eight.middle = NULL;
	eight.right = NULL;

	nine.small = 100;
	nine.large = 110;
	nine.left = NULL;
	nine.middle = NULL;
	nine.right = NULL;

	ten.small = 130;
	ten.large = 140;
	ten.left = NULL;
	ten.middle = NULL;
	ten.right = NULL;

	eleven.small = 160;
	eleven.large = NULL;
	eleven.left = NULL;
	eleven.middle = NULL;
	eleven.right = NULL;

	cout << "Here's the Inorder : ";
	inOrder(root);
	cout << endl;
	system("pause");
}


void inOrder(Node* root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->middle == NULL && root->right == NULL)
		{
			cout << root->small << " ";
		}
		else if (root->small != NULL && root->large != NULL)
		{
			inOrder(root->left);
			cout << root->small << " ";
			inOrder(root->middle);
			cout << root->large << " ";
			inOrder(root->right);
		}
		else
		{
			inOrder(root->left);
			cout << root->small << " ";
			inOrder(root->right);
		}
	}
}