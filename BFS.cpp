#include <bits/stdc++.h>
using namespace std;

#define INF 10010

int mark[INF] = {}, operacoes; 

int BFS (int origem, int destino){ // a BFS apenas usará o vértice de origem e o de destino
  
  queue <int> fila; 

  int aux;
  
  mark[origem] = 1;
  fila.push(origem);
  
  while(!fila.empty()){ 
    aux = fila.front(); 
    fila.pop(); 
    
    if(mark[aux+1] == 0){ 
      mark[aux+1] = mark[aux]+1;
      fila.push(aux+1); 
      
      if(aux+1 == destino)
        return operacoes = mark[aux+1];
  }
  }
  
  return 0;
  }

int main (){
  
  int origem, destino;
  
  cin >> origem >> destino;
  
  cout << BFS(origem, destino)-1 << endl; 
  
  memset(mark, 0, sizeof mark); 
  
  return 0;
}
