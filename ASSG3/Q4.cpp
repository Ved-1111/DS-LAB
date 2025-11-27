#include<iostream>
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
        cout<<x<<" pushed to stack"<<endl; 
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
    bool isOperator(char c){//function to check if character is operator
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
    int precedence(char c){//function to return precedence of operators
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return -1;
    }
    string infixToPostfix(string infix){//function to convert infix to postfix
        string postfix = "";//resultant postfix expression
        for(int i=0; i<infix.length(); i++){//traverse the infix expression
            char current = infix[i];//get the current character
            if((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9')){
                postfix += current;//if operand, add to postfix
            }
            else if(current == '('){
                push(current);//if '(', push to stack
            }
            else if(current == ')'){//if ')', pop and output from the stack until an '(' is encountered
                while(!isEmpty() && peek() != '('){
                    postfix += peek();
                    pop();
                }
                if(!isEmpty() && peek() == '('){//pop '(' from stack
                    pop();
                }
            }
            else if(isOperator(current)){//if operator, pop from stack to postfix until stack is empty or top has less precedence
                while(!isEmpty() && precedence(peek()) >= precedence(current)){//check precedence
                    if(current == '^' && precedence(peek()) == precedence(current)){//right associative
                        break;//do not pop
                    }
                    postfix += peek();//add to postfix
                    pop();//pop from stack
                }
                push(current);//push current operator to stack
            }


        }
        while(!isEmpty()){//pop all remaining operators from stack to postfix
            postfix += peek();
            pop();
        }
        return postfix;
    }
    int main(){
        string infix;
        cout<<"Enter an infix expression: ";
        cin>>infix;
        string postfix = infixToPostfix(infix);
        cout<<"Postfix expression: "<<postfix<<endl;
        return 0;
    }

                    