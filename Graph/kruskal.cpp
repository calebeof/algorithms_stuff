vector<int> parent, level;

typedef struct{
    int weight, v1, v2;
} Edge;

bool comp(Edge a, Edge b){
    return a.weight<b.weight;
}

int find(int v){
    if(parent[v]!=v)
        parent[v] = find(parent[v]);
    return parent[v];
}

void Union(int a, int b){
    a = find(a); 
    b = find(b);

    if(level[a]>level[b])
        parent[b] = a;
    else {
        parent[a] = b;
        if(level[a]==level[b])
            level[b]++;
    }
}

bool unionFind(int a, int b){
    a = find(a);
    b = find(b);
    
    return a==b;
}

int kruskal(vector<Edge> edges){
    sort(edges.begin(), edges.end(), comp);

    int sum = 0;

    for(Edge edge : edges){
        int v1 = edge.v1;
        int v2 = edge.v2;
        int w = edge.weight;

        if(!unionFind(v1, v2)){
            sum+=w;
            Union(v1, v2);
        }
    }

    return sum;
}

void util(int n){
    parent.resize(n);
    level.resize(n);
    for(int i=0; i<n; i++)
        parent[i] = i, level[i] = 1;
}