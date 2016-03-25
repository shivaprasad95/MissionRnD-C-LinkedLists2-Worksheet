/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	
	struct node *head = NULL, *current = NULL;

	if (head1 == NULL && head2 == NULL) //return NULL for error condition
		return NULL;
	if (head1 == NULL)   //return head2 if head1 is NULL
		return head2;
	else if (head2 == NULL)   //return head1 if head2 is NULL
		return head1;

	while ((head1 != NULL) && (head2 != NULL))   //till head1 and head2 not NULL
	{
		struct node *temp = (struct node *)malloc(sizeof(struct node)); //create new node
		if (head1->num  < head2->num)  //compare head1 num with head2 num
		{
			temp->num = head1->num;  //if head1 num is less,insert it into temp
			temp->next = NULL;      
			head1 = head1->next;	 
		}
		else
		{
			temp->num = head2->num;  //if head2 num is less,insert it into temp
			temp->next = NULL;
			head2 = head2->next;

		}
		if (head == NULL)  //assigning temp to head and current
		{
			head = temp;
			current = head;
		}
		else
		{
			current->next = temp;     //if head still has nodes append current to temp
			current = temp;
		}


	}


	while (head1 != NULL)  //insert remaining nodes in head1 to current
	{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->num = head1->num;
		temp->next = NULL;
		current->next = temp;
		current = temp;
		head1 = head1->next;
	}
	while (head2 != NULL)  //insert remaining nodes in head2 to current
	{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->num = head2->num;
		temp->next = NULL;
		current->next = temp;
		current = temp;
		head2 = head2->next;
	}


	return head;


}
