#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* reverse(LinkedListNode<int> *head){
    if(head == NULL || head->next == NULL) return head;
    LinkedListNode<int> *prev = NULL,*cur = head,*next = NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL) return true;
    int l = 0;
    LinkedListNode<int> *n = head;
    LinkedListNode<int> *slow = head,*fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    n = head;
    while(n!=NULL && slow !=NULL){
        if(n->data != slow->data) return false;
        n = n->next;
        slow = slow->next;
    }
    return true;
}
