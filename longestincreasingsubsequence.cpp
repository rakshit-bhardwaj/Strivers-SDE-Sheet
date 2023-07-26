#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& tails, int target) {
    int left = 0, right = tails.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (tails[mid] == target)
            return mid;
        else if (tails[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int longestIncreasingSubsequence(int arr[], int n) {
    if (n == 0) return 0;

    vector<int> tails;
    tails.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > tails.back()) {
            tails.push_back(arr[i]);
        } else {
            int index = binarySearch(tails, arr[i]);
            tails[index] = arr[i];
        }
    }

    return tails.size();
}
