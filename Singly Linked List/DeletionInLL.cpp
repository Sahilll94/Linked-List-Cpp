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

Node * deleteAtbegin(Node *& head , Node *& tail, int target)
{
    Node * curr = head;
    head = curr->next;
    delete curr;

    return head;
}

Node * DeleteTarget (Node *& head, Node *& tail, int target)
{
    
    if(head==NULL)
    {
        cout<<"No Node is available in the LL"<<endl;
        return NULL;
    }
    
    if(head->data == target)
    {
        return deleteAtbegin(head,tail,target);
    }
    
    Node * curr = head;

    while(curr->next!=NULL && curr->next->data != target)
    {
        curr = curr->next;
    }

    if(curr->next==NULL)
    {
        cout<<target<<" not present in the LL"<<endl;
        return head;
    }

    Node * temp = curr;
    curr->next = curr->next->next;

    delete temp;    

    return head;
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
    cout<<"Enter the element to delete: ";
    cin>>target;

    head = DeleteTarget(head,tail,target);
    
    cout<<"Elements in the LL is : ";
    printLL(head);
    cout<<endl;

    return 0;
}