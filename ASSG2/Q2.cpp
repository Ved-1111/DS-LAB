#include<iostream>
using namespace std;
int main(){
	//bubble sort
	int n,i,j;
	int arr[]={64, 34, 25, 12, 22, 11, 90};
	n=sizeof(arr)/sizeof(arr[0]);//calculate size of array
	for(i=0;i<n-1;i++){//outer loop for number of passes
	for(j=0;j<n-i-1;j++){//inner loop for each pass 
		int temp;//temporary variable for swapping
		if(arr[j]>arr[j+1]){//if current element is greater than next
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;//swap elements
		}
	}
	
}
for(i=0;i<n;i++)
cout<<" "<<arr[i];
	return 0;
}