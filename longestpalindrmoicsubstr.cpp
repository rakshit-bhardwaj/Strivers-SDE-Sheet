string longestPalinSubstring(string str)
{   
    string ans;
    int lp = 0;
    for(int i =0;i<str.size();i++){
        int x = i,y = i;
        while (x >= 0 && y < str.size() && str[x] == str[y]) {
          if (y - x + 1 > lp) {
            ans = str.substr(x, y - x + 1);
            lp = y - x + 1;
          }
          x--;
          y++;
        }
        x = i,y = i+1;
        while (x >= 0 && y < str.size() && str[x] == str[y]) {
          if (y - x + 1 > lp){
            ans = str.substr(x, y - x + 1);
            lp = y - x + 1;
            }
          x--;
          y++;
        }
        
    }
    return ans;
}
