bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int x=-1;
    int s = 0,e = n-1;
    while(s <= e){
        int mid = (s+e)/2;
        if(target>=mat[mid][0] && target<=mat[mid][m-1]){
            x = mid;
            break;
        }
        if(target < mat[mid][0]) e = mid - 1;
        else s = mid + 1;
    }
    if(x==-1) return false;
    s = 0;e = m-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(mat[x][mid]==target) return true;
        if(mat[x][mid] > target) e = mid-1;
        else s = mid + 1;
    }
    return false;
}
