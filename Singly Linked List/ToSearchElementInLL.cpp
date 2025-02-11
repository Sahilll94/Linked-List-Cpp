#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node * next;
    
    Node(int val) : data(val), next(NULL) {} ;

};

Node * insertAtBegin(Node *& head, Node *& tail, int val)
{
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node * newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

void printLL(Node * head)
{
    Node * curr = head;

    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }

}

bool search(int target,Node * head)
{
    Node * curr = head;
    
    while(curr!=NULL)
    {
        if(curr->data==target)
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
    head = insertAtBegin(head,tail,40);

    cout<<"Elements in the LL is : ";
    printLL(head);
    cout<<endl;


    int target;
    cout<<"Enter the target: ";
    cin>>target;


    if(search(target,head))
    {
        cout<<target<<" is present in the LL."<<endl;
    }
    else
    {
        cout<<target<<" is absent in the LL."<<endl;
    }


    return 0;
}