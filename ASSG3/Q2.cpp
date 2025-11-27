#include<iostream>
using namespace std;
#define MAX 100
int top=-1;
char arr[MAX];
bool isEmpty(){
    return top == -1;
}
bool isFull(){
    return top == MAX - 1;
}
void push(char x){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    arr[top] = x;
}
void pop(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    top--;
}
void reverseString(){//function to reverse the string
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Reversed string: ";
    while(!isEmpty()){//
        cout<<arr[top];//print top character
        pop();//remove top character from stack
    }
    cout<<endl;
}
int main(){
    string str;//input string
    cout<<"Enter a string: ";//prompt user to enter a string
    cin>>str;//get the string input
    for(int i=0; i<str.length(); i++){
        push(str[i]);//push each character onto the stack
    }
    cout<<"Reversed string: ";
    reverseString();//call function to reverse the string
    return 0;
}