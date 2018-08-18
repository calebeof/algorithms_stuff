#include <bits/stdc++.h>

using namespace std;

int expmod(int a, int b, int n) {
  if(b == 0)
    return 1;
  else {
    long long res = expmod(a, b/2, n);
    res = (res*res) % n;
    if(b%2 == 1)
      res = (res*a) % n;
    return (int) res;
  }
}

int main () {
	int a, b, n;
  //a^b % n
	while(cin >> a >> b >> n){
		cout << expmod(a, b, n) << "\n";
	}
	return 0;
}
