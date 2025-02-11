#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;

    // creating an alone LL;
    Node(int _val) : data(_val), next(NULL) {};

};

// This function simply insert a node in the beginning;
Node * insertAtHead(int val, Node* head, Node*tail)
{
    // If there is no LL then create one
    // How to check there is no LL? 
    // If head and tail both point at NULL means they are not assigned to anyone;
    if(head==NULL && tail==NULL)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }
    // There exist a node;
    else
    {
        Node * newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
    }

    // return the updated head;
    return head;
}

void printLL(Node * head)
{
    Node * curr = head;

    while(curr!=NULL)
    {
        cout<<curr->data<<" -> ";
        curr = curr->next; //When it reaches to last node which has next as NULL then stop;


        if(curr==NULL)
        {
            cout<<"NULL";
        }
    }
    // cout<<endl;
}



int main()
{
    // The below 2 lines says that there is no LL as head and tail is not assigned to anyone;
    Node * head = NULL;
    Node * tail = NULL;

    Node * first = new Node(10);

    head = insertAtHead(20,head,tail);
    head = insertAtHead(30,head,tail);
    head = insertAtHead(40,head,tail);
    head = insertAtHead(50,head,tail);

    // cout<<head<<endl;

    printLL(head);

    return 0;
}