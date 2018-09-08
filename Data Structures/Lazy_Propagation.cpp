#include <bits/stdc++.h>

using namespace std;

void updateRangeUtil(vector<int> &SegmentTree, vector<int> LazyTree, int indice_atual, int indice_min, int indice_max, int esquerda, int direita, int valor){
  if(LazyTree[indice_atual]!=0){ //se não atualizei
    SegmentTree[indice_atual]+=(indice_max-indice_min+1)*LazyTree[indice_atual];
    if(indice_min!=indice_max){ //adiciono se não for uma folha
      LazyTree[(indice_atual*2) + 1]+= LazyTree[indice_atual];
      LazyTree[(indice_atual*2) + 2]+= LazyTree[indice_atual];
    }
    LazyTree[indice_atual] = 0; //atualizei
  }
  if(indice_min>indice_max or indice_min>direita or indice_max<esquerda)
    return;
  if(indice_min>=esquerda && indice_max<=direita)//Se estamos totalmente no intervalo
  {
    SegmentTree[indice_atual]+=(indice_max-indice_min+1)*valor;
    if(indice_min!=indice_max){
      LazyTree[(indice_atual*2)+1]+=valor;
      LazyTree[(indice_atual*2)+2]+=valor;
    }
    return;
  }
  int mid = (indice_min+indice_max)/2;
  updateRangeUtil(SegmentTree, LazyTree, 2*(indice_atual) + 1, indice_min, mid, esquerda, direita, valor);
  updateRangeUtil(SegmentTree, LazyTree, 2*(indice_atual) + 2, mid+1, indice_max, esquerda, direita, valor);
  SegmentTree[indice_atual] = SegmentTree[(2*indice_atual)+1] + SegmentTree[(2*indice_atual)+2];
}

void updateRange(vector<int> &SegmentTree, vector<int> &LazyTree, int n, int esquerda, int direita, int valor){
  updateRangeUtil(SegmentTree, LazyTree, 0, 0, n-1, esquerda, direita, valor);
}
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

int getSumUtil(vector<int> &SegmentTree, vector<int> &LazyTree, int indice_min, int indice_max, int esquerda, int direita, int indice_atual){

  if(LazyTree[indice_atual]!=0){ //se ainda não atualizei
    SegmentTree[indice_atual]+=(indice_max-indice_min-1)*LazyTree[indice_atual];
    if(indice_max!=indice_min){
      LazyTree[(2*indice_atual)+1]+=LazyTree[indice_atual];
      LazyTree[(2*indice_atual)+2]+=LazyTree[indice_atual];
    }
    LazyTree[indice_atual] = 0; //atualizei
  }
  if(esquerda<=indice_min && direita>=indice_max)
    return SegmentTree[indice_atual];
  if(indice_max<esquerda or indice_min > direita)
    return 0;
  int mid = (indice_max+indice_min)/2;
  return getSumUtil(SegmentTree, LazyTree,indice_min, mid, esquerda, direita, 2*(indice_atual)+1) + getSumUtil(SegmentTree, LazyTree, mid+1, indice_max, esquerda, direita, 2*(indice_atual)+2);
}

int getSum(vector<int> &SegmentTree, vector<int> &LazyTree, int n, int esquerda, int direita){
  if(esquerda<0 or direita>n-1 or direita<esquerda)
    return -1;
  return getSumUtil(SegmentTree, LazyTree, 0, n-1, esquerda, direita, 0);
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

void constructST(vector<int> &SegmentTree, vector<int> &LazyTree, int arr[], int n){
  SegmentTree.resize(5*n);
  LazyTree.resize(5*n, 0);
  constructSTUtil(arr, 0, n-1, SegmentTree, 0);
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11}, n = 6;
  vector<int> SegmentTree, LazyTree;
  constructST(SegmentTree, LazyTree, arr, n);
  //cout << "oi" << endl;
  cout << getSum(SegmentTree, LazyTree, n, 2, 5) << endl;
  updateValue(arr, SegmentTree, n, 3, 25);
  cout << getSum(SegmentTree, LazyTree, n, 2, 5) << endl;
  updateRange(SegmentTree, LazyTree, n, 2, 5, 10);
  cout << getSum(SegmentTree, LazyTree, n, 2, 5) << endl;
  return 0;
}
