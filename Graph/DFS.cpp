#include <bits/stdc++.h>

#define INF 100000

using namespace std;

bool mark [INF];

vector <int> aux;
vector <vector <int> > grafo (INF, aux);

void DFS (int inicio){
    cout << inicio << "\n";

    mark[inicio] = true;
    for (int i=0; i<grafo[inicio].size(); i++){
        int aresta = grafo[inicio][i];
        if (!mark[aresta])
            DFS (aresta);
    }
}

int main () {
    int vertices, arestas;

    cin >> vertices >> arestas;

    while (vertices!=0 && arestas!=0){
        int cont=0;
        for (int i=0; i<arestas; i++){
            int v, a;
            cin >> v >> a;
            grafo [v].push_back(a);
        }
        for (int i=1; i<=vertices; i++){
            if (!mark[i]){
                cont++;
                DFS(i);
            }
        }
    for (int i=1; i<=vertices;i++){
        mark[i]=0;
        grafo[i].clear();
    }
    cin >> vertices >> arestas;
    }
    return 0;
}
