#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int count  = 0;
    int xr = 0;
    unordered_map<int,int> m;
    
    for(int i =0;i<arr.size();i++){
        xr = xr ^ arr[i];
        if(xr == x) count++;
        if(m.find(xr ^ x)!=m.end()) count += m[xr ^ x];
        m[xr]++;
    }
    return count;
}
