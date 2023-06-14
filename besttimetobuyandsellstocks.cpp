#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int ans = 0;
    int b = prices[0];
    for(int i =1;i<prices.size();i++){
        ans = max(ans,prices[i] - b);
        b = min(b,prices[i]);
    }
    return ans;
}
