int findCelebrity(int n) {
	stack<int> s;
	for(int i =0;i<n;i++) s.push(i);

	while(s.size()>1){
		int a = s.top();
		s.pop();
		int b = s.top();
		s.pop();

		if(knows(a,b)) s.push(b);
		else s.push(a);
	}

	int cad = s.top();
	
	for(int i =0;i<n;i++){
		if(i!= cad && knows(cad,i)) return -1;
		if(i!= cad && !knows(i,cad)) return -1;
	}
	return cad;
}
