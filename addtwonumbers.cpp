
Node *addTwoNumbers(Node *num1, Node *num2)
{   
    if(num1 == NULL && num2 == NULL) return NULL;
    if(num1 == NULL) return num2;
    if(num2 == NULL) return num1;
    int carry = 0,sum=0;
    Node* head = new Node();
    Node* ptr = head;
    while(num1!=NULL && num2!=NULL){
        sum = (num1->data + num2->data + carry)%10;
        carry = (num1->data + num2->data + carry)/10;
        Node* node = new Node(sum);
        ptr->next = node;
        ptr = ptr->next;
        num1 = num1->next;
        num2 = num2->next;
    }

    while(num1!=NULL){
        sum = (num1->data + carry)%10;
        carry = (num1->data + carry)/10;
        Node* node = new Node(sum);
        ptr ->next = node;
        ptr = ptr->next;
        num1 = num1->next;
    }
    while(num2!=NULL){
        sum = (num2->data + carry)%10;
        carry = (num2->data + carry)/10;
        Node* node = new Node(sum);
        ptr ->next = node;
        ptr = ptr->next;
        num2 = num2->next;
    }
    if (carry != 0) {
        Node* node = new Node(carry);
        ptr ->next = node;
        ptr = ptr->next;
    }
    
    return head->next;
}

