#include<iostream>
using namespace std;

int main() {
    int n;
    int arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {//input array 
    cin >> arr[i];
    }
    for(int i = 0; i < n; i++){//traverse the array
        for(int j = i + 1; j < n; j++){ //check for duplicates
            if(arr[i] == arr[j]) {//if duplicate found
    for(int k = j; k < n - 1; k++) {//remove duplicate by shifting elements from right to left
    arr[k] = arr[k + 1];//shift elements to left
    }
    n--;//reduce size of array  
    j--;//adjust index after removal
    }
   }
 }

    cout << "Array after removing duplicates: ";
    for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }

    return 0;
}
