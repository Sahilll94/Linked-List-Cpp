#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node * prev;
    Node * next;

    Node(int val) : data(val),prev(NULL),next(NULL) {};
};

Node * insertAtBegin(Node*& head, Node *&tail, int val)
{
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(val);
        head = tail = newNode;
    }
    else
    {
        Node * NewNode = new Node(val);
        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
    }

    return head;
}

void reversePrint(Node * tail)
{
    Node * temp = tail;

    cout<<"NULL ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }

}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    head = insertAtBegin(head,tail,10);
    head = insertAtBegin(head,tail,20);
    head = insertAtBegin(head,tail,30);

    reversePrint(tail);

    return 0;
}