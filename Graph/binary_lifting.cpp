int n, l;
vector<vector<int> > graph;
vector<int> tin, tout;
vector<vector<int> > up;
int timer;

void DFS(int vertex, int parent){
    tin[vertex] = ++timer; //counting the time when i entered in the node
    up[vertex][0] = parent; //the parent is the first ancestor of the current node

    for(int i=1; i<=l; i++)
        up[vertex][i] = up[up[vertex][i-1]][i-1]; //catching the ancestors 2^i above
    
    // up[vertex][i] = 2^i ancestor above the current vertex

    for(int nxt : graph[vertex])
        if(nxt!=parent)
            DFS(nxt, vertex); //visiting the sons of the node

    tout[vertex] = ++timer; //counting the time when i exited the node
}

bool is_ancestor(int u, int v){
    //If the DFS found u first and has gone out later then v,
    //then, u is an ancestor of v.
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int LCA(int u, int v){
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;

    for(int i=l; i>=0; i--) //loop (jump above u) until you find an ancestor of v 
        if(!is_ancestor(up[u][i], v))
            u = up[u][i];

    //The first ancestor of the node u, the LCA, will be up[u][0].
    //If the node is the root, it will be itself.
    return up[u][0]; 
}

void preprocess(int root){
    tin.resize(n);
    tout.resize(n);
    timer = 0; //initialize timer
    l = ceil(log2(n)); //height of the tree
    up.assign(n, vector<int> (l+1)); //every node will have an up and will have at most l ancestors

    DFS(root, root);
}