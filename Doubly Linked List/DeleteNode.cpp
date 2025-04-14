void deletionOfNode(Node *& head, Node*& tail, int position)
{
    // Linked List is empty
    if(head==NULL && tail==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }

    // When there is only one node present
    if(head==tail)
    {
        Node * curr = head;
        head = tail = NULL;
        delete curr;
        return;
    }

    // to delete the head node;
    if(position==1)
    {
        Node * curr = head;
        head = head->next;
        head->prev = NULL;
        delete curr;  
        return;
    }

    int length = getLength(head);
    // to delete the last node;
    if(position==length)
    {
        Node * curr = tail;
        tail = curr->prev;
        tail->next=NULL;
        delete curr;
        return;
    }

    if(position < 0 || position > length)
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    Node * curr = head;
    int count = 1;

    while(count < position)
    {
        curr = curr->next;
        count++;
    }

    curr ->prev ->next = curr->next;
    curr ->next ->prev = curr->prev;
    delete curr;
}