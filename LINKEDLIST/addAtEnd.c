
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

void addAtEnd(struct node *head, int data){
	struct node *ptr , *temp;
	ptr = head;
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = data;
	temp->link = NULL;
	
	while(ptr->link != NULL){
		ptr = ptr->link;
	}
	ptr->link = temp;
}

int main(){
	int n;
	printf("Enter a number for your linked list: \n");
	scanf("%d",&n);
	
	int b;
	printf("\nEnter a number for your linked list second element : \n");
	scanf("%d",&b);
	
	struct node *head = malloc(sizeof(struct node));
	head->data = n;
	head->link = NULL;
	printf("\nThe element of the linked list is %d\n",head->data);
	
	struct node *current = malloc(sizeof(struct node));
	current->data = b;
	current->link = NULL;
	head->link = current;
	
	printf("\nThe second element in the linked list is %d",current->data);
	
	int c;
	printf("\nEnter a number for your linked list third element: \n");
	scanf("%d",&c);
	
	current = malloc(sizeof(struct node));
	current->data = c;
	current->link = NULL;
	
	printf("\nThe third element linked list is %d",current->link->data);
	
	addAtEnd(head,67);
	struct node *ptr = malloc(sizeof(struct node));
	while(ptr !=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	
}
