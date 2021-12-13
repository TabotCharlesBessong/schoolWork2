#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

void addPos(struct node* head, int data , int position){
	struct node *ptr = head;
	struct node *ptr2 = malloc(sizeof(struct node));
	ptr2->data = data;
	ptr2->link = NULL;
	
//	position--;
	while(position !=2){
		ptr = ptr->link;
		position--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;
}

int main(){
	struct node *head = malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;
	
	addPos(head,78,2);
	addPos(head,65,2);
	addPos(head,34,3);
	addPos(head,89,1);
	struct node *ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	return 0;
}
