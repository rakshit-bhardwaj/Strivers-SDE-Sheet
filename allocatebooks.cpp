#include <bits/stdc++.h> 
using namespace std;

bool check(vector<int> &time,int n,long long cur){
	long long prefix=0;int count = 0;
	for(int i =0;i<time.size();i++){
		if(prefix + time[i]<=cur){
			prefix += time[i];
		} else {
			prefix = time[i];
			count++;
		}
	}
	return count<n;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	
	long long e = 0;
	long long s = 0;
	int maxi=0;
    for(auto it:time)
    {
        e+=it;
        maxi=max(maxi,it);
    }
	
	long long ans = 0;
	s = maxi;
	while(s<=e){
		long long mid = s + ((e-s) >> 1);
		if(check(time,n,mid)){
			ans = mid;
			e = mid-1;
		} else {
			s = mid+1;
		}	
	}
	return ans;
	
}
