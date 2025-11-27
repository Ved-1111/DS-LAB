#include<iostream>
using namespace std;
void mergeArrays(int arr[], int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;

    int L[n1];
    int R[n2];
    int k = left;

    for(int i=0; i<n1; i++) {
        L[i]=arr[left+i];
    }
    for(int j=0; j<n2; j++) {
        R[j]=arr[mid+j+1];
    }

    int i=0;
    int j=0;
    while(i<n1 && j<n2) { 
        if(L[i]<R[j]) {
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
        k++;

    }
    while(i<n1) {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left<right) {
        int mid=(left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        mergeArrays(arr, left, mid, right);
    }   
}

int main () {
    int n;
    cout<<"Enter size of array : "<<endl;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++) {
        cout<<"Enter value "<<i+1<<" : "<<endl;
        cin>>arr[i];
    }

    cout<<"Unsorted array : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr, 0, n-1);
    cout<<"Sorted array : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}