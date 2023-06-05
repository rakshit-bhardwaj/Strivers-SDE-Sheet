#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
   unordered_map<int,int> m;
   for(auto num : arr){
      if(m.find(s-num)!=m.end()) {
         int x = m[s-num];
         while(x--){
            ans.push_back({min(num, s - num), max(num, s - num)});
         }
      }
      m[num]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}
