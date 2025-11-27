#include <iostream>
#include <queue>
using namespace std;

class Stack2Q {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);

    }
    void pop() {
        if(q1.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    void top() {
        if(q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    bool isEmpty() {
        return q1.empty();
    }
};
        int main() {
    Stack2Q st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.top();
    st.pop();
    st.top();

    return 0;
}