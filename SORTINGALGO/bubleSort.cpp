 #include<iostream>
 using namespace std;
 
 void bubbleSortMin(int B[] , int n){
 	for(int k = 0;k<n-1;k++){
		 // with this algorithm , we will alaways start at the begining  of the array 
 		int flag = 0;
 		for (int i = 0;i< n-1;i++){
			 // this loop we will iterate and swap the vaues  to arrange them depending on if we want it to be  from lowest to highest or vice-versa 
 			if(B[i] > B[i+1]){
 				swap(B[i] , B[i+1]);
				 // this value of flag = 1 gives us the permission to swap the values 
 				flag = 1;
			 }
		 }
		 // when ever  we reach a values of 0 we stop telling us that we need to stop the iteration 
		 if(flag == 0)
		 	break;
	 }
 }
 
 void bubbleSortMax(int B[] , int n){
 	for(int k = 1;k<n;k++){
 		int flag = 0;
 		for (int i = 0;i< n-k;i++){
 			if(B[i] < B[i+1]){
 				swap(B[i] , B[i+1]);
 				flag = 1;
			 }
		 }
		 if(flag == 0)
		 	break;
	 }
 }
 
 int main(){
 	int B[] = {2,7,34,23,4,1,9,5,3,-4,14,8,-1};
	int n = sizeof(B)/sizeof(B[0]);
	cout<<"\n"<<"This is for minimumbb for bubble sort algo"<<"\n";
	cout<<"\n";
	bubbleSortMin(B,n);
	for (int i = 0 ;i< n ;i++)
		cout<<B[i]<<"\n";
		
	cout<<"\n"<<"This is for maximum for bubble sort algo"<<"\n";
	cout<<"\n";
	bubbleSortMax(B,n);
	for (int i = 0 ;i< n ;i++)
		cout<<B[i]<<"\n";
 }
