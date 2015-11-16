/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

void divide(struct node* source, struct node** firstList, struct node** secondList) {
	struct node* travOnce;
	struct node* travTwice;
	if (source == NULL || source->next == NULL) {
		*firstList = source;
		*secondList = NULL;
	}
	else {
		travOnce = source;
		travTwice = source->next;
		while (travTwice != NULL) {
			travTwice = travTwice->next;
			if (travTwice != NULL)
			{
				travOnce = travOnce->next;
				travTwice = travTwice->next;
			}
		}
		// travOnce is in middle of list, so spliatting at it
		*firstList = source;
		*secondList = travOnce->next;
		travOnce->next = NULL;
	}
}

struct node* merge(struct node* a, struct node* b) {
	struct node* result = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	if (a->num <= b->num) {
		result = a;
		result->next = merge(a->next, b);
	}
	else {
		result = b;
		result->next = merge(a, b->next);
	}
	return result;
}

void mergeSort(struct node ** headPtr) {
	// one or no nodes
	if (!*headPtr || !((*headPtr)->next))
		return;
	// splitting into halves
	struct node *firstHalf, *secondHalf;
	divide(*headPtr, &firstHalf, &secondHalf);
	// sorting two halves and merging them
	mergeSort(&firstHalf);
	mergeSort(&secondHalf);
	*headPtr = merge(firstHalf, secondHalf);
}

struct node * sortLinkedList(struct node *head) {
	mergeSort(&head);
	return head;
}