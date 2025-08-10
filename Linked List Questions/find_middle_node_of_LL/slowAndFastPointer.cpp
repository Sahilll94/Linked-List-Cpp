#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node * next;

    Node (int val) : data(val), next (NULL) {}; 
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
        tail->next = newNode;
        tail = newNode;
    }

    return tail;
}

Node * insertAtBegin(Node *& head, Node *& tail, int data)
{
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(data);
        head = tail = newNode;
    }
    else
    {
        Node * newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

void print(Node *& head)
{
    Node * curr = head;

    while(curr!=NULL)
    {
        cout<<curr->data;
        if(curr->next!=NULL) cout<<" - ";
        curr = curr->next;
    }
}


int TortoiseMethod(Node *& head)
{
    Node * curr1 = head;
    Node * curr2 = head;

    while(curr2!=NULL && curr2->next!=NULL)
    {
        curr1 = curr1->next;
        curr2 = curr2->next->next;
    }

    return curr1->data;
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    
    head = insertAtBegin(head,tail,30);
    head = insertAtBegin(head,tail,20);
    head = insertAtBegin(head,tail,10);

    tail = insertAtEnd(head,tail,40);
    tail = insertAtEnd(head,tail,50);
    tail = insertAtEnd(head,tail,60);



    cout<<"Nodes in the linked list: ";
    print(head);

    cout<<endl;

    cout<<"The middle node using Slow and Fast Pointer Method : "<<TortoiseMethod(head)<<endl;

    return 0;
}