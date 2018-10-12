#include <bits/stdc++.h>

using namespace std;

//SUBSET SUM IN LINEAR SPACE

bool coin_change(vector<int>&moedas, int troco){
  vector<bool>subset(troco+1, 0);
  subset[0] = true;
  for(int i=0; i<moedas.size(); i++){
    for(int j=troco; j>=moedas[i]; j--){
      subset[j] = max(subset[j], subset[j-moedas[i]]);
    }
  }
  /*for(int i=0; i<subset.size();i++)
    cout << subset[i] << endl;*/
  return subset[troco];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int troco, n;
  vector<int> moedas;
  cin >> troco >> n;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    moedas.push_back(a);
  }
  if(coin_change(moedas, troco))
    cout << "S" << endl;
  else
    cout << "N" << endl;
  return 0;
}
