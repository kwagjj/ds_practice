#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void printlist(struct node* head);

void testfunc(void);

void addnode(struct node* head, int data);

int getlength(struct node* head);

struct node* Nthfromend(struct node* head,int index);


void random_addnode(struct node* head);

int count_node_with_key(struct node* head, int key);
