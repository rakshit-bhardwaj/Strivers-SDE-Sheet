#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};

class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}

    bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i]) || (i!=0 && !node->isEnd())) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

};
string completeString(int n, vector<string> &a){
    sort(a.begin(),a.end(),[](string &s1,string &s2){
        if(s1.size() > s2.size()) return true;
        else if(s1.size() < s2.size()) return false; 
        return s1 < s2;
        });
    Trie tri;

    for(int i =0;i<n;i++) tri.insert(a[i]);

    for(int i =0;i<n;i++) if(tri.search(a[i])) return a[i];
        

    return "None";
}
