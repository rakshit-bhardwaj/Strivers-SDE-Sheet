int longestSubSeg(vector<int> &arr , int n, int k){
    int kc = 0,ans=0;
    int i =0, j =0;
    while(j<n){
        if(arr[j]==0){
            kc ++;
            while(kc > k){
                if(arr[i]==0) kc--;
                i++;
            }
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}
