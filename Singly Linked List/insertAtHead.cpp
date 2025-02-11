#include<iostream>
using namespace std;


class Node
{
    public:
        int data;
        Node * next;

    // CTOR which creates new node and keep next as NULL;
    // Then to change the next simply update it as per your requirement;
    Node(int _val) : data(_val), next(NULL) {};

};


// Returns head of the new LL as pointer;
Node * insertAtHead(int value, Node* head, Node* tail)
{
    // If LL is empty, means Head and tail pointing to NULL, means head and tail is uninitialised or there is no node;
    if(head==NULL && tail==NULL)
    {
        Node * newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    // If there is a LL already then insert at head or begin or before newNode;
    else
    {
        Node * newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

int main()
{
    // Head and tail should be NULL in the starting;
    Node * head = NULL;
    Node * tail = NULL;
    
    // LL is empty;

    head = insertAtHead(10,head,tail);
    // 10 -> NULL (10 next pointing to null)

    head = insertAtHead(20,head,tail);
    // 20 -> 10 -> NULL

    head = insertAtHead(30,head,tail);
    // 30 -> 20 -> 10 -> NULL


    return 0;
}