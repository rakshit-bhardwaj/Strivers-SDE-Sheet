#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> q;
    int cur=0,fr=0,size=0;
    Queue() {
        q.resize(5000);
    }   

    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty() {
        return size==0;
    }

    void enqueue(int data) {
        size++;
        q[cur++] = data;
    }

    int dequeue() {
        if(size==0) return -1;
        size--;
        return q[fr++];
    }

    int front() {
        if(size==0) return -1;
        return q[fr];
    }
};
