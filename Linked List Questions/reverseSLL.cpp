// LeetCode question link for practice : https://leetcode.com/problems/reverse-linked-list/

#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node * next;

    Node (int val) : data(val), next(NULL) {};
};


Node * insert(Node *& head, int val)
{
    if(head==NULL)
    {
        Node * newNode = new Node(val);
        head = newNode;
        return head;
    }

    Node * newNode = new Node(val);
    newNode -> next = head;
    head = newNode;
    return head;

}

void print(Node *& head)
{
    Node * curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" - ";
        curr = curr->next;
    }
    cout<<" NULL ";
}

Node * reverseSLL(Node *& head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head; //return null or the last node
    }

    Node * newHead = reverseSLL(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}

int main()
{
    Node * head = NULL;

    head = insert(head,10);
    head = insert(head,20);
    head = insert(head,30);
    head = insert(head,40);

    print(head);

    head = reverseSLL(head);
    cout<<endl;
    cout<<"After reversing: ";

    print(head);


    return 0;
}
