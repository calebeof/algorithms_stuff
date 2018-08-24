#include <bits/stdc++.h>
#define INF 1000000 
using namespace std;

int DIJKSTRA (int origem, int destino, vector<vector<pair<int, int> > > &adj);

int main()
{
	int v, a, origem, destino;
	cin >> v >> a; // recebe a quantidade de vértices e arestas do grafo
	vector<pair<int, int> > aux; // como as arestas tem peso, precisamos de um vector de pares pra poder armazenar os vértices vizinhos junto com os pesos
	vector<vector<pair<int, int> > > adj(v, aux); // nosso grafo é um vector em que cada índice contém outro vector que tem os vizinhos do vértice desse índice junto com os respectivos pesos

	for (int i = 0; i < a; i++) // recebe o grafo
	{
		int from, to, peso;
		cin >> from >> to >> peso;
		to--; from--; 
		adj[to].push_back(make_pair(from, peso));
		adj[from].push_back(make_pair(to, peso)); 
	}
	cin >> origem >> destino; 
	origem--; destino--;

	int temp = DIJKSTRA(origem, destino, adj);
	if (temp==INF)
		cout << "Nao existe um caminho minimo.\n";
	else
		cout << "Caminho minimo = " << temp << '\n';

	return 0;
}
int DIJKSTRA (int origem, int destino, vector<vector<pair<int, int> > > &adj)
{
	vector<int>dist(adj.size(), INF); 
	dist[origem] = 0; 
	set<pair<int, int> > S; // set mantém a ordem que usamos pra percorrer os vizinhos dos vértices
	S.insert(make_pair(0, origem)); // começa com o vértice de origem
	while(!S.empty())
	{
		pair<int, int> f = *S.begin();
		int d = f.first, v = f.second; // pega a distância desse vértice e o próprio vértice
		S.erase(S.begin()); // tira esse vértice do set
		for (int i = 0; i < adj[v].size(); i++) // percorre os vizinhos do vértice
		{
			if (dist[adj[v][i].first] > d + adj[v][i].second) 
			{
				dist[adj[v][i].first] = d + adj[v][i].second; 
				S.insert(make_pair(dist[adj[v][i].first], adj[v][i].first)); //
			}
		}
	}
	return dist[destino]; 
}
