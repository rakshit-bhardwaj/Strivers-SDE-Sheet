#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) {
    unordered_map<int, int> m;
    vector<int> ans;
    int count = 0;

    for (int i = 0; i < k; i++) {
        m[arr[i]]++;
        if (m[arr[i]] == 1)
            count++;
    }
    ans.push_back(count);

    for (int i = k; i < arr.size(); i++) {
        m[arr[i - k]]--;
        if (m[arr[i - k]] == 0)
            count--;

        m[arr[i]]++;
        if (m[arr[i]] == 1)
            count++;

        ans.push_back(count);
    }

    return ans;
}
