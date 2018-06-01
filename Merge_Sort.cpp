#include <bits/stdc++.h>

using namespace std;

int merge (vector <int> &v){
  if (v.size()==1)
    return 0;
  vector <int> esq(v.begin(), v.begin()+v.size()/2), dir (v.begin()+v.size()/2, v.end());
  int cont = 0; 
  cont+=merge(esq);
  cont+=merge(dir);
  int d=0, e=0;
  for (int i=0; i<v.size(); i++){
    if (e==esq.size())
      v[i]=dir[d++];
    else if (d==dir.size() or esq[e]<=dir[d])
      v[i]=esq[e++];
    else{
      v[i] = dir [d++];
      cont+=esq.size()-e;
    }
  }
  return cont; 
}

int main() {
  vector <int> v;
  int n;
  cin >> n;
  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  int inversoes = merge (v);
  cout << inversoes << "\n";  
  return 0; 
}
