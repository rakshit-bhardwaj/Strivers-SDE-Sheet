#include<bits/stdc++.h>
using namespace std;
typedef priority_queue<int> maxheap;
typedef priority_queue<int,vector<int>,greater<int>> minheap;

void insert(maxheap &maxpq,minheap &minpq,int x){
    if(maxpq.size() == minpq.size()){
        if(maxpq.size()==0){
            maxpq.push(x);
        }
        else{
            if(x < maxpq.top()) maxpq.push(x);
            else minpq.push(x);
        }
    } else if(maxpq.size() > minpq.size()){
        if(x >= maxpq.top()) minpq.push(x);
        else{
            int temp = maxpq.top();
            maxpq.pop();
            maxpq.push(x);
            minpq.push(temp);
        }
    } else {
        if(x <= minpq.top()) maxpq.push(x);
        else{
            int temp = minpq.top();
            minpq.pop();
            minpq.push(x);
            maxpq.push(temp);
        }
    }
}

int findmedian(maxheap &maxpq,minheap &minpq){
    if(maxpq.size() == minpq.size()) return (maxpq.top() + minpq.top())/2;
    else if(maxpq.size() > minpq.size()) return maxpq.top();
    else return minpq.top();
}

void findMedian(int *arr, int n)
{
    maxheap maxpq;minheap minpq;
    for(int i =0;i<n;i++){
        insert(maxpq,minpq,arr[i]);
        cout<<findmedian(maxpq,minpq)<<" ";
    }
}
