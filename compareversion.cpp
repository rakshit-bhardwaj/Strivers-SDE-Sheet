#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    int64_t  cur1=0,cur2=0;
    int i =0;
    vector<int64_t> v1,v2;
    
    while(i<a.size()){
        if(a[i]=='.'){
            v1.push_back(cur1);
            cur1=0;
        } else cur1 = cur1 * 10 + (a[i] - '0');
        i++;
    }
    v1.push_back(cur1);
    i=0;

    while(i<b.size()){
        if(b[i]=='.'){
            v2.push_back(cur2);
            cur2=0;
        } else cur2 = cur2 * 10 + (b[i] - '0');
        i++;
    }
    v2.push_back(cur2);

    i =0;

    while(i<v1.size() && i<v2.size()){
        if(v1[i] > v2[i]) return 1;
        if(v2[i] > v1[i]) return -1;
        i++;
    }
    while(i<v1.size()){
        if(v1[i]!=0) return 1;
        i++;
    }
    while (i < v2.size()) {
      if (v2[i] != 0)
        return -1;
      i++;
    }
    return 0;
}
