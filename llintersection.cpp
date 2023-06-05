/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int l1=0,l2=0;
    if(firstHead == NULL || secondHead == NULL) return NULL;
    Node *n = firstHead,*n1;
    while(n!=NULL){
        l1++;
        n=n->next;
        
    }
    n = secondHead;
    while(n!=NULL){
        n=n->next;
        l2++;
    }
    if(l2>l1){
        n = secondHead;
        n1 = firstHead;
        int t = l2-l1;
        while(t--) n=n->next;
    } else if(l2<l1){
        n = firstHead;
        n1 = secondHead;
        int t = l1-l2;
        while(t--) n=n->next;
    } else {
        n = firstHead;
        n1 = secondHead;
    }
    

    while(n!=NULL && n1!=NULL){
        if(n==n1){
            return n;
        }
        n = n->next;
        n1= n1->next;
    }
    return NULL;
}
