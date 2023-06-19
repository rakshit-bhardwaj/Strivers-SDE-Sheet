#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long ans = 0;
    int l = 0,r = n-1;
    long lmax = arr[l],rmax = arr[r];
    while(l<r){
        if(lmax < rmax){
            l++;
            lmax = max(lmax,arr[l]);
            ans += lmax - arr[l];
        } else {
            r--;
            rmax = max(rmax,arr[r]);
            ans += rmax - arr[r];
        }
    }
    return ans;
}
