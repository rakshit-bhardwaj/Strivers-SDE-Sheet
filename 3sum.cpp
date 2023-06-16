#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-2;i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int l = i + 1,h = n -1;
            while(l<h){
                if((nums[i] + nums[l] + nums[h]) == K){
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[l]);
                    t.push_back(nums[h]);
                    ans.push_back(t);
                    while(l<h && nums[l]==nums[l+1]) l++;
                    while(h>l && nums[h]==nums[h-1]) h--;
                    l++;h--;
                } else {
                    if(nums[i] + nums[l] + nums[h] > K ) h--;
                    else l++;
                }
                
            }
        }
        return ans;
}
