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
        head=tail=newNode;
    }
    else
    {
        Node * newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

void print(Node *& head)
{
    Node * cur = head;

    while(cur!=NULL)
    {
        cout<<cur->data<<" -> ";
        cur = cur->next;
    }
    cout<<"NULL";
}

Node * insertAtEnd(Node *& head, Node*& tail, int val)
{
    if(head==NULL)
    {
        Node* newNode = new Node(val);
        tail = head = newNode;
    }
    else
    {
        Node * newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

int getLen(Node* & head)
{
    int len = 0;

    Node* curr = head;

    while(curr!=NULL)
    {
        curr = curr->next;
        len++;
    }

    return len;
}

Node * insertAtPos(int len, int val, Node* &head, Node* &tail, int pos)
{
    // Invalid input;
    if(pos<1 || pos>len+1)
    {
        cout<<"Invalid position"<<endl;
        return head;
    }

    // Position is 1 means insert at begin;
    if(pos==1)
    {
        return insertAtBegin(head,tail,val);
    }

    // Position is len+1 means suppose LL is 4, you want to add at 4+1=5 means insert at end;
    if(pos==len+1)
    {
        return insertAtEnd(head,tail,val);
    }

    // sas
    // insert at position;
    Node * newNode = new Node(val);
    Node * temp = head;
    // 'l' is the number of time to move temp forward;
    int l = pos-2;

    //  1     2     3    4     5      6      7
    // 30 -> 20 -> 10 -> 40 -> 50 -> 100 -> 60 -> NULL

    // Let say, I want to insert at position 4 means in between 10 and 40 I will insert a new node; i.e. 10->NewNode->40;
    // means we need to go till 3rd position to insert, position - 2, 4-2 = 2; why pos-2? Our temp will be at head, then we will move 2 times only to come at 3rd;
    while(l--)
    {
        temp = temp -> next;
    }

    newNode->next= temp->next;
    temp->next = newNode;
            
    return head;
    
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

    int len = getLen(head);
    
    head = insertAtPos(len,100,head,tail,6);

    print(head);

    return 0;
}