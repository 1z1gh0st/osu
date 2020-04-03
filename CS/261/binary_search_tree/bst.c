#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
};

void insert_node_to_tree(struct Node **head, int value_in)
{
	struct Node *temp = malloc(sizeof(struct Node));
	temp->value = value_in;
	temp->left = NULL;
	temp->right = NULL;
	if (*head == NULL)
		*head = temp;
	else
	{
		struct Node *curr = *head;
		while (curr != NULL)
		{
			if (curr->value > value_in)
			{
				if (curr->right == NULL)
					curr->right = temp;
				curr = curr->right;	
			}
			else if (curr->value < value_in)
			{
				if (curr->left == NULL)
					curr->left = temp;
				curr = curr->left;
			}
			else
			{
				return;
			}
		}
	}
}

bool is_in_tree(struct Node *head, int value)
{
	if (head == NULL)
		return false;
	else
	{
		struct Node *curr = head;
		while (curr != NULL)
		{
			if (curr->value > value)
			{
				curr = curr->right;	
			}
			else if (curr->value < value)
			{
				curr = curr->left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
}

int main() 
{
	struct Node *head = NULL;
	insert_node_to_tree(&head, 5);
	insert_node_to_tree(&head, 2);
	insert_node_to_tree(&head, 9);
	insert_node_to_tree(&head, 1);
	insert_node_to_tree(&head, 10);
	insert_node_to_tree(&head, 8);
	insert_node_to_tree(&head, 0);
	printf("8 [%d]\n", is_in_tree(head, 8));
	printf("1 [%d]\n", is_in_tree(head, 2));
	printf("3 [%d]\n", is_in_tree(head, 3));
	return 0;
}

