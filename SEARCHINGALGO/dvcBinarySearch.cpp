#include<bits/stdc++.h>

  using namespace std;

   int Binary_search(int arr[],int l,int r, int value)
 
  {
       if(l<=r)
     {
         int mid = l+((r-l)/2);
         
         if(arr[mid]==value)
          return 1;
          
          else if(arr[mid]>value)
           return Binary_search(arr,l,mid-1,value);
           
           else
             return Binary_search(arr,mid+1,r,value);
     }
     
     return 0;
 }

   int main()
 {
//   int arr[]={3,4,5,6,7,8,4,5,2,8,9,13,14,17,19};
	int n;
	cout<<"Enter array size";
	cin>>n;
	int arr[n];
	
   
//   int n=sizeof(arr)/sizeof(arr[0]);
   
   for(int i = 0;i<n;i++){
   	cout<<"Enter element arr["<<i<<"]Element: ";
   	cin>>arr[i];
   }
   
    int value;
    cout<<"Enter element to be searched";
    cin>>value;
    int index = Binary_search(arr,0,n-1,value);
   
   sort(arr,arr+n);
   cout <<"Element"<<value<<"found at"<<index;
   
//    if(Binary_search(arr,0,n-1,value))
//     cout<<"key is found in given array"<<endl;
//     
//     else
//      cout<<"key is not found in given array"<<endl;
 }
