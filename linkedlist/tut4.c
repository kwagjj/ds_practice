#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	
int iterative_count(struct node* head){
	int count=1;
	struct node* temp;
	temp=head;
	while(temp->next!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

int recursive_count(struct node* head){
	if(head->next==NULL){
		return 1;
	}
	return 1+recursive_count(head->next);
}

bool iterative_search(struct node* head, int key){
	while(1){
		if(head->data==key){
			return true;
		}
		if(head->next==NULL){
			return false;
		}
		head=head->next;
	}
}

bool recursive_search(struct node* head, int key){
	if(head->data==key){
		return true;
	}
	if(head->next==NULL){
		return false;
	}
	return recursive_search(head->next,key);
}

int getNth(struct node* head,int index){
	
	if(index<=0){
		printf("invalid index number\n");
		return -1;
	}
	int count=1; // match with index which starts with 1;
	while(1){
		
		if(count==index){
			return head->data;
		}
		if(head->next==NULL){
			printf("index larger than list length. returning zero\n");
			return 0;
		}
		count++;
		head=head->next;
	}
	return 0;
}

int checkendnode(struct node* targetnode, struct node* head){
	while(head->next!=NULL){
		head=head->next;
	}
	if(targetnode==head){
		return 1;
	}
	return 0;
}

int deletenode(struct node* delnode,struct node* head){
	//must check is delnode is end node. if so, need special treatment
	if(checkendnode(delnode,head)){
		return 1;
	}
	struct node* temp;
	temp=delnode->next;
	delnode->data=temp->data;
	delnode->next=temp->next;
	free(temp);
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

	printf("iterative count:%d \n",iterative_count(head));

	printf("recursive count:%d \n",recursive_count(head));

	printf("iterative search for key=3: %d\n",iterative_search(head,3));

	printf("recursive search for key=5: %d\n",recursive_search(head,5));

	printf("2nd node data: %d\n",getNth(head,6));
	
	printf("delete node\n");
	if(deletenode(head,head)){
		printf("cannot delete since it is last node\n");
	}
	else{
		printlist(head);
	}
	return 0;
}
