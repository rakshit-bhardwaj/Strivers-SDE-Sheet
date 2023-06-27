#include <bits/stdc++.h> 
class Node {
    public:
    vector<Node*> bits; 
    Node(){bits.resize(2,NULL);}
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* curnode = root;
        for(int i =31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(curnode->bits[bit]==NULL){
                curnode->bits[bit] = new Node();
            }
            curnode = curnode->bits[bit];
        }
    }
    
    int getmax(int num){
        int ans =0;
        Node* n = root;
        for(int i =31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(n->bits[1 - bit]!=NULL){
                ans = ans | (1 << i);
                n = n->bits[1 - bit];
            } else {
                n= n->bits[bit];
            }
        }
        return ans;
    }
};


int maximumXor(vector<int> A)
{
    int ans = 0;
    Trie t;
    for(auto x : A) t.insert(x);
    for(auto x : A) ans = max(ans,t.getmax(x));
    return ans;   
}
