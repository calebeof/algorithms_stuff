#include <bits/stdc++.h>

using namespace std;

int getSum(vector<int> &BITree, int indice){
  int sum = 0;
  indice = indice + 1;
  while(indice>0){
    sum+=BITree[indice];
    indice-= indice&(-indice);
  }
  return sum;
}
int getSumRange(vector<int>&BITree, int from, int to){
  return getSum(BITree, to)-getSum(BITree, from-1);
}
void updateBIT(vector<int> &BITree, int n, int indice, int valor){
  indice = indice + 1;
  while(indice<=n){
    BITree[indice]+=valor;
    indice+= indice & (-indice);
  }
  //for(int i=0; i<BITree.size(); i++)
    //cout << BITree[i] << " ";
  //cout << endl;
}
void constructBIT(int arr[], int n, vector<int> &BITree){
  for(int i=0; i<=n; i++)
    BITree.push_back(0);
  
  for(int i=0; i<n; i++){
    updateBIT(BITree, n, i, arr[i]);
  }
}

int main() {
  int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 12;
  vector<int> BITree;
  constructBIT(arr, n, BITree);
  cout << getSum(BITree, 5) << endl;
  cout << getSumRange(BITree, 3, 5) << endl;
  updateBIT(BITree, n, 5, 10);
  cout << getSumRange(BITree, 3, 5) << endl;
  return 0;
}
