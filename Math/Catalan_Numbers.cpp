#include<bits/stdc++.h>

#define TAM 1000

using namespace std;

int main()
{
  unsigned long long int catalan[TAM];
  catalan[0] = 1;
  catalan[1] = 1;
  int n;
  cin >> n;
 
  for (int i=2; i<=n; i++)
  {
    catalan[i] = 0;
    for (int j=0; j<i; j++)
      catalan[i] += catalan[j] * catalan[i-j-1];
  }
  cout << catalan[n] << "\n";
  return 0;
}
