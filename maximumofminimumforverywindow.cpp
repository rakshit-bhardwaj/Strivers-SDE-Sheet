#include <bits/stdc++.h> 
using namespace std;

vector<int> maxMinWindow(vector<int> &a, int n) {
    vector<int> ans(n, INT_MIN);
    vector<int> ns(n,n), ps(n,-1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (!s.empty()) ps[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop(); 

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (!s.empty()) ns[i] = s.top();
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        int len = ns[i] - ps[i] - 1;
        ans[len-1] = max(ans[len-1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}


