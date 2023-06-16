#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{   
    int ans = 1,st=0;
    unordered_map<int,int> m;
    for(int i =0;i<input.size();i++){
        if(m.find(input[i])==m.end()){
            m[input[i]] = i;
        } else {
            st = max(m[input[i]] + 1,st);
            m[input[i]] = i;
        }
        ans = max(ans,i-st+1);
    }
    return ans;
}
