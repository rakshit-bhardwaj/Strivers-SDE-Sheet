#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<int> ans;
    vector<vector<int>> v;
    int limit;
    for(int i=0;i<start.size();i++) v.push_back({end[i],start[i],i});
    sort(v.begin(),v.end(),[](const vector<int> &a,const vector<int> &b){
        if(a[0]<b[0]) return true;
        else if(a[0]>b[0]) return false;
        if(a[2] < b[2]) return true;
        return false;
        });

    ans.push_back(v[0][2] + 1);
    limit = v[0][0];

    for(int i =1;i<start.size();i++){
        if(v[i][1]>limit){
            ans.push_back(v[i][2]+1);
            limit = v[i][0];
        }
    }
    return ans;
}
