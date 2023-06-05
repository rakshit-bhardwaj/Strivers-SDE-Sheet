/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* mergell(Node* head1,Node* head2){
	Node* ptr1 = head1,*ptr2 = head2;
	head1->next = NULL;
	Node* cur = new Node(0);
	Node* newhead = cur;

    while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->data <= ptr2->data){
			cur->child = ptr1;
			ptr1 = ptr1->child;
			cur = cur->child;
		}
		else{
			cur->child = ptr2;
			ptr2 = ptr2->child;
			cur = cur->child; 
		}
	}

	if(ptr1!=NULL) cur -> child = ptr1;
	else cur -> child = ptr2;
	
	return newhead->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next == NULL) return head;

	head->next = flattenLinkedList(head->next);

	return mergell(head, head->next);
	
}
