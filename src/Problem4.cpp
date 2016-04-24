/*

Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.

Example 1:
Input : 
   20        25
  /  \      /  \
 5    30   10   35
Output :
Bst 1 :
     20
   /   \
  5     30
   \   /  \
   10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,Any 1 of those correct ways would be fine .
Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs 
(Both r1 and r2 shouldnt be NULL at the time of Input)

Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.

You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard 
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
void in(struct node *root, int *arr, int *i)
{
	int j;
	if (root == NULL)
	{
		return;
	}
	else
	{

		in(root->left, arr, i);
		j = *i;
		(*i)++;
		arr[j] = root->data;

		in(root->right, arr, i);
	}
}
void inorder(struct node *root, int *arr){

	int i = 0;
	if (root != NULL)
	{
		in(root, arr, &i);
	}
}
int count(struct node *root2)
{
	int c = 1;

	if (root2== NULL)
		return 0;
	else
	{
		c += count(root2->left);
		c += count(root2->right);
		return c;
	}
}
struct node *newNode(int d)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node)*1);
	temp->data = d;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node* node, int *d)
{
	if (node == NULL) 
		return newNode(*d);
	if (*d< node->data)
		node->left = insert(node->left,d);
	else if (*d > node->data)
		node->right = insert(node->right,d);
	return node;
}
void merge_two_bst(struct node *root1, struct node *root2){
	int *arr,len,i=0;
	struct node *temp;
	if (root1&&root2)
	{
		len = count(root2);
		arr = (int *)malloc(sizeof(int)*len);
		inorder(root2, arr);
		temp = (struct node *)malloc(sizeof(struct node) * 1);
		while (i < len)
		{
			temp = root1;
			insert(temp, &arr[i]);
			i++;
		}
	}
}