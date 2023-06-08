#include <bits/stdc++.h> 
void insertele(stack<int> &stack,int ele){
	if(stack.empty() || ele >= stack.top()){
		stack.push(ele);
	} else {
		int t = stack.top();
		stack.pop();
		insertele(stack,ele);
		stack.push(t);
	}
}

void func(stack<int> &stack){
	if(stack.size() <=1) return;

	int t1 = stack.top();
	stack.pop();
	func(stack);
	insertele(stack,t1);

}
void sortStack(stack<int> &stack)
{
	func(stack);
}
