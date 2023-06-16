bool detectCycle(Node *head)
{
	Node* ptr = head;
    while(ptr!=NULL){
        if(ptr->data<0) return true;
        ptr->data *= -1;
        ptr = ptr->next;
    }
    return false;
}
