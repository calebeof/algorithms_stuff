#include <bits/stdc++.h>

#define vi vector<int>
#define ll long long int 

#define TAM 100000

using namespace std;

void sieve (vi &primos){
  bool mark[TAM] = {};
  for(int i=2; i<TAM; i++){
    if(!mark[i]){
      mark[i] = true;
      primos.push_back(i);
      for(int j = i+i; j<TAM; j+=i)
        mark[j] = true;
    }
  }
}

int phi(int n, vi &primos){
  int res = n;
  for (int p: primos){
    if(n%p==0){
      res-=res/p;
      while(n%p==0)
        n/=p;
    }
    if(p>n)
      break;
  }
  if(n>1)
    res-=res/n;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  vi primos;
  sieve(primos);
  while(cin >> n)
    cout << phi(n, primos) << endl;
  return 0;
}
