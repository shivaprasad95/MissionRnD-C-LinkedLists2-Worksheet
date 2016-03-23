/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	
	int length = 0;
	int size = 0;
	int num = 0;
	int evenFlag = 0;
	int oddFlag = 0;
	int flag = 0;

	struct node *temp = head;

	if (head == NULL) //if head is NULL return -1
		return -1;

	while (temp!=NULL)
	{
		length++;

		if (temp->next == NULL && flag == 0)
		{
			size = length;
			if (length % 2 == 0)
				evenFlag = 1;
			else
				oddFlag = 1;
			flag = 1;
			length = 1;
			temp = head;
		}

		if (oddFlag == 1)  //if odd length 
		{
			if (length-1 == size / 2)
				return temp->num;
		}
		else if (evenFlag == 1)   //if even length
		{ 
			if (length-1 == (size / 2)- 1)
				return (temp->num +temp->next->num) / 2;
		}

		
		temp = temp->next;
	} 
}
