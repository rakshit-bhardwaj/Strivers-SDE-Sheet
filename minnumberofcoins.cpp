#include <bits/stdc++.h> 

int findMinimumCoins(int amount) 
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int i = coins.size() -1,curam = 0,curcoin = 0;
    while(i>=0){
        if(curam == amount) return curcoin;
        if(curam + coins[i] <= amount){
            curam += coins[i];
            curcoin++;
            continue;
        }
        i--;
    }
    return curcoin;
}

