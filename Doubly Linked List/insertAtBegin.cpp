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

Node * insertAtPosition(int pos, int val, Node *& head, Node *& tail)
{
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(val);
        head = tail = newNode;
    }

    if(pos<=1) return insertAtBegin(head,tail,val);

    Node * curr = head;
    int count = 1;

    // 3

    while(curr!=NULL && count < pos-1)
    {
        curr = curr -> next;
        count++;
    }

    // if current pointer is at last linked list.
    if(curr==tail) return insertAtTail(val,head,tail);

    Node * newNode = new Node(val);
    newNode -> prev = curr;
    newNode -> next = curr->next;
    curr -> next = newNode;
    curr -> next -> prev = newNode;

    return head;
}

void reversePrint(Node *& tail)
{
    Node * curr = tail;

    cout<<"Null <- ";

    while(curr!=NULL)
    {
        cout<<curr->data<<" <- ";
        curr = curr->prev;
    }

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

    return 0;
}