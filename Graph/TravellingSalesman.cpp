#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<pair<int, int> > 
#define vvii vector<vector<pair<int, int> > > 
#define vvid vector<vector<pair<int, double > > >
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF LLONG_MAX
#define TAM 20

using namespace std;

double memo[TAM][1<<TAM]; //1 << TAM means all of the vertices that we will have to visit

double tsp(vvid &graph, int s, int bitmask,int n){
  if(__builtin_popcount(bitmask)==n) //if all are visited
    return graph[s][0].s;
  if(memo[s][bitmask]!=-1) //if already was visited
    return memo[s][bitmask];
  double dist = INF;
  for(int i=0; i<n; i++){
    if(!(bitmask & (1<<i))) //if not visited
      dist = min(dist, graph[s][i].s + tsp(graph, i, bitmask | (1 << i), n)); //send bitmask updated with visited
  }
  return memo[s][bitmask] = dist; //return the value of the distance in that moment
}

void generate_edges(vii &points, vvid &graph, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      double x = points[i].f-points[j].f;
      double y = points[i].s-points[j].s;
      double dist = sqrt((x*x)+(y*y));
      graph[i].pb(mp(j, dist));
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n && n!=0){
    vii points;
    vvid graph(TAM);
    n++;
    for(int i=0; i<n; i++){
      int a, b;
      cin >> a >> b;
      points.pb(mp(a,b));
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<(1<<n); j++){
        memo[i][j] = -1;
      }
    }
    generate_edges(points, graph, n);
    cout << setprecision(2) << fixed<< tsp(graph, 0, 1, n) << endl;
  }
  return 0;
}
