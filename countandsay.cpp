#include <bits/stdc++.h> 

string func(string s){
	int count=1;
	char cur = s[0];
	string t;
	for(int i =1;i<s.size();i++){
		if(s[i]==cur) count++;
		else{
			t.push_back(count + '0');
			t.push_back(cur);
			count = 1;
			cur = s[i];
		}
	}
	t.push_back(count + '0');
	t.push_back(s[s.size()-1]);
	
	return t;
}

string writeAsYouSpeak(int n) 
{	
	string s = "1";
	for(int i =0;i<n-1;i++){
		s = func(s);
	}
	return s;
}
