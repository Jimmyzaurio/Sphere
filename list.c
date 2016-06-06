#include "list.h"
#include "R3Coord.h"

Node* append(Node *head, void *element) {
	Node *n = NULL;
	n = (Node*)malloc(sizeof(Node));
	n->data = malloc(sizeof(R3Coord));
	memcpy(n->data, element, sizeof(R3Coord));	
	n->next = NULL;

	if (head == NULL) {
		head = n;
	} else {
		Node *last = head;
		while (last->next != NULL)
			last = last->next;
		last->next = n;
	}
	return head;
}

void* getData(Node *head, int pos) {
	Node *ptr;
	int i = 1;
	for (ptr = head; ptr; ptr = ptr->next, i++)
		if (i == pos)
			break;	
	return ptr->data;	
}

int findInList(Node *head, void* elto) {	
	for (; head; head = head->next) {
		if (equalR3Coord(*(R3Coord *)head->data, *(R3Coord *)elto))
			return 1;
	}
	return 0;
}