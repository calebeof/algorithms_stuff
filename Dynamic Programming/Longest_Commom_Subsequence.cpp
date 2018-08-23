#include <bits/stdc++.h>

using namespace std;

int lcs (string a, string b){
  int l[a.size()+1][b.size()+1];
  for(int i=0; i<=a.size(); i++)
    for(int j=0; j<=b.size(); j++){
      if(i==0 or j==0)
        l[i][j] = 0;
      else if (a[i-1] == b[j-1])
        l[i][j] = l[i-1][j-1]+1;
      else
        l[i][j] = max(l[i-1][j], l[i][j-1]);
    }
  return l[a.size()][b.size()];
}

int main() {
  string a, b;
  while(getline(cin, a) && getline(cin, b))
    printf("%d\n", lcs(a, b));
  return 0;
}
