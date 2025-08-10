#include<iostream>
#include<math.h>
using namespace std;

class Node
{
public:
    int data;
    Node * next;

    Node (int val) : data(val), next(NULL) {};
};

Node * insertAtBegin(Node *& head, Node *& tail, int data)
{
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(data);
        head = tail = newNode;
    }
    else
    {
        Node * newNode = new Node (data);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

void print(Node *& head)
{
    Node * curr = head;

    while(curr != NULL)
    {
        cout<<curr->data;
        if(curr->next!=NULL) cout<<" - ";
        curr = curr->next;
    }
}

int findlength (Node *& head)
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

int middleNode(Node * head, int length)
{
    int middle = ceil(length/2);

    Node * curr = head;

    int middleNodeElement = 0;

    while(middle--)
    {
        curr = curr->next;
    }

    middleNodeElement = curr->data;
    return middleNodeElement;
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;

    head = insertAtBegin(head,tail,10);
    head = insertAtBegin(head,tail,20);
    head = insertAtBegin(head,tail,30);
    head = insertAtBegin(head,tail,40);
    head = insertAtBegin(head,tail,50);


    cout<<"The nodes are: ";
    print(head);

    int count = findlength(head);
    
    cout<<endl;

    cout<<"The number of total nodes is : "<<count<<endl;

    cout<<"The middle node element is : "<<middleNode(head,count)<<endl;

    return 0;
}