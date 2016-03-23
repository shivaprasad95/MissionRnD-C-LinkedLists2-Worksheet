/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {

	if (head == NULL)
		return NULL;
	
	struct node* prev = NULL;
	struct node* temp = head;
	struct node* next;
	while (temp)
	{
		next = temp->next;    //storing next node
		temp->next = prev;    //adding previous node to temp
		prev = temp;          //making added node as current node
		temp = next;		  //shifting to next node
	}

	head = prev;

	return head;
}
