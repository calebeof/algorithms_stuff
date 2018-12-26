#include <bits/stdc++.h>

#define vvii vector<vector<pair<int, int> > > 
#define vvi vector<vector<int> >
#define vi vector<int> 
#define pb push_back
#define mp make_pair
#define INF 1000000

using namespace std;

int BellmanFord(vvii &graph, int begin, int end, int vertices,int edges){
  vi dist(vertices, INF);
  dist[begin] = 0;
  for(int i=0; i<vertices-1; i++)
    for(int k=0; k<vertices; k++)
      for(int j=0; j<graph[k].size(); j++){
        int first = k;
        int second = graph[k][j].first;
        int weight = graph[k][j].second;
        dist[second] = min(dist[second], dist[first]+weight);
      }
  return dist[end];
}

int main() {
  int vertices, edges;
  cin >> vertices >> edges;
  vvii graph(vertices+1);
  for(int i=0; i<edges; i++){
    int a, b, c;
    cin >> a >> b >> c;
    //a--, b--; //if indexed by 1
    graph[a].pb(mp(b,c));
  }
  cout << BellmanFord(graph, 0, 2, vertices, edges) << endl;
  return 0;
}
