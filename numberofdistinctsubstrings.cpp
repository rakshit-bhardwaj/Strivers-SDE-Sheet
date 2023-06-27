#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    vector<Node*> children = vector<Node*> (26,NULL); 
    bool leaf = false;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curnode = root;
        for(int i = 0;i<word.size();i++){
            if(curnode->children[word[i] - 'a']==NULL) {
                Node* t = new Node();
                curnode->children[word[i] - 'a'] = t;
            }
            curnode = curnode->children[word[i] - 'a'];
        }
        curnode->leaf = true;
    }
    
    bool search(string word) {
        Node* curnode = root;
        for(int i = 0;i<word.size();i++){
            if(curnode->children[word[i] - 'a'] == NULL) return false;
            curnode = curnode->children[word[i] - 'a'];
        }
        return curnode->leaf;
    }
    
    bool startsWith(string prefix) {
        Node* curnode = root;
        for(int i = 0;i<prefix.size();i++){
            if(curnode->children[prefix[i] - 'a'] == NULL) return false;
            curnode = curnode->children[prefix[i] - 'a'];
        }
        return true;
    }
};

int count(Node* n){
    int c = 0;
    for(int i =0;i<26;i++){
        if(n->children[i]!=NULL) c+= count(n->children[i]);
    }
    if(n->leaf) c++;
    return c;
}

int distinctSubstring(string &word) {
    Trie t;
    for(int i =0;i<word.size();i++){
        for(int j = i;j<word.size();j++){
            t.insert(word.substr(i,(j-i + 1)));
        }
    }
    return count(t.root);
}
