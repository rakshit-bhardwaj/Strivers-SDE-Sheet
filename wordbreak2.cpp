#include <bits/stdc++.h> 

void fun(vector<string>&ans,int mx,string w,unordered_set<string>&s,string str)
{
    if(w.size()==0&& str.size() > 0)
    {
       ans.push_back(str);
       return;
    }
    else
    {
        int N=w.size();
        string str1="";
        for(int i=0;i<N;i++)
        {
            str1+=w[i];
            if(str1.size()>mx)break;
            if(s.count(str1))
            {
                string new_str = (str == "") ? str1 : str + " " + str1;

                fun(ans,mx,w.substr(i+1),s,new_str);            
            }
        } 
    }
}

vector<string> wordBreak(string &w, vector<string> &dict)

{
    unordered_set<string>st;
    int n=dict.size();
    int mx=INT_MIN;

    for(int i=0;i<n;i++)
    {
     st.insert(dict[i]);  
     int siz=dict[i].size();
     mx=max(mx,siz);
    } 
    vector<string>ans;
    fun(ans,mx,w,st,"");
    return ans;
}
