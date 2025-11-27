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

void reverseLL() {
    Node* curr =head;
    Node* prev =NULL;
    Node* next = head;
    while (curr!=NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return;



}

void findmiddle() {
    Node* fast=head;
    Node* slow=head;
    while (fast!=NULL && fast->next!=NULL) {
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<"Middle Node is : "<<slow->data;
}
int main () {
    int choice, key, value;
    while(1) {
        cout << "\n1.Insert Beg\n2.Insert End\n3.Insert After\n4.Delete Beg\n5.Delete End\n6.Delete Value\n7.Search\n8.Display\n9.Exit\n10.Reverse\n11.Find Middle Node\nEnter choice: ";
        cin>>choice;
        switch (choice) {
            case 1: cin >> value; insertatbegin(value); break;
            case 2: cin >> value; insertatend(value); break;
            case 3: cin >> key >> value; insertafter(key, value); break;
            case 4: deletebegin(); break;
            case 5: deletefromend(); break;
            case 6: cin >> key; deletevalue(key); break;
            case 7: cin >> key; search(key); break;
            case 8: display(); break;
            case 9: return 0;
            case 10: reverseLL(); break;
            case 11: findmiddle(); break;
            default: cout << "Invalid!";
        }
    }
    return 0;
}