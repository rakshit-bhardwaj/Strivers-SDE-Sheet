#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= k; sum++) {
            if (arr[i - 1] > sum) {
                dp[i][sum] = dp[i - 1][sum];
            } else {
                dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - arr[i - 1]];
            }
        }
    }

    return dp[n][k];
}
