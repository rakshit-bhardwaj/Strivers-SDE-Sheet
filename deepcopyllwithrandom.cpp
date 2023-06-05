#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(head==NULL) return head;
    LinkedListNode<int> *ptr = head,*next;
    
    while(ptr!=NULL){
        LinkedListNode<int> *n = new LinkedListNode<int>(ptr->data);
        next = ptr->next;
        ptr->next = n;
        n->next = next;
        ptr = ptr->next->next;
    }
    
    ptr = head;
    while(ptr!=NULL){
        if(ptr->random == NULL) ptr->next->random = NULL;
        else ptr->next->random = ptr->random->next;
        ptr = ptr->next->next;
    }
    
    LinkedListNode<int> *dhead = new LinkedListNode<int>(0);
    LinkedListNode<int> *copy = dhead,*front;
    ptr = head;
    while(ptr!=NULL){
        front = ptr->next->next;
        copy->next = ptr->next;
        ptr->next = front;
        ptr = ptr->next;
        copy = copy->next;
    }
    return dhead->next;
}
