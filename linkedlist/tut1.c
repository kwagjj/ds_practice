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

int main(void){
	struct node* head=NULL;
	struct node* mid=NULL;
	struct node* end=NULL;

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

	return 0;
}
