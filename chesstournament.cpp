#include <bits/stdc++.h> 
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	int e = positions[n-1] - positions[0];
	int s = 1,m,ans;
	while(s<=e){
		m = (s+e) >> 1;
		int count = c;
		int limit = -1e9;
		for(int i = 0;i<n;i++){
			if(positions[i] - limit >= m){
				limit = positions[i];
				count--;
				if(count == 0) break;
			}
		}
		if(count == 0){
			s = m+1;
			ans = m;
		} else e = m-1;
	}
	return ans;
}
