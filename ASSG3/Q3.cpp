#include<iostream>
#include<string>
using namespace std;
#define MAX 100
char arr[MAX];
int top=-1;
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
char peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return '\0';
    }
    return arr[top];
}
bool match(char opening, char closing){//function to check if opening and closing brackets match
    if(opening == '(' && closing == ')') return true;
    if(opening == '{' && closing == '}') return true;
    if(opening == '[' && closing == ']') return true;
    return false;
}
bool isBalanced(string expr){//function to check if brackets are balanced
    for(int i=0; i<expr.length(); i++){//traverse the expression
        char current = expr[i];//get the current character
        if(current == '(' || current == '{' || current == '['){//if it's an opening bracket, push it to stack
            push(current);
        }
        else if(current == ')' || current == '}' || current == ']'){//if it's a closing bracket 
            if(isEmpty() ){//stack should not be empty
                return false;
            }
            char topChar = peek();//get the top character from stack
            if(!match(topChar, current)){//check if they match
                return false;
            }
            pop();//remove the matched opening bracket from stack
        }
    }
    return isEmpty();//check if stack is empty at the end
}
int main(){
    string expr;
    cout<<"Enter an expression: ";
    cin>>expr;
    if(isBalanced(expr)){
        cout<<"Brackets are balanced"<<endl;
    }
    else{
        cout<<"Brackets are not balanced"<<endl;
    }
    return 0;
}
