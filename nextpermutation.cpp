#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    vector<int> ans = permutation;
    int ind = -1;
    for(int i =n-2;i>=0;i--){
        if(ans[i]<ans[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(ans.begin(),ans.end());
        return ans;
    }

    for(int i = n-1;i>ind;i--)
      if (ans[i] > ans[ind]) {
        swap(ans[i], ans[ind]);
        break;
      }

    reverse(ans.begin() + ind +1,ans.end());  
    return ans;
}
