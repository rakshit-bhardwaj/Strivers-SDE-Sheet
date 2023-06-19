Node *rotate(Node *head, int k) {
     if(head==NULL || head->next == NULL || k==0) return head;
     int l =1;
     Node *ptr = head;
     while(ptr->next!=NULL){
          ptr = ptr->next;
          l++;
     }
     ptr->next = head;
     k = k%l;
     k = l - k;
     while(k--) ptr = ptr->next;
     head = ptr->next;
     ptr->next = NULL;
     return head;
}
