int NthRoot(int n, int m) {
  int s = 1,e = m/2 +1;
  while(s <= e){
    int mid = s + (e-s)/2;
    if(pow(mid,n)==m) return mid;
    if(pow(mid,n)>m) e = mid-1;
    else s = mid+1;
  }
  return -1;
}
