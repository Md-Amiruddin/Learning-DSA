#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val)
{
    Node* n = new Node(val);
    Node* temp = head;

    if(head == NULL){
        head = n;
        n->next=head;
        return;
    }

    while(temp->next != head){
        temp=temp->next;
    }

    temp->next=n;
    n->next=head;
    head = n;
}

void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val);
    Node* temp = head;

    if(head == NULL){
        insertAtHead(head,val);
        return;
    }

    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next = n;
    n->next= head;
    
}

void deleteAtHead(Node* &head){
    Node* toDelete = head;
    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }

    head = head->next;
    temp->next = head;
    delete toDelete;
    toDelete = NULL;
}

void deletion(Node* &head, int pos)
{
    Node* temp = head;
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    int count = 1;

    while(count!=pos-1){
        temp=temp->next;
        count++;
    }

    Node* toDelete = temp->next;
    toDelete = NULL;
    temp->next=temp->next->next;
    delete toDelete;
}

void printList(Node* head){
    Node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<"head";
}

int main()
{
    Node* head = NULL;
    insertAtTail(head,55);
    insertAtTail(head,66);
    insertAtTail(head,77);
    insertAtHead(head,89);
    printList(head);
    cout<<"\n";
    deletion(head,2);
    deleteAtHead(head);
    printList(head);
    return 0;
}