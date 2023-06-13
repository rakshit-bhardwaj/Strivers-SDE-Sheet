#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{   
    long long ans = 0,cur=0;
    int i =0;
    while(i < n && arr[i] <= 0) i++;
    for(i;i<n;i++){
        cur += arr[i];
        if(cur < 0) cur = 0;
        ans = max(cur,ans);
        ans = max(ans,(long long) arr[i]);
    }
    return ans;
}
