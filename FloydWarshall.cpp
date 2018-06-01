#include <iostream>
 
#define TAM 110
#define INF 999999
 
using namespace std;
 
int grafo[TAM][TAM];
 
void floydWarshall(int vertices, int dist[][TAM]){
  for (int i=1; i<=vertices; i++)
    for (int j=1; j<=vertices; j++)
       dist[i][j] = grafo[i][j];
   for (int k = 1; k <= r; k++)
     for (int i = 1; i <= vertices; i++)
       for (int j = 1; j <= vertices; j++){
           if (dist[i][k] + dist[k][j] < dist[i][j])
             dist[i][j] = dist[i][k] + dist[k][j];
       }
  /*for (int i=1; i<=vertices; i++)
    for (int j=1; j<=vertices; j++)
      printf("%d -> %d = %d\n", i, j, dist[i][j]);
  */
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
    int dist [TAM][TAM];
    floydWarshall(vertices, dist);
    for (int i=0; i<consultas; i++){
      int from, to;
      cin >> from >> to;
      if (dist[from][to]!=INF)
        printf("%d\n", dist[from][to]);
      else
        printf("-1\n");
    }
  }
  return 0;
}
