Node* removeKthNode(Node* head, int K)
{
    Node* dummy = new Node();
    Node* slow = dummy;
    slow->next = head;
    Node* fast = head;
    while(K--){
        fast = fast->next;
    }

    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    if(slow == dummy){
        dummy = head;
        head = head->next;
    }else {
        dummy = slow->next;
        slow->next = slow->next->next;
    }
    
    delete dummy;
    return head;
}
