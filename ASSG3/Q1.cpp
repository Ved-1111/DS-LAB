#include<iostream>
using namespace std;
#define MAX 100
    int top=-1;
    int arr[MAX];
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == MAX - 1;
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
        cout<<x<<" pushed to stack"<<endl; 
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<arr[top]<<" popped from stack"<<endl;
        top--;
    }
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Top element is "<<arr[top]<<endl;
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Stack elements are: ";
        for(int i=top; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }

int main(){
    int choice, value;
    while(true){
        cout<<"\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n";
        cin>>choice;
    switch(choice){
        case 1:
            cout<<"Enter value to push: ";
            cin>>value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if(isEmpty())
                cout<<"Stack is empty"<<endl;
            else
                cout<<"Stack is not empty"<<endl;
            break;
        case 5:
            if(isFull())
                cout<<"Stack is full"<<endl;
            else
                cout<<"Stack is not full"<<endl;
            break;
        case 6:
            display();
            break;
        case 7:
            return 0;
        default:
            cout<<"Invalid choice"<<endl;
    }
    }
    return 0;
        }