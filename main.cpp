#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node()
        {
            cout<<"CTOR"<<endl;
        }

        // CTOR (init list)
        Node(int _value) : data(_value), next(NULL) {};
};

int main()
{
    // Creating Node on STACK;
    Node first;

    // Creating Node on Heap via DMA;
    Node * second = new Node(10);


    return 0;
}