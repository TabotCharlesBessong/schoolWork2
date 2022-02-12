
#include<iostream>
using namespace std;

// general structure of node
struct Node{
	int data;
	int *link;
};

// top pointer to keep track of the element at the top of the stack
Node *top = NULL;

// Function to check if the stack is empty or not

bool isempty(){
	if(top ==NULL){
		return true;
	}else{
		return false;
	}
}

// Function to insert an elelment into the stack

void push(){
	Node *ptr = new Node();
	ptr->data = value;
	ptr->link = top;
	top = ptr;
}

// funtion to delete an element from the top of the stack

void pop(){
	if(isempty()){
		cout<<"Stack is empty";
	}else{
		Node *ptr  = top;
		top = top -> link;
		delete(ptr);
	}
}

// funtion to show the top most element 

void showTop(){
	if(isempty()){
		cout<<"Stack is empty";
	}else{
		cout<<"The element at the top is: "<<top->data;
		
	}
}

// function to display all the element in the stack

void displayStack(){
	if(isempty()){
		cout<<"Stack is empty";
	}else{
		Node *temp=top;
		while(temp !=NULL){
			cout<<temp->data<<" ";
			temp=temp->link;
		}
		cout<<"\n";
	}
}

int main(){
	int choice , flag=1,value;
	while(flag == 1){
		cout<<"\n1.push \n2.pop \n3.showtop \n4.displayStack \n5.Exit\n";
		cin>>choice;
		switch (choice){
			case 1:cout<<"Enter your value";
				cin>>value;
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				showTop();
				break;
			case 4:
				displayStack();
				break;
			case 5:
				flag = 0;
				break;
		}
	}
	return 0;
}
