#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void printlist(struct node* head){
	struct node* temp;
	temp=head;
	while(1){
		printf("data: %d\n",temp->data);
		if(temp->next==NULL){
			break;
		}
		temp=temp->next;
	}
}

int delete_key(struct node* head, int key){
	struct node* temp;
	struct node* prev;


	prev=NULL;
	temp=head;
	while(1){
		if(temp->data==key){
			prev->next=temp->next;
			free(temp);	
			break;
		}
		prev=temp;
		if(temp->next==NULL){
			return 1; //  there is no match with key
		}
		temp=temp->next;
		
	}

	return 0;
}


int main(void){
	struct node* head;
	struct node* second;
	struct node* end;

	head=malloc(sizeof(struct node));
	second=malloc(sizeof(struct node));
	end=malloc(sizeof(struct node));
	
	head->data=1;
	head->next=second;

	second->data=2;
	second->next=end;

	end->data=3;
	end->next=NULL;

	printlist(head);

	printf("delete test\n");
	if(delete_key(head,5)){
		printf("no match with key found. nothing is deleted\n");
	}
	printlist(head);

	return 0;
}
