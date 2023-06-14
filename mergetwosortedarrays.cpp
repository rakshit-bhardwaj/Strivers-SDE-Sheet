#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	for(int i =m;i<m+n;i++){
		arr1[i] = arr2[i-m];
	}

	int l = 0,r = m + 1;
	int len = m + n;
	int gap = (len/2) + len%2;

	while(gap>0){
		int left = 0;
		int right = gap;
		while(right < len){
			if(arr1[left]> arr1[right]) swap(arr1[left],arr1[right]);
			left++;right++;
		}
		if(gap==1) break;
		gap = gap/2 + gap%2;
	}
	return arr1;
}
