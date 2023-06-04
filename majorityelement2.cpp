#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n =arr.size();
    int req = floor(n/3);
    vector<int> ans;
    int num1=-1,num2=-1,c1 =0,c2=0;
    for(auto num : arr){
        if(num == num1) c1++;
        else if(num == num2) c2++;
        else if(c1 == 0){
            num1 = num;
            c1 = 1;
        } else if(c2 == 0){
            num2 = num;
        }
        else {
            c1 --;
            c2 --;
        }
    }
    c1  = 0;c2=0;
    for(auto num : arr){
        if(num == num1) c1++;
        else if(num == num2) c2++;
    }
    if(c1 > req) ans.push_back(num1);
    if(c2 > req) ans.push_back(num2);
    return ans;
}
