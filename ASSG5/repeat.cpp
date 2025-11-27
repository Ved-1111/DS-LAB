#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node (int value) {
        data=value;
        next=NULL;
    }
};

Node* head = NULL;

void insertatbegin(int value) {
    Node* newNode =new Node(value);
    newNode -> next =head;
    head=newNode;
}

void insertatend(int value) {
    if(head==NULL) {
    Node* newNode =new Node(value);
    head=newNode;
    }
    else {
        Node* newNode =new Node(value);
        
        Node* temp = head;
        while(temp->next != NULL) {
        temp=temp->next;
        }
        temp->next=newNode;

    }
    
}

void insertafter(int key, int value) {
    Node* temp = head;
    while(temp != NULL && temp->data != key ) {
        temp=temp->next;
    }
    if(temp==NULL) {
        cout<<"Node not found"<<endl;
        return;
    }
    Node* newNode =new Node(value);
    newNode->next=temp->next;
    temp->next=newNode;
}

void deletebegin() {
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    else {
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete(temp);   
    }
}

void deletefromend() {
    Node* temp=head;
    
    if (head==NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    if (head->next==NULL) {
        head=NULL;
        delete temp;
        return;
    }
    while(temp->next->next != NULL) {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}

void deletevalue(int key) {
    Node* temp=head;
    if (head==NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    if(key==head->data) {
        head=temp->next;
        delete temp;
        return;
    }
    while(temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if(temp->next==NULL) {
        cout<<"Node not found"<<endl;
        return;
    }
    Node* del = temp->next;
    temp->next=del->next;
    delete del;

}

void search(int key) {
    int pos=1;
    Node* temp = head;
    while(temp != NULL && temp->data != key) {
        temp=temp->next;
        pos++;
    }
    if(temp==NULL) {
        cout<<"Node not found"<<endl;
        return;
    }
    else {
        cout<<"Position is "<<pos<<endl;
        return;
    }
}

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleterepeat (int key) {
    int count = 0;
    while(1) {
    // int pos=1;
    Node* temp = head;
    
    while(temp != NULL && temp->data != key) {
        temp=temp->next;
        // pos++;
    }
    if(temp==NULL) {
        // cout<<"Node not found"<<endl;
        break;;
    }
    else {
        deletevalue(key);
        count++;
    }
}
    cout<<count<<endl;

}
int main () {
    insertatbegin(10);
    insertatbegin(20);
    insertatbegin(10);
    insertatbegin(20);
    insertatbegin(10);
    insertatbegin(30);
    insertatbegin(10);
    display();
    deleterepeat(20);
    display();
    

    return 0;
}