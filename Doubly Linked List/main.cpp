#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * prev;
        Node * next;

        Node (int val) : data(val),prev(NULL),next(NULL) {};
};

int getLength(Node *& head)
{
    Node * curr = head;
    int count = 0;

    while(curr!=NULL)
    {
        count++;
        curr = curr->next;
    }

    return count;
}


Node * insertAtBegin(Node *& head, Node*& tail, int val)
{
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(val);
        head = tail = newNode;
    }
    else
    {
        Node * newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

void printDLL(Node *& head)
{
    // SC : constant
    Node * curr = head;

    while(curr!=NULL)
    {
        cout<<curr->data<<" -> ";
        curr=curr->next;
    }

    cout<<" NULL "<<endl;
}

Node * insertAtTail(int val, Node *& head, Node *& tail)
{
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(val);
        head = tail = newNode;
    }
    else
    {
        Node * newNode = new Node(val);
        newNode->prev = tail;
        tail -> next = newNode;
        tail = newNode;
    }

    return head;
}


// algorithm
// 1. take a pointer "curr" at head;
// 2. move curr pointer till pos-2 times as if we want to go to position 4 and the curr is at head, then it will have to move (iterate) 2 times means pos-2 or 4-2 = 2.
// 3. Then create a new node.
// 4. connect new node prev to the curr node and the new node's next to the curr's next.
// 5. Now, connect curr's next's prev to the new node.
// 6. connect curr's next to the new node.
// return the head.

Node * insertAtPosition(int pos, int val, Node *& head, Node *& tail)
{
    int length = getLength(head);

    if(pos>length || pos<0)
    {
        cout<<"Invalid position"<<endl;
        return head;
    }

    if(pos==1)
    {
        return insertAtBegin(head,tail,val);
    }

    // length+1 because if you want to insert after the last DLL.
    if(pos==length+1) return insertAtTail(val,head,tail);

    Node * curr = head;
    int count = 1;
    
    // check positionforInsertAtPosition image in the same directory.
    while(curr!=NULL && count < pos-1)
    {
        curr = curr->next;
        count++;
    }

    Node * newNode = new Node(val);
    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;

    return head;
    
}

// Algorithm for deletion of a node;
// 1. When linked list is empty means head and tail both are NULL.
// 2. When there is only one linked list means head and tail are same like head == tail.
// 3. to delete the first node means position == 1
// 4. to delete the last node of the linked lists.
// 5. to delete the middle or random position linked list.
void deletionOfNode(Node *& head, Node*& tail, int position)
{
    // Linked List is empty
    if(head==NULL && tail==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }

    // When there is only one node present
    if(head==tail)
    {
        Node * curr = head;
        head = tail = NULL;
        delete curr;
        return;
    }

    // to delete the head node;
    if(position==1)
    {
        Node * curr = head;
        head = head->next;
        head->prev = NULL;
        delete curr;  
        return;
    }

    int length = getLength(head);
    // to delete the last node;
    if(position==length)
    {
        Node * curr = tail;
        tail = curr->prev;
        tail->next=NULL;
        delete curr;
        return;
    }

    if(position < 0 || position > length)
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    Node * curr = head;
    int count = 1;

    while(count < position)
    {
        curr = curr->next;
        count++;
    }

    curr ->prev ->next = curr->next;
    curr ->next ->prev = curr->prev;
    delete curr;
}

bool search(Node *& head, int target)
{
    Node * curr = head;

    while(curr!=NULL)
    {
        if(curr->data == target)
        {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    head = insertAtBegin(head,tail,10);
    head = insertAtBegin(head,tail,20);
    head = insertAtBegin(head,tail,30);

    printDLL(head);

    head = insertAtTail(40,head,tail);
    head = insertAtTail(50,head,tail);

    head = insertAtPosition(4,60,head,tail);

    printDLL(head);

    int target;
    cout<<"Enter the target element: ";
    cin>>target;

    if(search(head,target))
    {
        cout<<" The element "<<target<< " is found!"<<endl;
    }
    else
    {
        cout<<" The element "<<target<< " is not found!"<<endl;
    }


    int position;
    cout<<"Enter the position of the node you wish to delete: ";
    cin>>position;
    deletionOfNode(head,tail,position);

    cout<<"After deletion: ";
    printDLL(head);

    return 0;
}