/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};
void  in(struct node *root,struct node_dll *dll,int *i)
{
	if (root == NULL)
	{
		return ;
	}
	else
	{

		in(root->left,dll,i);
		if (*i == 0)
		{
			if (root->data!= dll->data)
			{
				*i = 1;
			}
		}
		in(root->right,dll,i);
	}
}
int inorder(struct node *root,struct node_dll *dll){

	int i = 0;
	if (root != NULL)
	{
		in(root,dll, &i);
		return i;
	}
}
void pre(struct node *root,struct node_dll *dll,int *j)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		if (*j == 0)
		{
			if (root->data!= dll->data)
			{
				*j = 1;
			}
		}
		pre(root->left,dll,j);
		pre(root->right,dll,j);
	}
}
int preorder(struct node *root,struct node_dll *dll){
	int j = 0;
	if (root != NULL)
	{
		pre(root,dll,&j);
		return j;
	}
}
void post(struct node *root,struct node_dll *dll,int *k)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		post(root->left,dll,k);
		post(root->right,dll,k);
		if (*k == 0)
		{
			if (root->data != dll->data)
			{
				*k = 1;
			}
		}
	}

}
int  postorder(struct node *root,struct node_dll *dll){

	int k = 0;
	if (root != NULL)
	{
		post(root,dll,&k);
		return k;
	}

}
int is_identical(struct node_dll *head, struct node *root){

	int p;
	if (root&&head)
	{
		p = inorder(root, head);
		if (p == 0)
		{
			return 1;
		}
		else
		{
			p = preorder(root, head);
			if (p == 0)
			{
				return 1;
			}
			else
			{
				p = postorder(root, head);
				if (p == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return -1;
}