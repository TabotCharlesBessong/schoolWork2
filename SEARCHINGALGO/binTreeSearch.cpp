// Binary Search IN a Tree 
#include<iostream>
using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

// Creating a new Node
BstNode* GetNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


// this function is to insert data into a node
BstNode* Insert(BstNode* root , int data){
	if(root == NULL){
		root = GetNewNode(data);
		return root;
	}
	else if(data <= root->data){
		root->left = Insert(root->left , data);
	}
	else{
		root->right = Insert(root->right , data);
	}
	return root;
}

bool Search(BstNode* root , int data){
	if(root == NULL)
		return false;
	if(root->data == data)
		return true;
	else if(data <= root->data)
		return Search(root->left,data);
	else
		return Search(root->right, data);
}

int main(){
	BstNode* root = NULL;
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,27);
	root = Insert(root,9);
	root = Insert(root,30);
	root = Insert(root,7);
	root = Insert(root,34);
	root = Insert(root,78);
	
	int number;
	cout<<"Enter number to be searched\n";
	cin>>number;
	if(Search(root,number) == true)
		cout<<"Found\n";
	else
		cout<<"Not found \n";
}
