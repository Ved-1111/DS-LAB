#include<iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node* head = NULL;

void insertatend(char value) {
    Node* newNode = new Node (value);
    Node* temp = head;
    if(head==NULL) {
        head=newNode;
        return;
    }
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

bool isPalindrome() {
    Node* tail=head;
    while(tail->next!=NULL) {
        tail=tail->next;
    }
    Node* left=head ;
    Node* right=tail ;
    while(left!=right && left->prev!=right) {
        if(left->data!=right->data) {
            return false;
        }
        left=left->next;
        right=right->prev;
    }
    return true;
}

int main () {
    string s;
    cout<<"Enter string : "<<endl;
    cin>>s;

    for(int i = 0; i<s.length(); i++) {
        insertatend(s[i]);
    }
    if(isPalindrome()) cout<<"Palindrome"<<endl;
    else cout<<"Not a Palindrome"<<endl;
    return 0;
}