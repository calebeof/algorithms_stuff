#include <bits/stdc++.h>

using namespace std;

long long int gcd (long long int a, long long int b){
  if (b==0)
    return a;
  else
    return gcd (b, a%b);
}

long long int lcm (long long int a, long long int b){
  return (a*b)/(gcd(a,b));
}

int main() {
  int a, b;
  cin >> a >> b;
  printf("Greatest common divisor: %lld\n", gcd(a, b));
  printf("Least common multiple: %lld\n", lcm(a, b));

  return 0;
}
