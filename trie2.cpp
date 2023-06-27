#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<node*> children;
    int ew = 0,pt = 0;
    node() {
        children.resize(26);
    }
};

class Trie {
private:
    node* root;

public:
    Trie() {
        root = new node();
    }

    void insert(string& word) {
        node* n = root;
        for (int i = 0; i < word.size(); i++) {
            if (n->children[word[i] - 'a']== NULL)
                n->children[word[i] - 'a'] = new node();
            n->pt++;
            n = n->children[word[i] - 'a'];
        }
        n->ew++;
    }

    int countWordsEqualTo(string& word) {
        int minc = INT_MAX;
        node* n = root;
        for (int i = 0; i < word.size(); i++) {
            if (n->children[word[i] - 'a'] == NULL)
                return 0;
            if (n->pt == 0)
                return 0;
            minc = min(n->pt, minc);
            n = n->children[word[i] - 'a'];
        }
        return min(minc,n->ew);
    }

    int countWordsStartingWith(string& word) {
        node* n = root;
        for (int i = 0; i < word.size(); i++) {
            if (n->children[word[i] - 'a'] == NULL)
                return 0;
            if (n->pt == 0)
                return 0;
            n = n->children[word[i] - 'a'];
        }
        return max(max(1,n->pt),n->ew);
    }

    void erase(string& word) {
        node* n = root;
        for (int i = 0; i < word.size(); i++) {
            n->pt--;
            n = n->children[word[i] - 'a'];
        }
        n->ew--;
    }
};
