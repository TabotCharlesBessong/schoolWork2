// FE20A106
//TABOT CHARLES BESSONG
#include<iostream>
using namespace std;

int partition(int *B,int start ,int end){
	int pivot = B[end];
	int pIndex = start;
	for(int i=start;i<end;i++){
		if(B[i] <= pivot){
			swap(B[i], B[pIndex]);
			pIndex ++;
		}
	}
	swap(B[pIndex],B[end]);
	return pIndex;
}

void quickSortMin(int *B ,int start ,int end){
	if(start < end){
		int pIndex = partition (B , start ,end);
		quickSortMin(B , start , pIndex - 1);
		quickSortMin(B , pIndex + 1, end);
	}
	
}



void quickSortMax(int *B ,int start ,int end){
	if(start > end){
		int pIndex = partition (B , end,start);
		
		quickSortMax(B , pIndex - 1 , start  );
		quickSortMax(B ,  end  ,pIndex + 1);
	}
	
}

int main(){
	
	int B[] = {2,7,34,23,4,1,9,5,3,-4,14,8,-1};
	int n = sizeof(B)/sizeof(B[0]);
	cout<<"\n"<<"This is for minimum for quick sort algo"<<"\n";
	cout<<"\n";
	quickSortMin(B,0,12);
	for (int i = 0 ;i< n ;i++)
		cout<<B[i]<<"\n";
		
	cout<<"\n"<<"This is for maximum for quick sort algo"<<"\n";
	cout<<"\n";
	quickSortMax(B,0,12);
	for (int i = 0 ;i< n ;i++)
		cout<<B[i]<<"\n";
	
	return 0;
}
