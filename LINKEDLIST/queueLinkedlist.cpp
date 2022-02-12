
#include<iostream>
using namespace std;

// we first begin by creating the linked list 
struct Node{
	int data;
	Node *link;
};

// we initialise the head and taik to NULL  so we can have an empty list
Node *head = NULL;
Node *tail = NULL;

// this method is to check if the list is empty or not;
bool isempty(){
	if(head == NULL && tail == NULL){
		return true;
	}else{
		return false;
	}
}

// here , we create a new node element
void enqueue(int value){
	Node *ptr = new Node();
	// we add a value to that node and puts its link to null for the next element
	ptr->data=value;
	ptr->link=NULL;
	// if originslly , it was empty , we will have to add everything to the first and initial node
	if(head == NULL){
		head = ptr;
		tail = ptr;
	}
	// if there was already an element , we set a pointer for the next element
	else{
		tail->link = ptr;
		tail = ptr;
	}
}

// here , we delete the last elelement in the node
void dequeue(){
	if(isempty()){
		cout<<"Queue is empty\n";
	}else if(head == tail){
//		free(head);
		head == NULL;
		head  = tail = NULL; 
	}else{
		Node *ptr = head;
		head = head->link;
//		free(ptr);
		ptr = NULL;
	}
}

void showfront(){
	if(isempty()){
		cout<<"Queue is empty\n";
	}else{
		cout<<"The element at the front is :"<<head->data;
	}
}

void displayQueue(){
	if(isempty()){
		cout<<"Queue is empty\n";
	}else{
		Node *ptr = head;
		while(ptr != NULL){
			cout<<ptr->data<<" ";
			ptr = ptr->link;
		}
	}
}

int main(){
	int choice , flag=1,value;
	while(flag == 1){
		cout<<"\n1.enqueue \n2.dequeue \n3.showfront \n4.displayQueue \n5.Exit\n";
		cin>>choice;
		switch (choice){
			case 1:cout<<"Enter your value";
				cin>>value;
				enqueue(value);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				showfront();
				break;
			case 4:
				displayQueue();
				break;
			case 5:
				flag = 0;
				break;
		}
	}
	return 0;
}
