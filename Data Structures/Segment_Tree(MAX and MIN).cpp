#include <bits/stdc++.h>

#define vi vector<int> 
#define pb push_back
#define INF 10000000
#define MAX 100100
using namespace std;

vi tree_min(4*MAX), tree_max(4*MAX);
int n;

void update_min(int v, int tl, int tr, int pos, int new_val){
  if(tl == tr)
    tree_min[v] = new_val;
  else{
    int tm = (tl+tr)/2;
    if(pos<=tm)
      update_min(v*2, tl, tm, pos, new_val);
    else
      update_min(v*2 + 1, tm+1, tr, pos, new_val);
    tree_min[v] = min(tree_min[v*2],tree_min[v*2 + 1]);
  }
}

void update_max(int v, int tl, int tr, int pos, int new_val){
  if(tl == tr)
    tree_max[v] = new_val;
  else{
    int tm = (tl+tr)/2;
    if(pos<=tm)
      update_max(v*2, tl, tm, pos, new_val);
    else
      update_max(v*2 + 1, tm+1, tr, pos, new_val);
    tree_max[v] = max(tree_max[v*2], tree_max[v*2 + 1]);
  }
}

void build_min(vi &arr, int v, int tl, int tr){
  if(tl==tr)
    tree_min[v] = arr[tl];
  else{
    int tm = (tl+tr)/2;
    build_min(arr, v*2, tl, tm);
    build_min(arr, v*2 + 1, tm+1, tr);
    tree_min[v] = min(tree_min[v*2],tree_min[v*2 + 1]);
  }
}

void build_max(vi &arr, int v, int tl, int tr){
  if(tl==tr)
    tree_max[v] = arr[tl];
  else{
    int tm = (tl+tr)/2;
    build_max(arr, v*2, tl, tm);
    build_max(arr, v*2 + 1, tm+1, tr);
    tree_max[v] = max(tree_max[v*2], tree_max[v*2 + 1]);
  }
}

int get_max(int v, int tl, int tr, int l, int r){
  if(l > r)
    return -INF;
  if(l== tl && r == tr)
    return tree_max[v];
  int tm = (tl+tr)/2;
  return max(get_max(v*2, tl, tm, l, min(r,tm)), get_max(v*2 + 1, tm+1, tr, max(l, tm+1), r));
}

int get_min(int v, int tl, int tr, int l, int r){
  if(l > r)
    return INF;
  if(l == tl && r == tr)
    return tree_min[v];
  int tm = (tl+tr)/2;
  return min(get_min(v*2, tl, tm, l, min(r,tm)),get_min(v*2 + 1, tm +1, tr, max(l, tm+1), r));
}

int main() {
  int queries;
  ios_base::sync_with_stdio(false);
  while(cin >> n){
    vi arr;
    for(int i=0; i<n; i++){
      int a;
      cin >> a;
      arr.pb(a);
    }
    build_min(arr, 1, 0, n-1);
    build_max(arr, 1, 0, n-1);
    //for(int i=0; i<100; i++)
      //cout << tree_min[i] << " ";
    cin >> queries;
    for(int i=0; i<queries; i++){
      int a, b, c;
      cin >> a >> b >> c;
      b--;
      if(a == 1){
        update_min(1, 0, n-1, b, c);
        update_max(1, 0, n-1, b, c);
      }
      else{
        c--;
        cout << get_max(1, 0, n-1, b, c) << " " << get_min(1, 0, n-1, b, c) << endl;
      }
    }
  }
  return 0;
}
