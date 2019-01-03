#include <bits/stdc++.h>

#define vi vector<int>
#define pb push_back

using namespace std;

void divisors(int n) { 
  vi div;
  for (int i=1; i<=sqrt(n); i++) { 
    if (n%i==0) { 
      if (n/i == i)
        div.pb(i);
      else{ 
        div.pb(i);
        div.pb(n/i); 
      } 
    } 
  } 
  sort(div.begin(),div.end());
  for (int i=0; i<div.size(); i++) 
    cout << div[i] << " ";
  cout << endl;
} 

int main () {
  int n;
  while(cin >> n)
    divisors(n);
  return 0;
}
