int kthlargest(vector<int> &arr,int l,int r,int k){

    if(l==r) return arr[l];

    int p = l;

    int pivot = arr[r];

    for(int i = l;i<r;i++){

        if(arr[i] < pivot){

            swap(arr[i],arr[p++]);

        }

    }

    swap(arr[r],arr[p]);

    if(p >= k) return kthlargest(arr,l,p-1,k);

    if(p < k-1) return kthlargest(arr,p+1,r,k);

    else return arr[p];

}
