#include<iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        //find min element index
        int minIndex=i;
        for(int j=i+1;j<n; j++) {
            if(arr[j]<arr[minIndex]) {
                minIndex=j;
            }
        } 
        //swap min element with ith element
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
    

}

int main() {
    int n;
    cout<<"Enter size of array : "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cout<<"Enter element "<<i+1<<" : "<<endl;
        cin>>arr[i];
    }
    selectionSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}