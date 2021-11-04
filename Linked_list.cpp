#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << "->";
        head = head->next;
    }
    cout << "NULL";
}

void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);

    if (head == NULL)
    {
        head = n;
        n = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    temp = NULL;
}

void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);

    n->next = head;
    head = n;
    n = NULL;
}

bool search(Node *head, int key)
{
    while (head != NULL)
    {
        if (head->value == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

void deletion(Node *&head, int val)
{
    Node *temp = head;

    if (head == NULL)
    { //this if for edge case -> if list is empty
        return;
    }

    if (head->value == val)
    { //this is for edge case -> if the head node is to be deleted.
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            toDelete = NULL;
        }
        return;
    }

    while (temp->next->value != val)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "Unable to delete, value not present in list.\n";
            return;
        } //This statement prevents the program from getting stuck if the value to be deleted is not present in the list.
    }

    Node *toDelete = temp->next; //pointer to the nth node that needs to be deleted
    temp->next = toDelete->next; //pointing the n-1 node to n+1 node(changing the link).
    delete toDelete;             //releasing the memory held by the node object.
    toDelete = NULL;             //pointing the dangling pointer to NULL.
}

Node *reverseList(Node *&head)
{
    Node *previous = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    { //In linked list if a pointer is becoming NULL after that we can't access pointer->next and pointer->data, doing so will result in the program getting stuck/terminate.
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    head = previous;
    return head;
}

Node *reverseRecursive(Node *&head) //Reversing list using recursion
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newhead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
}

Node *reverse_K_nodes(Node *&head, int k)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr = NULL;

    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;

        count++;
    }

    if (nextptr != NULL)
        head->next = reverse_K_nodes(nextptr, k);
    return prevptr;
}

void makeCycle(Node *head, int pos)
{
    Node *temp = head;
    Node *target = NULL;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            target = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = target;
}

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }
    return false;
}

void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

void appendKNodes(Node *&head, int k) //not working yet needs to be fixed
{
    Node *temp = head;
    Node *temp2 = head;
    int count = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (k >= count)
        return;

    int stepsToTake = count - k;

    count = 1;
    while (count < stepsToTake)
    {
        temp2 = temp2->next;
        count++;
    }
    Node *newtail = temp2;
    temp2 = temp2->next;
    newtail->next = NULL;
    temp->next = head;
    head = temp2;
}

int getLength(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int getIntersection(Node *head1, Node *head2) //returns the value of intersecting node or -1 if lists are not intersected.
{
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    Node *ptr1 = NULL;
    Node *ptr2 = NULL;

    int diff;
    if (l1 > l2)
    {
        diff = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        diff = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    int count = 1;
    while (count <= diff && ptr1 != NULL)
    { //setting the pointer1 of 1st list at an equal distance as pointer 2 of 2nd list from the intersection
        ptr1 = ptr1->next;
        count++;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    { //moving ahead in both lists until an intersection/NULL is found
        if (ptr1 == ptr2)
        {
            return ptr1->value;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

Node *mergeLists(Node *head1, Node *head2)
{
    Node *dummyNodeHead = new Node(-1);
    Node *ptr = dummyNodeHead;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL && head2 != NULL)
        {
            if (head1->value > head2->value)
            {
                ptr->next = head2;
                head2 = head2->next;
            }
            else if (head1->value == head2->value)
            {
                ptr->next = head1;
                head1 = head1->next;
                head2 = head2->next;
            }
            else
            {
                ptr->next = head1;
                head1 = head1->next;
            }
            ptr = ptr->next;
        }
        else if (head1 == NULL)
        {
            ptr->next = head2;
            break;
        }
        else
        {
            ptr->next = head1;
            break;
        }
    }
    Node *toDelete = dummyNodeHead;
    dummyNodeHead = dummyNodeHead->next;
    delete toDelete;
    toDelete = NULL;
    return dummyNodeHead;
}

Node* mergeListRecursive(Node* head1, Node* head2)
{
    if(head1==NULL)
    {
        return head2;
    }

    if(head2==NULL)
    {
        return head1;
    }

    Node* result;
    if(head1->value < head2->value){
        result=head1;
        result->next=mergeListRecursive(head1->next,head2);
    }
    else if(head1->value > head2->value){
        result = head2;
        result->next=mergeListRecursive(head1,head2->next);
    }
    else{
        result = head1;
        result->next=mergeListRecursive(head1->next,head2->next);
    }

    return result;
}

int main()
{
    Node *head = new Node(78); //head, second, third are only pointers to the objects of type Node. They can be made to point to some other Node object if required. The actual nodes which store the values are objects of type Node (generated by the statement 'new Node(integer)') and are nameless blocks of memory location. That is why they can only be accesssed by pointers which store their address.
    Node *second = new Node(79);
    Node *third = new Node(80);
    Node *gh = NULL;

    head->next = second;
    second->next = third;
    third->next = NULL;

    insertAtTail(head, 90);
    insertAtHead(head, 541);
    printList(head);

    cout << "\n"
         << search(head, 79) << "\n";

    deletion(head, 43);

    cout << "\n";
    printList(head);

    // cout<<"\n";
    // Node* newhead= reverseList(head);
    // printList(newhead);

    // cout<<"\n";
    // Node* newhead= reverse_K_nodes(head,2);
    // printList(newhead);

    makeCycle(head, 2);

    cout << "\n"
         << detectCycle(head);

    removeCycle(head);

    cout << "\n"
         << detectCycle(head);

    appendKNodes(head, 2);

    cout << "\n";
    printList(head);

    Node *a1 = new Node(1); //creating a1 and n1 linked lists which intersect at a point.
    Node *a2 = new Node(4);
    a1->next = a2;
    Node *a3 = new Node(6);
    a2->next = a3;
    Node *a4 = new Node(7);
    a3->next = a4;
    Node *a5 = new Node(9);
    a4->next = a5;

    Node *n1 = new Node(2);
    Node *n2 = new Node(3);
    n1->next = n2;
    Node *n3 = new Node(5);
    n2->next = n3;
    n3->next = a4;

    cout << "\n";
    printList(a1);
    cout << "\n";
    printList(n1);

    cout << "\n";
    cout << "Intersection: " << getIntersection(a1, n1);
    cout << "\n";
    cout << "Intersection: " << getIntersection(head, a1);

    cout << "\n";
    Node *mergedListHead = mergeLists(a1, n1);
    printList(mergedListHead);
    return 0;
}