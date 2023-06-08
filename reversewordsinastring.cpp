string reverseString(string &str){
	int i =0,n = str.size();
	while(str[i] == ' ') i++;
	string ans;
	vector<string> strv;
	string cur;
	while(i<n){
		if(str[i] == ' ' ){
			if(cur.size()==0){
				i++; continue;
			}
			strv.push_back(cur);
			cur = "";
		} else {
			cur.push_back(str[i]);
		}
		i++;
	}
	if(cur.size()!=0) strv.push_back(cur);

	for(int i = strv.size()-1;i>=0;i--){
		string word = strv[i];
		ans.append(word);
		ans.push_back(' ');
	}
	ans.pop_back();
	return ans;
}
