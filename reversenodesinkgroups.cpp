Node* func(Node* head,int b[],int i,int n){
	if(head == NULL || head->next == NULL || i == n) return head;
	int k = b[i];
	if(k==0) return func(head,b,i+1,n);
	
	Node* cur = head;
	Node* prev = NULL;
	Node* nex;
	
	while(cur!=NULL && k--){
		nex = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nex;
	}
	
	if(nex!=NULL) head->next = func(nex,b,i+1,n);
	
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return func(head,b,0,n);
}
