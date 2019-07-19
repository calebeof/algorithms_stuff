#include <bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int> 
#define vvii vector<vector<pii> >  
#define pb push_back
#define mp make_pair

using namespace std;

int vertices, arestas;
int origem, destino; 

struct Edge{
	int fluxo, capacidade; 
	
	Edge(int a, int b){
		fluxo = a;
		capacidade = b;
	}
};

vector<Edge> aux;
vector<vector<Edge > > grafo; 
vector<int> papai;

/*vector<vector<Edge> > build(vector<vector<Edge > > &atual){
	vector<vector<Edge> > residual;
	residual.resize(atual.size(), aux);
	for(int i=0; i<atual.size(); i++){
		for(int j=0; j<atual[i].size(); j++){
			if(atual[i][j].capacidade > atual[i][j].fluxo)
				residual[i].pb(Edge(j, atual[i][j].fluxo, atual[i][j].fluxo));
		}
	}
}*/

int BFS(int s, int t){
  vector<bool> mark(vertices, false);  
  mark[s] = true;
  queue<int> fila;
  fila.push(s);
  
  int menor = INT_MAX; 
  
  for(int i=0; i<vertices; i++)
	papai[i] = i;
	
  while (!fila.empty()){
    int vertice;
    vertice = fila.front();
    fila.pop();
    if(vertice == t) return menor;
    
    for (int i=0; i<grafo[vertice].size(); i++){
    	Edge edge = grafo[vertice][i];
    	if(!mark[i] and edge.capacidade-edge.fluxo>0){
    		mark[i] = true;
    		papai[i] = vertice;
    		
    		fila.push(i);
    		menor = min(menor, edge.capacidade-edge.fluxo);
		}
  	}
  }
  return INT_MAX; 
}

void saturar(int valor, int s, int t){
	int atual = t;
	while(atual!=s){
		grafo[atual][papai[atual]].capacidade+=valor;
		grafo[papai[atual]][atual].fluxo+=valor; 
		atual = papai[atual];
	}
}
int edmondKarp(int s, int t){
	
	while(true){
		int res = BFS(origem, destino);
		if(res==INT_MAX) break;
		
		//cout << res << endl;
		
		saturar(res, origem, destino);
	}
	
	int flux = 0;
	for(int i=0; i<vertices; i++)
		flux+=grafo[i][t].fluxo;
	
	return flux;
}

int main () {
	
	ios_base::sync_with_stdio(false);
	
	int k = 1;
	while(cin >> vertices && vertices){
		
		grafo.clear();
		cin >> origem >> destino >> arestas;
		
		origem--, destino--;
		
		for(int i=0; i<vertices; i++){
			vector<Edge> opa;
			for(int j=0; j<vertices; j++)
				opa.pb(Edge(0, 0));
			grafo.pb(opa);
		}
			
		papai.resize(vertices);
		
		for(int i=0; i<arestas; i++){
			int a, b, c; 
			cin >> a >> b >> c;
			a--, b--;
			int capacidade1 = grafo[a][b].capacidade, capacidade2 = grafo[b][a].capacidade;
			grafo[a][b] = Edge(0, c+capacidade1);
			grafo[b][a] = Edge(0, c+capacidade1);
			//cout << c + capacidade1 << endl;
		}
		
		cout << "Network " << k++ << endl;
		cout << "The bandwidth is " << edmondKarp(origem, destino) << "." <<  endl << endl;
	}
	
	return 0;
}
