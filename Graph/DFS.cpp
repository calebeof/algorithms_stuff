vector<vector<int> > graph;
vector<bool> mark(graph.size(), false);

void DFS(int vertex){
    mark[vertex] = 1;

    for(int i : graph[vertex])
        if(!mark[i])
            DFS(i);
}