#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;

    Node (int val) : data(val), next(NULL) {};
};

Node * insertAtBegin(Node *& head, Node *& tail, int val)
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
        head = newNode;
    }

    return head;

}

Node * insertAtEnd(Node *& head, Node *& tail, int val)
{
    if(head==NULL)
    {
        Node * newNode = new Node(val);
        head = tail = newNode;
    }
    else
    {
        Node * newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

void printLinkedList(Node * head)
{
    Node * curr = head;

    while ( curr!=NULL)
    {
        cout<<curr->data<<" -> ";
        curr = curr->next;
    }

    cout<<" NULL "<<endl;
    
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    head = insertAtBegin(head,tail,10);
    head = insertAtBegin(head,tail,20);
    head = insertAtBegin(head,tail,30);

    head = insertAtEnd(head,tail,40);
    head = insertAtEnd(head,tail,50);
    head = insertAtEnd(head,tail,60);

    printLinkedList(head);



    return 0;
}