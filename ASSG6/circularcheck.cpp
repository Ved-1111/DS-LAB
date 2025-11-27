#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* head = NULL;

void insertatend(int value) {
    Node* newNode = new Node(value);
    Node* temp = head;
    if(head==NULL) {
        head=newNode;
        newNode->next=head;
        return;
    }
    while(temp->next!=head) {
        temp=temp->next;
    }
    newNode->next=head;
    temp->next=newNode;
    
}

bool isCirclular() {
    if(head==NULL) {
        return false;
    }
    Node* temp = head->next;
    while(temp!=NULL && temp!=head) {
        temp= temp->next;
    }
    if(temp==head) {
        return true;
    }
    else return false;
}

int main () {
    insertatend(2);
    insertatend(4);
    insertatend(6);
    insertatend(7);
    insertatend(5);
    insertatend(7);
    insertatend(2);

    if(isCirclular()) cout<<"circular"<<endl;
    else cout<<"Not circular"<<endl;
    return 0;
}