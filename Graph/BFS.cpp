vector<vector<int> > graph;
const int INF = int(1e9);

void BFS(int origin){
    vector<int> dist(graph.size(), INF);
    queue<int> q;
    
    q.push(origin);
    dist[origin] = 0;

    while(!q.empty()){
        int vertex = q.front();
        q.pop();

        for(int i : graph[vertex])
            if(dist[i]>dist[vertex]+1){
                dist[i] = dist[vertex]+1;
                q.push(i);
            }
    }
}