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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie tri;
	vector<int> ans(queries.size());
	for(int i = 0;i<queries.size();i++) queries[i].push_back(i);
	sort(queries.begin(),queries.end(),[](vector<int> &a,vector<int> &b){return a[1] < b[1];});
	sort(arr.begin(),arr.end());
	int i =0;
	for(int q =0;q<queries.size();q++){
		while(i<arr.size() && arr[i] <= queries[q][1]){
			tri.insert(arr[i]);
			i++;
		}
		if(queries[q][1] >= arr[0])
			ans[queries[q][2]] = tri.getmax(queries[q][0]);
		else ans[queries[q][2]] = -1;
	}
	return ans;
}
