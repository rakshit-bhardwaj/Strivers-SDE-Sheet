#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int ans = 1;
    if(n==1) return 1;
    unordered_set<int> s;
    for(auto x : arr) s.insert(x);
    for(int i = 0;i<n;i++){
        int cur = arr[i];
        if(s.find(arr[i]-1)!=s.end()) continue;
        int count = 1;
        while(s.find(cur + 1)!=s.end()){
            count++;
            cur = cur+1;
        }
        ans = max(count,ans);
    }
    return ans;
}
