#include "ll_lib.h"


void printlist(struct node* head){
	printf("entered printlist\n");
	while(1){
		printf("%d->",head->data);
		if(head->next==NULL){
			break;
		}
		head=head->next;
	}
	printf("NULL\n");
}

void testfunc(void){
	printf("this is test");
}

void addnode(struct node* head, int data){
	struct node* newnode;
	newnode=malloc(sizeof(struct node));
	
	newnode->data=data;
	newnode->next=NULL;

	while(1){
		if(head->next==NULL){
			head->next=newnode;
			break;
		}
		head=head->next;
	}
}

int getlength(struct node* head){
	int count=0;
	while(1){
		printf("endtered whileloop\n");
		count++;
		if(head->next==NULL){
			printf("reached end node\n");
			return count;
		}
		head=head->next;
	}
	return -1;
}


struct node* Nthfromend(struct node* head,int index){
	printf("entered Nthfromend\n");
	int len=getlength(head);
	printf("len: %d\n",len);
	if(index>len){
		printf("index larger than length\n");
		return NULL;
	}
	int stop=len-index;
	int i;
	for(i=0;i<stop;i++){
		head=head->next;
	}
	return head;

}

void random_addnode(struct node* head){
	addnode(head,rand()%10);
}

int count_node_with_key(struct node* head, int key){
	int count=0;
	while(1){
		if(head->data==key){
			count++;
		}
		if(head->next==NULL){
			return count;
		}
		head=head->next;
	}
}
