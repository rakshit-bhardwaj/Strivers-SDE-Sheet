#include<bits/stdc++.h>
using namespace std;

class Queue {
    // Define the data members(if any) here.
    

    public:
    stack<int> s1,s2;
    int size =0;

    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        s1.push(val);
        size++;
    }

    int deQueue() {
        if(size==0) return -1;
        int top;
        while(!s1.empty()){
            top = s1.top();
            s2.push(top);
            s1.pop();
        }
        top = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        size--;
        return top;
    }

    int peek() {
        if(size==0) return -1;
        int top;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        top = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
            
        return top;
    }

    bool isEmpty() {
        return size == 0;
    }
};
