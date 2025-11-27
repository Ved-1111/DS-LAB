#include <iostream>
using namespace std;

#define MAX 5   // size of circular queue

class CQueue {
    int arr[MAX];
    int front, rear;

public:
    CQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty(CQueue q) {
        if(q.front == -1) {
            return true;
        }
        else return false;
    }

    bool isFull(CQueue q) {
        // corrected condition → next position becomes front
        if ((q.rear + 1) % MAX == q.front) {
            return true;
        }
        else return false;
    }

    CQueue enqueue(CQueue q, int value) {
        if(isFull(q)) {
            cout << "Overflow" << endl;
            return q;
        }

        if(q.front == -1) {
            q.front = 0;
        }

        q.rear = (q.rear + 1) % MAX;
        q.arr[q.rear] = value;

        cout << value << " enqueued successfully!" << endl;
        return q;
    }

    CQueue dequeue(CQueue q) {
        if(isEmpty(q)) {
            cout << "Underflow" << endl;
            return q;
        }

        cout << q.arr[q.front] << " dequeued successfully!" << endl;

        if(q.front == q.rear) {   // only one element
            q.front = -1;
            q.rear = -1;
            return q;
        }

        q.front = (q.front + 1) % MAX;
        return q;
    }

    CQueue peek(CQueue q) {
        if(q.front == -1) {
            cout << "Queue is empty" << endl;
            return q;
        }
        cout << q.arr[q.front];
        return q;
    }

    CQueue display(CQueue q) {
        if(q.front == -1) {
            cout << "Queue is empty" << endl;
            return q;
        }
        int i=q.front;
        while (i!=q.rear) 
        {
            cout<<q.arr[i]<<" ";
            i=(i+1)%MAX;
        }
            cout<<q.arr[q.rear]<<endl;

        return q;
        

    }
};

int main() {
    CQueue q;
    int choice, value;

    while (true) {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n5.Peek\n6.isFull\n7.isEmpty\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                q = q.enqueue(q, value);
                break;

            case 2:
                q = q.dequeue(q);
                break;

            case 3:
                q=q.display(q);
                break;

            case 4:
                return 0;
                break;

            case 5: 
                q=q.peek(q)  ;  
                break;

            case 6:
                if(q.isFull(q)) {
                    cout<<"Full"<<endl;
                }
                else cout<<"Not full"<<endl;
                break;

            case 7:
                if(q.isEmpty(q)) {
                    cout<<"Empty"<<endl;
                }
                else cout<<"Not empty"<<endl;
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
