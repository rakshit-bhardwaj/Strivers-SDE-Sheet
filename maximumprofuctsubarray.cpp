#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int ans = INT_MIN;
	int prefix=1,suffix = 1;
	for(int i = 0;i<arr.size();i++){
		if(prefix == 0) prefix = 1;
		if(suffix == 0) suffix = 1;

		prefix = arr[i] * prefix;
		suffix = arr[n-i-1] * suffix;
		ans = max(ans,max(prefix,suffix));
	}
	return ans;
}
