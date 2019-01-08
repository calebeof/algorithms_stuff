#include <bits/stdc++.h>

#define vi vector<int>
#define pb push_back
using namespace std;

struct Node {
  Node *l, *r;
  int sum;
  Node(int value):l(nullptr), r(nullptr), sum(value){}
  Node(Node *l, Node *r) : l(l), r(r), sum(0) {
    if (l) sum += l->sum;
    if (r) sum += r->sum;
  }
};

vector<Node*> versions;

Node* build (vi &arr, int tl, int tr){
  if (tl==tr)
    return new Node(arr[tl]);
  int tm = (tl+tr)>>1;
  return new Node(build(arr, tl, tm), build(arr, tm+1, tr));
}

int get_sum(Node* v, int tl, int tr, int l, int r){
  if(l>r)
    return 0;
  if(l==tl && tr == r)
    return v-> sum;
  int tm = (tl+tr)>>1;
  return get_sum(v->l, tl, tm, l, min(r, tm)) + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Node* update(Node* v, int tl, int tr, int pos, int value){
  if (tl==tr)
    return new Node(value);
  int tm = (tl+tr)>>1;
  if(pos<=tm)
    return new Node(update(v->l, tl, tm, pos, value), v->r);
  else
    return new Node(v->l, update(v->r, tm+1, tr, pos, value));
}

int main () {
  ios_base::sync_with_stdio(false);
  int t;
  while(cin >> t){
    while(t--){
      int n;
      vi arr;
      cin >> n;
      for(int i=0; i<n; i++){
        int a;
        cin >> a;
        arr.pb(a);
      }
      versions.pb(build(arr, 0, n-1));
      int op;
      cin >> op;
      for(int i=0; i<op; i++){
        int a, x;
        cin >> a >> x;
        if(a==1){
          int y, k;
          cin >> y >> k;
          x--, y--;
          cout << get_sum(versions[k], 0, n-1, x, y) << endl;
        }else{
          int w;
          cin >> w;
          x--;
          versions.pb(update(versions[versions.size()-1],0, n-1, x, w));
        }
      }
      versions.clear();    
    }
  }
  return 0;
}
