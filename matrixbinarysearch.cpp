bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int x=-1;
    for(int i = 0;i<n;i++){
        if(target>=mat[i][0] && target<=mat[i][m-1]){
            x = i;
            break;
        }
    }
    if(x==-1) return false;
    int s = 0,e = m-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(mat[x][mid]==target) return true;
        if(mat[x][mid] > target) e = mid-1;
        else s = mid + 1;
    }
    return false;
}
