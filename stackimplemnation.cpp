#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int> stack;
    int size,cur;
    Stack(int capacity) {
        stack.resize(capacity);
        size = capacity;
        cur = 0;
    }

    void push(int num) {
      if (cur != size) {
        stack[cur] = num;
        cur++;
      }
    }

    int pop() {
        if(cur==0) return -1;
        int num = stack[cur-1];
        cur--;
        return num;
    }
    
    int top() {
        if(cur==0) return -1;
        return stack[cur-1];
    }
    
    int isEmpty() {
        return cur == 0;
    }
    
    int isFull() {
        return cur == size;
    }
    
};
