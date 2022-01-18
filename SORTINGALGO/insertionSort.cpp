#include<iostream>
using namespace std;

void insertionSortMin(int C[] , int n ){
	// just like  in all other  algorithm , this loop enables us to iterate the whole algorithm 
	for(int i = 0;i<n;i++){
		// take the value in the first index and create a hole  in that index 
		int value = C[i];
		int hole = i;
		// in this loop , we are here to make sure that we swap values if a  vakue less than the innitial value is met 
		while(hole > 0 && C[hole-1] > value ){
			C[hole] = C[hole-1];
			// since  we are using insertion sorting algorithm , we will have  to update the  position of our hole  everytime  we swap values 
			hole--;
		}
		C[hole] = value;
	}
}

void insertionSortMax(int C[] , int n ){
	for(int i = 0;i<n;i++){
		int value = C[i];
		int hole = i;
		while(hole > 0 && C[hole-1] < value ){
			C[hole] = C[hole-1];
			hole--;
		}
		C[hole] = value; 
	}
}

int main(){
	int C[] = {2,7,34,23,4,1,9,5,3,-4,14,8,-1};
	int n = sizeof(C)/sizeof(C[0]);
	cout<<"\n"<<"This is for minimum for insertion sort algo"<<"\n";
	cout<<"\n";
	insertionSortMin(C,n);
	for (int i = 0 ;i< n ;i++)
		cout<<C[i]<<"\n";
		
	cout<<"\n"<<"This is for maximum for insertion sort algo"<<"\n";
	cout<<"\n";
	insertionSortMax(C,n);
	for (int i = 0 ;i< n ;i++)
		cout<<C[i]<<"\n";
}
