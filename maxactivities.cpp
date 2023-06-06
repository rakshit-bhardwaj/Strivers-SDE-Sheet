#include<bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> activities;
    int n = start.size();
    for(int i =0;i<n;i++) activities.emplace_back(make_pair(finish[i],start[i]));
    sort(activities.begin(),activities.end());
    int ans = 1,limit = activities[0].first;
    for(int i =1;i<n;i++){
        if(activities[i].second >= limit){
            ans ++;
            limit = activities[i].first;
        }
    }

    return ans;
}
