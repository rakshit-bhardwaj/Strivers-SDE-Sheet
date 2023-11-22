class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minsum = 1e9;
        int maxsum = -1e9;

        int totsum = accumulate(nums.begin(),nums.end(),0);
        int cursummin = 0,cursummax = 0;

        for(int i =0;i<nums.size();i++){
            cursummin += nums[i];
            cursummax += nums[i];
            minsum = min(minsum,cursummin);
            cursummin = min(0,cursummin);
            maxsum = max(maxsum,cursummax);
            cursummax = max(0,cursummax); 
        }

        return totsum == minsum ? maxsum : max(maxsum,totsum - minsum);
    }
};
