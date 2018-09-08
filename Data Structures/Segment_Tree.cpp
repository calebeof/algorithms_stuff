#include <bits/stdc++.h>

using namespace std;

void updateUtil(vector<int>&SegmentTree, int esquerda, int direita, int indice, int diferenca, int indice_seg){
  if(indice<esquerda or indice>direita)
    return;
  SegmentTree[indice_seg]+=diferenca;
  if(esquerda!=direita){
    int mid = (esquerda+direita)/2;
    updateUtil(SegmentTree, esquerda, mid, indice, diferenca, 2*(indice_seg)+1);
    updateUtil(SegmentTree, mid+1, direita, indice, diferenca, 2*(indice_seg)+2);
  }
}

void updateValue(int arr[], vector<int>&SegmentTree, int n, int indice, int valor){
  if(indice<0 or indice>n-1)
    return;
  int diferenca = valor - arr[indice];
  updateUtil(SegmentTree, 0, n-1, indice, diferenca, 0);
}

int getSumUtil(vector<int> &SegmentTree, int indice_min, int indice_max, int esquerda, int direita, int indice_atual){
  if(esquerda<=indice_min && direita>=indice_max)
    return SegmentTree[indice_atual];
  if(indice_max<esquerda or indice_min > direita)
    return 0;
  int mid = (indice_max+indice_min)/2;
  return getSumUtil(SegmentTree, indice_min, mid, esquerda, direita, 2*(indice_atual)+1) + getSumUtil(SegmentTree, mid+1, indice_max, esquerda, direita, 2*(indice_atual)+2);
}

int getSum(vector<int> &SegmentTree, int n, int esquerda, int direita){
  if(esquerda<0 or direita>n-1 or direita<esquerda)
    return -1;
  return getSumUtil(SegmentTree, 0, n-1, esquerda, direita, 0);
}

int constructSTUtil(int arr[], int esquerda, int direita, vector<int> &SegmentTree, int indice_seg){
  if(esquerda==direita){
    SegmentTree[indice_seg] = arr[esquerda];
    return arr[esquerda];
  }
  int mid = (esquerda+direita)/2;
  SegmentTree[indice_seg] = constructSTUtil(arr, esquerda, mid, SegmentTree, (indice_seg*2)+1) + constructSTUtil(arr, mid+1, direita, SegmentTree, (indice_seg*2)+2);
  return SegmentTree[indice_seg];
}

void constructST(vector<int> &SegmentTree, int arr[], int n){
  SegmentTree.resize(5*n);
  constructSTUtil(arr, 0, n-1, SegmentTree, 0);
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11}, n = 6;
  vector<int> SegmentTree;
  constructST(SegmentTree, arr, n);
  cout << getSum(SegmentTree, n, 2, 5) << endl;
  updateValue(arr, SegmentTree, n, 3, 25);
  cout << getSum(SegmentTree, n, 2, 5) << endl;
  return 0;
}
