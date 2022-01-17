#include<iostream>
using namespace std;
void selectionSortMin(int A[] , int n){
	// this loop enables us to transverse through the whole array 
	for (int i =0;i< n-1;i++){
		// here , we store and  decide that by default the i = 0 is our minimum value 
		int iMin = i ;
			// this second  interation helps in comparison 
		for(int j = i+1;j<n;j++){
			// so if the next value is smaller  than that at i = 0 , we will have  to upfate the value  of our minimum variable
			if(A[j] < A[iMin])
				iMin = j;
		}
		// here we are simply swapping  between the values 
		// if we  ever encounterd  a  situation  where the next value was smaller then we will have  to dwap 
		int temp = A[i];
		A[i] = A[iMin];
		A[iMin] = temp;
		// after this we  continue our iteration while the condition is still true 
	}
}

// same  changes apply , here except tha here we are dealing with maximum 
void selectionSortMax(int A[] , int n){
	for (int r = 0;r<n-1;r++){
		int rMax = r;
		for(int s=r+1;s<n;s++){
			if(A[s] > A[rMax])
				rMax = s;
		}
		int temp1 = A[r];
		A[r] = A[rMax];
		A[rMax] = temp1;
	}
}

int main(){
	int A[] = {2,7,4,1,9,5,3,-4,14,-1};
	int n = sizeof(A)/sizeof(A[0]);
	cout<<"\n"<<"This is for minimum for selection sort algo"<<"\n";
	cout<<"\n";
	selectionSortMin(A,n);
	for (int i = 0 ;i< n ;i++)
		cout<<A[i]<<"\n";
	
	cout<<"\n"<<"This is for maximum for selection sort algo"<<"\n";
	cout<<"\n";
	selectionSortMax(A,n);
	for (int i = 0 ;i< n ;i++)
		cout<<A[i]<<"\n";
}


// selection sort algorithm is a sorting algorithm where the you compare one number  with the next until you reach the end og the  list .
// I.E you  compare  the  first and the  second the you move to the  the third and everytime  that the next is  smaller , you skeep 