/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	struct node *temp = head;
	struct node *temp1,*knode;

	int swit = 0;
	int count = 0;
	int flag = 0;

	if (K <= 0 || head == NULL)
		return NULL;

	while (temp)
	{

		
		if((count+1)% K == 0 && flag == 0) {  //if K to be inserted in next node and not already inserted(flag ==0)

			knode = (struct node*)malloc(sizeof(struct node)); //allocating memory to new node
			knode->num = K;    //adding values to node
			knode->next = NULL;

			temp1 = temp->next;     //storing next node in temp1
			temp->next = knode;		//adding new node to temp
			knode->next = temp1;	//adding back actual nodes after adding new node
			
			temp = temp->next;
			flag = 1;        //to know the node is inserted

		}
		else{
			flag = 0;         
			count++;
			temp = temp->next;  
		}
	}
	return head;
}
