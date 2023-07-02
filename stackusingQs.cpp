#include <bits/stdc++.h> 
class Stack {
	// Define the data members.

   public:
    queue<int> q1,q2;
    int size = 0;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(int element) {
        q1.push(element);
        size++;
    }

    int pop() {
        if(q1.empty()) return -1;
        int topelement;
        while(!q1.empty()){
            topelement = q1.front();
            if(q1.size()>1)q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        size--;
        return topelement;
    }

    int top() {
        if(q1.empty()) return -1;
        int topelement;
        while(!q1.empty()){
            topelement = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        
        return topelement;
    }
};
