int search(int* arr, int n, int key) {
    int s = 0,e = n-1;
    while(s<=e){
        int m = s + ((e-s) >> 1);
        if(arr[m] == key) return m;
        if(arr[s] <= arr[m]){
            if(key >= arr[s] && key < arr[m]) e = m-1;
            else s = m+1;
        } else {
            if(key > arr[m] && key <= arr[e]) s = m+1;
            else e = m-1;
        }
    }
    return -1;
}
