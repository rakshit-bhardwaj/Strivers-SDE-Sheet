#include <bits/stdc++.h> 
int atoi(string str) {
    int num = 0;
    bool neg = false;
    if(str[0]=='-') neg = true;
    for(auto c : str){
        if(c >= '0' && c <='9'){
            num = num * 10 + (c-'0');
        }
    }
    if(neg) num = num * -1;
    return num;
}
