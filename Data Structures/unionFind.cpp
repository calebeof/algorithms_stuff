vector<int> parent, level;

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

void util(int vertexes){
    parent.resize(vertexes);
    level.resize(vertexes);

    for(int i=0; i<vertexes; i++)
        parent[i] = i, level[i] = 1;
}