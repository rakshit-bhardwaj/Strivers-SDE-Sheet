#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> s;
	int min;
	public:
		
		// Constructor
		minStack() 
		{ 

		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{	
			if(!s.empty()){
				if(num >= min) s.push(num);
				else {
					s.push(2 * num - min);
					min = num;
				}
			} else{
				min = num;
				s.push(num);
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(s.empty()) return -1;
			if(s.top() < min) {
				int prev = min;
				min = 2*min - s.top();
				s.pop();
				return prev;
			} else {
				int top = s.top();
				s.pop();
				return top;
			}
			
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(s.empty()) return -1;
			if(s.top() < min) return min;
			else return s.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(s.empty()) return -1;
			return min;
		}
};
