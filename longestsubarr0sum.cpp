#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > nums) {
  unordered_map<int,int> m;
  int k = 0;
    int l = 0,prefixsum = 0;
    for(int i = 0;i<nums.size();i++){
        prefixsum += nums[i];
        if(prefixsum == k){
            l = max(l,i+1);
        }
        if(m.find(prefixsum - k)!=m.end()){
            l = max(l,i - m[prefixsum-k]);
        }
        if(m.find(prefixsum)==m.end()) m[prefixsum] = i;
    }
    return l;

}

