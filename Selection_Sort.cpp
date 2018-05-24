#include <bits/stdc++.h>

using namespace std;

void SelectionSort(vector<int> &seq){
  for (int i=0; i<seq.size()-1; i++){
    int menor = seq[i];
    int menor_indice = i;
    for (int j=i+1; j<seq.size(); j++){
      if (seq[j]<menor){
        menor = seq[j];
        menor_indice = j;
      }
    }
    swap(seq[i], seq[menor_indice]);
  }
}

int main() {
  int n;
  vector<int> seq;
  cin >> n;
  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    seq.push_back(a);
  }

  SelectionSort(seq);
  
  for (int i=0; i<n; i++)
    printf("%d ", seq[i]);
  printf("\n");
  
  return 0;
}
