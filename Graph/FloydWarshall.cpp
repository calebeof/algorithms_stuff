vector<vector<int> > graph;
const int INF = int(1e9);

void floydWarshall(int vertexes){
    
    for(int i=1; i<=vertexes; i++)
        for(int j=1; j<=vertexes; j++)
            graph[i][j] = INF;
    
    for(int i=1; i<=vertexes; i++)
        for(int j=1; j<=vertexes; j++)
            for(int k=1; k<=vertexes; k++)
                graph[i][j] = min(graph[i][j],
                    graph[i][k]+graph[k][j]);
    
}