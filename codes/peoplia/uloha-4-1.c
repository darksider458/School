// uloha-4-1.c -- Tyzden 4 - Uloha 1
// Ronald Demeter, 13.10.2015 15:22:53

#include <stdio.h>
#include <stdlib.h>



struct Node{

	int data;
	struct Node *left;
	struct Node *right;




};

struct Node * Insert(struct Node *node, int data)
{
	if (node == NULL)
	{
		struct Node *temp;
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}

	if (data >(node->data))
	{
		node->right = Insert(node->right, data);
	}
	else if (data < (node->data))
	{
		node->left = Insert(node->left, data);
	}
	
	return node;

}

int Find(struct Node *node, int data,int pos)
{
	
	if (node == NULL)
	{
		/* Element is not found */
		return NULL;
	}
	if (data > node->data)
	{
		/* Search in the right sub tree. */
		
		return Find(node->right, data,pos+1);
	}
	else if (data < node->data)
	{
		
		/* Search in the left sub tree. */
		return Find(node->left, data,pos+1);
	}
	else
	{
		/* Element Found */
		return pos;
	}
}
int main(void){

	struct Node *root = NULL;

	int c;
  char a;
  int i = 0;
	while( scanf("%d\n",&c) != EOF){
    
		root = Insert(root, c);
		printf("%d\n", Find(root, c, 0));
	}
	return 0;
}
