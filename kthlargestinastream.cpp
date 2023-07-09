#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    Kthlargest(int k, vector<int> &arr) {
       for(auto x : arr) q.push(x);
       while(q.size() != k) q.pop();
    }

    void add(int num) {
        q.push(num);
        q.pop();
    }

    int getKthLargest() {
       return q.top();
    }

};
