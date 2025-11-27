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

void insertatbegin(int value) {
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
    head=newNode;
}

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

void insertafter(int key, int value) {
    Node* newNode = new Node (value);
    Node* temp = head;
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    while(temp->data!=key && temp->next!=head) {
        temp=temp->next;
    }
    if(temp->next==head && temp->data!=key) {
        cout<<"Node not found"<<endl;
        return;
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

void deletenode(int key) {
    Node* del = head;
    Node* temp =head;
    //empty LL//
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    //single node//
    if(head->next==head && head->data==key) {
        delete temp;
        head=NULL;
        return;
    }
    //first node and all other nodes are handled here//
    while(temp->next!=head && temp->next->data!=key) {
        temp=temp->next;
    }
    if(temp->next==head && temp->next->data==key) {
        del=head;
        temp->next=del->next;
        head=head->next;
        delete del;
        return;
    }
    if(temp->next==head && temp->next->data!=key) {
        cout<<"Node not found"<<endl;
        return;
    }
    del=temp->next;
    temp->next=del->next;
    del->next=NULL;
    delete del;

}

void search(int key) {
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    Node* temp = head;
    int pos=1;
    while(temp->next!=head && temp->data!= key) {
        temp=temp->next;
        pos++;
    }
    if(temp->next==head && temp->data!=key) {
        cout<<"Node not found"<<endl;
        return;
    }
    cout<<"position is : "<<pos<<endl;
}

void display() {
    Node* temp = head;
    if(head==NULL) {
        cout<<"LL is empty"<<endl; 
        return;
    }
    do {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!= head) ;
    cout<<head->data<<endl;
    
}

void size () {
    Node* temp = head;
    if(head==NULL) {
        cout<<"Size : 0"<<endl;
        return;
    }
    int size = 0;
    do {
        temp=temp->next;
        size++;
    } while(temp!=head);
    cout<<"Size : "<<size;
}
int main () {
int value, choice, key;
    while(1) {
        cout << "\nDoubly Linked List Menu\n";
        cout << "1 Insert front\n2 Insert end\n3 Insert after key\n4 Delete key\n5 Search\n6 Display\n7 Exit\n8 Size\n";
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