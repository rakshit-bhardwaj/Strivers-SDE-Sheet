#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int ele = -1;
	int count = 0;
	for(int i =0;i<n;i++){
		if(count == 0) ele = arr[i];
		if(arr[i]==ele) count++;
		else count--;
	}
	count = 0;
	for(int i = 0;i<n;i++) if(ele == arr[i]) count++;
	return count > floor(n/2) ? ele : -1;
}
