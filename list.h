#ifndef __LIST_H
#define __LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*freefunction)(void *);
typedef enum {FALSE, TRUE} bool;
typedef bool (*listIterator)(void *);

typedef struct node{
	void *data;
	struct node *next;
}Node;

Node* append(Node*, void *);
int sizeList(Node *);
void* getData(Node *, int);
int findInList(Node *, void*);

#endif