#include <bits/stdc++.h> 

void push(vector<int> &heap,int num){
    heap.push_back(num);
    int i = heap.size()-1;
    while(i>0){
        int parent = (i-1)/2;
        if(heap[parent]>heap[i]){
            swap(heap[parent],heap[i]);
            i = parent;
        } else return;
    }
}

int min(vector<int> &heap){
    int ans = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int i =0;
    while(i<heap.size()){
        int smaller = 2*i + 1;
        if(smaller>= heap.size()) return ans;
        if(smaller + 1 < heap.size()){
            smaller = heap[smaller] <= heap[smaller + 1] ? smaller : smaller + 1;
        }
        if(heap[i] > heap[smaller]){
            swap(heap[i],heap[smaller]);
            i = smaller;
        } else return ans;
    }
    return ans;
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> heap,ans;
    for(int i =0;i<n;i++){
        if(q[i].size() == 1) ans.push_back(min(heap));
        else push(heap,q[i][1]);
    }
    return ans;
}
