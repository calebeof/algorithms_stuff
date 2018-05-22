//**LONGEST INCREASING SUBSEQUENCE**// 

#include <bits/stdc++.h>

using namespace std;

vector<int> l;//guarda o maior tamanho de subsequência encontrado até então

int lis(vector<int> &num){
  //verifica o tamanho da subsequência crescente máxima
  int tam=0;
  for(int i=1; i<l.size(); i++){
    for(int j=0; j<i; j++){
      if(num[i]>=num[j])
        l[i]=max(l[i],l[j]+1);//evita que o tamanho da subsequência salvo seja menor do que um anteriormente encontrado
    }
  }
  for(int i=0; i<l.size(); i++)
    if(l[i]>tam)
      tam=l[i];
  
  return tam;
}
void maior_sub(int tam, vector<int> &num){ 
  //imprime a subsequência maxima contígua

  int i;
  vector<int>sub;
  for(i=l.size()-1; i>=0; i--){
    if(l[i]==tam)
    break;
  }
  sub.push_back(num[i]);
  
  for(int j=l.size()-1; j>=0; j--){
    if(l[j]==l[i]-1 and num[j]<=num[i]){
      sub.push_back(num[j]);
      i=j;
    }
  }
  
  for(int j=sub.size()-1; j>=0; j--){
    cout<<sub[j]<<" ";
  }
  
  cout<<'\n';
}

int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++)
    l.push_back(1);
    
  vector<int> num;//guarda a sequência original
  
  while(n){
    int a;
    cin>>a;
    num.push_back(a);
    n--;
  }
  
  cout << lis(num) << "\n";
  maior_sub(lis(num), num);
  
  return 0;
}
