#include<iostream>
#include<queue>
using namespace std;
int main () {
    queue<int> q;
    int n, x;
    cout << "Enter number of elements (even): ";
    cin>>n;

    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin>>x;
        q.push(x);
    }
    if(n%2!=0) {
        cout << "Interleaving not possible (odd number of elements)" << endl;
        return 0;
    }
    int half = n/2;
    queue<int> firstHalf;

    for(int i=0; i<n/2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while(!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }

    cout << "Interleaved Queue: ";
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
