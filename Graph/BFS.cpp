#include <bits/stdc++.h>

#define TAM 100000

using namespace std;

bool mark [TAM];

vector<vector<int> > grafo(TAM);

void BFS(int orig){
  mark[orig] = true;
  queue<int> fila;
  fila.push(orig);
  cout << "origem: " <<orig << "\n";
  while (!fila.empty()){
    int aux;
    aux = fila.front();
    fila.pop();
    for (int i=0; i<grafo[aux].size(); i++)
      if(!mark[grafo[aux][i]]){
        mark[grafo[aux][i]] = true;
        cout << grafo[aux][i] << "\n";
        fila.push(grafo[aux][i]);
      }
  }
}

int main() {
  int vertices, arestas;

  while(cin >> vertices >> arestas && arestas!=0 && vertices!=0){
    for (int i=0; i<arestas; i++){
      int from, to;
      cin >> from >> to;
      grafo[from].push_back(to);
    }
    for(int i=0;i<vertices; i++)
      if(!mark[i])
        BFS(i);
    }
  return 0;
}
