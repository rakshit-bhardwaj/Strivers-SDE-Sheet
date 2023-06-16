Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *head = new Node<int>(0);
    Node<int> *ptr = head;
    while(first != NULL && second != NULL){
        Node<int> *n = new Node<int> (0);
        if(first->data<=second->data){
            n->data = first->data;
            first = first->next;
        } else {
            n->data = second->data;
            second = second->next;
        }
        ptr ->next = n;
        ptr = ptr->next;
    }

    while(first!=NULL){
        Node<int> *n = new Node<int> (first->data);
        ptr ->next = n;
        ptr = ptr->next;
        first = first->next;
    }
    while(second!=NULL){
        Node<int> *n = new Node<int> (second->data);
        ptr ->next = n;
        ptr = ptr->next;
        second = second->next;
    }

    return head->next;
}
