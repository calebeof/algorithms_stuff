#include <bits/stdc++.h>

using namespace std;

#define TAM 100000

void crivo (bool *matrix, vector<int> &primos){
  for (int i=2; i<TAM; i++){
    if (!matrix[i]){
      for (int j=i+i; j<TAM; j+=i)
          matrix[j] = true;
      primos.push_back(i);
    }
  }
}

int main() {
  bool matrix[TAM]={};
  vector <int> primos;
  
  crivo (matrix, primos);
  
  for (int i=0; i<primos.size(); i++)
    cout << primos[i] << " ";
  cout << "\n";
  
  return 0;
}
