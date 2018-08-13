#include <iostream>
 
#define TAM 110
#define INF 999999
 
using namespace std;
 
int grafo[TAM][TAM];
 
void floydWarshall(int vertices){
   for (int k = 1; k <= vertices; k++)
     for (int i = 1; i <= vertices; i++)
       for (int j = 1; j <= vertices; j++){
           if (grafo[i][k] + grafo[k][j] < grafo[i][j])
             grafo[i][j] = grafo[i][k] + grafo[k][j];
       }
}
 
int main() {
  int vertices, arestas;
  while (cin >> vertices >> arestas){
    for (int i=1; i<=vertices; i++)
      for (int j=1; j<=vertices; j++)
        grafo[i][j] = INF;
    for (int i=0; i<arestas; i++){
      int from, to, weight;
      cin >> from >> to >> weight;
      grafo[from][to] = weight;
      grafo[to][from] = weight;
    }
    int consultas;
    cin >> consultas;
    floydWarshall(vertices);
    for (int i=0; i<consultas; i++){
      int from, to;
      cin >> from >> to;
      if (grafo[from][to]!=INF)
        printf("%d\n", grafo[from][to]);
      else
        printf("-1\n");
    }
  }
  return 0;
}
