#include <bits/stdc++.h> 
void func(string &s,string t,vector<string> &ans,int x){
    if(t.size()==s.size()){
        ans.push_back(t);
        return;
    }
    for(int i =0;i<s.size();i++){
        if(s[i]== '_') continue;
        string u = t;
        u.push_back(s[i]);
        char v = s[i];
        s[i] = '_';
        func(s,u,ans,i);
        s[i] = v;
    }
}
vector<string> findPermutations(string &s) {
    vector<string> ans;
    for(int i =0;i<s.size();i++){
        string t;
        t.push_back(s[i]);
        char v = s[i];
        s[i] = '_';
        func(s,t,ans,i);
        s[i] = v;
    }
    return ans;
}
