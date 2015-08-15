#include <stdio.h>
#include <stdlib.h>
#include "ll_lib.h"

int main(void){
	printf("starting\n");

	struct node* head;
	head=malloc(sizeof(struct node));
	head->data=0;
	head->next=NULL;

	int i;
	for(i=0;i<10;i++){
		printf("i: %d\n",i);
		addnode(head,i+1);
	}
	printf("starting printlist\n");
	printlist(head);

	int index_fromend=3;
	struct node* rec_ptr=Nthfromend(head,index_fromend);
	if(rec_ptr!=NULL){
		printf("%dth data from end: %d\n",index_fromend,rec_ptr->data);
	}


	for(i=0;i<10;i++){
		random_addnode(head);	
	}

	printlist(head);
	

	
	return 0;

}
