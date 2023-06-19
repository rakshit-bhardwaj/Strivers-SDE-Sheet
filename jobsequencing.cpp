#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),[] (vector<int> &a,vector<int> &b){
        return a[1] > b[1];
    });

    vector<int> timeslots(3001,0);
    int ans = 0;
    for(int i =0;i<jobs.size();i++){
        int j = jobs[i][0];
        while(j >=1 && timeslots[j]==1) j--;
        if(j >=1){
            timeslots[j] = 1;
            ans+=jobs[i][1];
        }
    }
    return ans;
}
