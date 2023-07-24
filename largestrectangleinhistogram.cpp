#include<bits/stdc++.h> 
using namespace std;

 int largestRectangle(vector < int > & heights) {
   int n = heights.size();
   vector<int> post(n),pre(n);
   stack<int> s1,s2;
   for(int i=0;i<n;i++){
     while(!s1.empty() && heights[s1.top()] >= heights[i]) s1.pop();
     if(!s1.empty()) pre[i] = s1.top();
     else  pre[i] = -1;
     s1.push(i);
   }

   for(int i=n-1;i>=0;i--){
     while(!s2.empty() && heights[s2.top()] >= heights[i]) s2.pop();
     if(!s2.empty()) post[i] = s2.top();
     else post[i] = n;
     s2.push(i);
   }

    int ans = 0;
    for(int i =0;i<n;i++){
      int cur = heights[i] * (post[i] - pre[i] - 1);
      ans = max(ans,cur);
    }

    return ans;

 }
