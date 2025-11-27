#include<iostream>

using namespace std;
#define MAX 5
class queue {
    int arr[MAX];
    int front, rear;

    public:
        queue() {
            front=-1;
            rear=-1;
        }

        bool isEmpty() {
            if((front==-1 && rear==-1) || front>rear) {
                return true;
            }
            else return false;
        }

        bool isFull() {
            if(rear>=MAX-1) {
               
                return true;
            }
            else return false;
        }

        void enqueue (int value) {
            if(isFull()) {
                cout<<"Overflow"<<endl;
                
                return;
            }
            if(front==-1 && rear == -1) {
                front++;
            }  
            rear++;
            arr[rear]=value;
            cout << value << " enqueued successfully!" << endl;
            
        }

        void dequeue() {
            if(isEmpty()) {
                cout<<"Underflow"<<endl;
                return;
            }
            front++;
            cout << arr[front-1] << " dequeued successfully!" << endl;
            if(front>rear) {
                front=rear=-1;
            }
        }

        void peek() {
            if(isEmpty()) {
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<arr[front];
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return;
            }
            int temp = front;
            while(temp<=rear) {
                cout<<arr[temp]<<" ";
                temp++;
            }
            cout<<endl;
        }
};

int main() {
    queue q;
    int choice, value;

    while (true) {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is empty!" : "Queue is not empty!") << endl;
            break;
        case 6:
            cout << (q.isFull() ? "Queue is full!" : "Queue is not full!") << endl;
            break;
        case 7:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}