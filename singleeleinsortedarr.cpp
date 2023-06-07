int singleNonDuplicate(vector<int>& arr)
{	if(arr.size()==1) return arr[0];
	int s = 1,e = arr.size()-2;
	if(arr[0]!=arr[1]) return arr[0];
	if(arr[e+1]!=arr[e]) return arr[e+1];

	while(s<=e){
		int m = (s+e)/2;
		if(arr[m]!=arr[m-1] && arr[m]!=arr[m+1]) return arr[m];
		if((m%2==0 && arr[m]==arr[m+1]) || (m%2!=0 && arr[m] == arr[m-1])) s = m+1;
		else e = m-1;
	}
	return -1;
}
