#include <bits/stdc++.h> 
using namespace std;

vector<int> merge(vector<int> &a,vector<int> &b){
    int i =0,j=0;
    vector<int> temp;
    while(i<a.size() && j<b.size()){
      if (a[i] <= b[j]) temp.push_back(a[i++]);
      else temp.push_back(b[j++]);
    }
    
    while(i<a.size()) temp.push_back(a[i++]);
    while(j<b.size()) temp.push_back(b[j++]);

    return temp;
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    if(k==1) return kArrays[0];
    vector <int> temp = kArrays[k-1];
    for(int i = k-2;i>=0;i--){
        temp = merge(kArrays[i],temp);
    }
    return temp;
}
