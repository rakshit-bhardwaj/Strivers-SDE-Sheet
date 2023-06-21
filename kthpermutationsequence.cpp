#include<bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k) {
    int fact=1;
    vector<int> nums;
    string ans;
    k--;
    for (int i = 1; i < n; i++) {
      nums.push_back(i);
      fact *= i;
    } 
    nums.push_back(n);
    
    while(true){
        ans.push_back(nums[k / fact] + '0');
        nums.erase(nums.begin() + k/fact);
        if(nums.size()==0) break;
        k = k%fact;
        fact = fact/nums.size();
    }
    return ans;
}
