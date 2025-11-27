#include<iostream>
#include<queue>
using namespace std;

class stack {
    queue<int> q;

    public: 
    void push(int x) {
        q.push(x);
        int size=q.size();
        for(int i=0; i<size-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if(q.empty()) {
            cout<<"stack underflow"<<endl;
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }
    void top() {
        if(q.empty()) {
            cout<<"stack is empty"<<endl;
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }
    bool isEmpty() {
        return q.empty();
    }
};
int main () {
    stack st;
    st.push(5);
    st.push(15);
    st.push(25);

    st.top();
    st.pop();
    st.top();
    return 0;
}