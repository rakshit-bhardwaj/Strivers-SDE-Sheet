#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{   
    vector<int> lps(p.size(),0);
    int prev = 0,i=1,j;
    while(i<p.size()){
        if(p[i] == p[prev]){
            lps[i] = prev + 1;
            prev += 1;
            i += 1;
        } else if(prev == 0){
                lps[i] = 0;
                i++;
            } 
        else prev = lps[prev - 1]; 
    }

    j =0,i=0;
    while(i<s.size()){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        else{
            if(j==0) i++;
            else j = lps[j-1];
        }
        if(j==p.size()) return true;
    }
    
    return false;
}
