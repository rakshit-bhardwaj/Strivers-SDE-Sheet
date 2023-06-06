#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double maxval = 0;
    sort(items.begin(),items.end(),[] (const pair<int,int> &a,const pair<int,int> &b) {
        return (double) a.second / a.first > (double) b.second / b.first;
    });
    
    int rem=w;
    for(int i =0;i<n;i++){
        if(rem >= items[i].first){
            maxval += items[i].second;
            rem -= items[i].first;
            continue;
        } else {
            maxval += (double) (rem/(double)items[i].first) * items[i].second;
            break;
        }
    }
    return maxval;
}
