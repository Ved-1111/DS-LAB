#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node (int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node* head = NULL;

void insertatbegin(int value) {
    Node* newNode =new Node(value);
    if(head==NULL) {
        head=newNode;
        return;
    }
    newNode -> next =head;
    head->prev=newNode;
    head=newNode;
}

void insertatend(int value) {
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

void insertafter(int key, int value) {
    Node* newNode = new Node (value);
    Node* temp = head;
    if(head==NULL) {
    cout<<"List empty, cannot insert after key"<<endl;
    return;
    }
    while(temp!=NULL && temp->data != key) {
        temp=temp->next;
    }
    if(temp==NULL) {
        cout<<"Node not found"<<endl;
        return;
    }
    if(temp->next==NULL) {
        temp->next=newNode;
        newNode->prev=temp;
        return;
    }
   
    
    
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}

void deletenode(int key) {
    //empty//
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    Node* temp= head;
    //single node//
    if(temp->next==NULL && temp->data==key) {
        delete temp;
        head=NULL;
        return;
    }
    if(temp->next==NULL && temp->data!=key) {
        cout<<"Node is not present"<<endl;
        return;
    }
    //search//
    while(temp!=NULL && temp->data!=key) {
        temp=temp->next;
    }
    //not found//
    if(temp==NULL) {
        cout<<"Node not found"<<endl;
        return;
    }
    //key == first node//
    if(temp->prev==NULL) {
        temp->next->prev=NULL;
        head=temp->next;
        delete temp;
        return;
    }
    //last node//
    if(temp->next==NULL) {
        temp->prev->next=NULL;
        temp->prev=NULL;
        delete temp;
        return;
    }
    //otherwise
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;

}

void search(int key) {
    Node* temp = head;
    int pos=1;
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
   while(temp!=NULL && temp->data!=key) {
    temp=temp->next;
    pos++;
   } 
   if(temp==NULL) {
    cout<<"Node not found"<<endl;
    return;
   }
   if(temp->data==key) {
    cout<<"position is : "<<pos<<endl;
    return;
   }
   
}

void display() {
    Node* temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void size() {
    if(head==NULL) {
        cout<<"Size : 0"<<endl;
        return;
    }
    Node* temp = head;
    int size =0;
    while(temp!=NULL) {
        temp=temp->next;
        size++;
    }
    cout<<"Size : "<<size;
}
int main() {
    int value, choice, key;
    while(1) {
        cout << "\nDoubly Linked List Menu\n";
        cout << "1 Insert front\n2 Insert end\n3 Insert after key\n4 Delete key\n5 Search\n6 Display\n7 Exit\n8 Find size\n";
        cin >> choice;
        switch (choice) {
            case 1 : cin>>value; insertatbegin(value); break;
            case 2 : cin>>value; insertatend(value); break;
            case 3 : cin>>key; cin>>value; insertafter(key,value); break;;
            case 4 : cin>>key; deletenode(key); break;
            case 5 : cin>>key; search(key); break;
            case 6 : display(); break;
            case 7 : return 0;
            case 8 : size(); break;
            default: cout << "Invalid!";
        }
    }
    return 0;
}