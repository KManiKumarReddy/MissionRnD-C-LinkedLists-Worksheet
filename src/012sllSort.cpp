/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	struct node * start = head;
	// leaving heading 0s
	while (start && !(start->data)) start = start->next;
	if (!start) return;
	// counting 0s, 1s and 2s
	struct node * temp = start;
	int count[3] = { 0, 0, 0 };
	do count[temp->data] ++; while (temp = temp->next);
	// changing data to 0s, 1s and 2s depending on their count
	while (count[0]--) {
		start->data = 0;
		start = start->next;
	}
	while (count[1]--) {
		start->data = 1;
		start = start->next;
	}
	while (count[2]--) {
		start->data = 2;
		start = start->next;
	}
}