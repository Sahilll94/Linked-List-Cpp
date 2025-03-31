#include<iostream>
using namespace std;

class Node
{
public:
    Node * prev;
    int data;
    Node * next;

    Node(int val) : data(val), next(NULL),prev(NULL) {};

};

Node * insertAtEnd(Node *& head, Node *& tail, int data)
{
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(data);
        head = tail = newNode;
    }
    else
    {
        Node * newNode = new Node(data);
        newNode->prev = tail; //If we kept, newNode->prev = head; This would always point to the first node
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

void printDLL(Node *& head)
{
    Node * curr = head;

    while(curr!=NULL)
    {
        cout<<curr->data<<" -> ";
        curr = curr->next;
    }

    cout<<" NULL ";
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    head = insertAtEnd(head,tail,10);
    head = insertAtEnd(head,tail,20);
    head = insertAtEnd(head,tail,30);
    head = insertAtEnd(head,tail,40);

    printDLL(head);

    return 0;
}