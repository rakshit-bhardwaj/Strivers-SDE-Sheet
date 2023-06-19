int calculateMinPatforms(int at[], int dt[], int n) {
    vector<int> atv,dtv;
    for(int i =0;i<n;i++){
        atv.push_back(at[i]);
        dtv.push_back(dt[i]);
    }
    sort(atv.begin(),atv.end());
    sort(dtv.begin(),dtv.end());

    int i =0,j=0,ans = 0;
    for(int x = 0;x<n;x++){
        if(atv[i] <= dtv[j]){
            ans++;
        } else j++;
        i++;
    }
    return ans;
}
