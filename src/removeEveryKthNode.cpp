/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (!head || K < 1)
		return NULL;
	if (K == 1) {
		while (head) {
			struct node * temp = head;
			head = head->next;
			free(temp);
		}
		return NULL;
	}
	struct node * temp = head;
	int check = K - 2;
	while (temp) {
		if (check--) temp = temp->next;
		else {
			check = K - 2;
			if (temp->next) {
				struct node * temp1 = temp->next;
				temp->next = temp1->next;
				free(temp1);
				temp = temp->next;
			}
			else
				return head;
		}
	}
	return head;
}