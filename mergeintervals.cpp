vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{   
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());

    for(int i =1;i<intervals.size();i++){
        if(intervals[i][0] > intervals[i-1][1]){
            continue;
        } else {
            intervals[i][0] = min(intervals[i-1][0],intervals[i][0]);
            intervals[i][1] = max(intervals[i-1][1],intervals[i][1]);
            intervals[i-1][0] = -1;
            intervals[i-1][1] = -1;
        }
    }

    for(int i =0;i<intervals.size();i++) if(intervals[i][0]!=-1) ans.push_back(intervals[i]);
    
    return ans;
}
