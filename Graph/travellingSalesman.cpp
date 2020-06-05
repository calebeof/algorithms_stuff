const int TAM = 20, INF = int(1e9);
int dp[TAM][1<<TAM]; //1 << TAM means all of the vertices that we will have to visit

vector<vector<pair<int, int> > > graph;
int n;

int tsp(int vertex, int bitmask){

    if(__bultin_popcount(bitmask)==n) //if all are visited
        return graph[vertex][0].second; // return distance
    
    if(dp[vertex][bitmask]!=-1)
        return dp[vertex][bitmask];
    
    int dist = INF;

    for(int i=0; i<n; i++){
        if(!(bitmask & (1<<i))) // if i not visited (not in the mask)
            dist = min(dist, graph[vertex][i].second + tsp(i, bitmask | (1<<i));
            //sum weight of the edge and active i-th bit in the mask
    }

    return dp[vertex][bitmask] = dist;
}

void util(int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<(1<<n); j++)
            dp[i][j] = -1;
}