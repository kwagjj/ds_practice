#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void printlist(struct node* start){
	struct node* temp=start;
	do{
		printf("data: %d\n",temp->data);
		temp=temp->next;

	}
	while(temp!=start);

}

void insert_after(struct node* targetnode, int newdata){
	struct node* newnode;
	newnode=malloc(sizeof(struct node));
	newnode->next=targetnode->next;
	targetnode->next=newnode;
	newnode->data=newdata;
}

void insert_front(struct node* newnode,int newdata, struct node* head){
	newnode->data=head->data;
	newnode->next=head->next;

	head->data=newdata;
	head->next=newnode;

}

void insert_end(struct node* head, int newdata){
	struct node* newnode;
	newnode=malloc(sizeof(struct node));

	
}

void delete_node(struct node* head,int key){
	struct node* temp;
	temp=head;
	do{
		if(temp->data==key){
			
		}
	}
	
}

int main(void){
	struct node* head;
	struct node* mid;
	struct node* end;

	head=(struct node*)malloc(sizeof(struct node));
	mid=(struct node*)malloc(sizeof(struct node));
	end=(struct node*)malloc(sizeof(struct node));

	head->data=1;
	head->next=mid;

	mid->data=2;
	mid->next=end;

	end->data=3;
	end->next=head;

	printlist(head);

	struct node* newnode;
	newnode=malloc(sizeof(struct node));
	insert_front(newnode,0,head);

	printlist(head);

	insert_after(mid,5);
	printlist(head);

	return 0;
}
