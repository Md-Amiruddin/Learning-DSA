#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(int val){
        prev = NULL;
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val)
{
    Node* n = new Node(val);

    if(head==NULL){
        head=n;
        return;
    }

    n->next=head;
    head->prev=n;
    head=n;
}

void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val);
    
    Node* temp = head;

    if(head==NULL){
        head = n;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
}

void deleteNode(Node* &head, int key)
{
    Node* temp = head;

    if(head==NULL){  //edge case: if list is empty
    return;
    }

    if(head->data==key){   //edge case if head node is to be deleted
        if(head->next==NULL){
            delete head;
            head=NULL;
        }else{
        head->next->prev==NULL;
        Node* toDelete = head;
        delete toDelete;
        toDelete = NULL;
        head=head->next;
        }
        return;
    }
    
    while(temp->data!=key){
        temp=temp->next;
        if(temp==NULL){
            cout<<"Unable to delete, data not in list.";
            return;
        }
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL)           //incase if last node is to be deleted, we can't access temp->next->prev as temp->next will be null, program will get stuck if tried to access prev of NULL
    temp->next->prev=temp->prev;
    delete temp;
    temp=NULL;
}

void printList(Node* head)
{
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}

int main()
{
    Node* head = NULL;
    insertAtTail(head,33);
    insertAtTail(head,44);
    insertAtTail(head,55);
    insertAtTail(head,66);

    insertAtHead(head,312);

    deleteNode(head,66);

    printList(head);
    return 0;
}