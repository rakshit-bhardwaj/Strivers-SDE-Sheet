#include <bits/stdc++.h>
string fourSum(vector<int> nums, int target, int n) {
        int sum,i,j,l,h;
        if(n<4) return "NO";
        sort(nums.begin(),nums.end());
        for(i=0;i<n-3;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
            for(j=i+1;j<n-2;j++){
                if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){
            
            int l = j+1, h = n-1, sum = target-nums[i]-nums[j];
                while(l<h){
                    if(nums[l]+nums[h]==sum){
                        return "Yes";
                    }
                    else if((nums[l]+nums[h]) < sum) l++;
                    else h--;
                } 
                }
            }
            }
        }
        return "No";
}
