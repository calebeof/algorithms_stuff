#include<bits/stdc++.h>

using namespace std;

vector<int>pais, niveis;

int find(int v){
  if(pais[v]!=v)
    pais[v]=find(pais[v]);
  return pais[v];
}
void uniao(int v1,int v2){
  if(niveis[v1]>niveis[v2])
    pais[v2]=v1;
  else{
    pais[v1]=v2;
    if(niveis[v1]==niveis[v2])
      niveis[v2]++;
  }
}
bool union_find(int v1,int v2){
  int pai1=find(v1);
  int pai2=find(v2);
  if(pai1==pai2)
    return true;
  //uniao(pai1,pai2);
  return false;
}

int main(){
  int v,a,cons;
  int k=0;
  ios_base::sync_with_stdio(false);
  while(cin>> v >> a >> cons){
    if (k!=0)
      printf("\n");
    pais.push_back(0);
    niveis.push_back(0);
    for(int i=1;i<=v;i++){
      pais.push_back(i);
      niveis.push_back(0);
    }
    for(int i=0;i<a;i++){
      int a, b;
      cin >> a >> b;
      uniao(pais[a], pais[b]);
    }
    for (int i=0; i<cons; i++){
      int from, to;
      cin >> from >> to;
      if (union_find(from, to))
        printf("S\n");
      else
        printf("N\n");
    }
    k++;
    niveis.clear();
    pais.clear();
  }
  return 0;
}
