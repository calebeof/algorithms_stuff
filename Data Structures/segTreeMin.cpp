vector<int> arr, segTree;

const int INF = int(1e9);

int getMin(int node, int l, int r, int qL, int qR){
    if(l>=qL and r<=qR)
        return segTree[node];

    if(l>qR or r<qL)
        return INF;

    int mid = (l+r)/2;

    return min(getMin(2*node + 1, l, mid, qL, qR),
        getMin(2*node + 2, mid+1, r, qL, qR));
}

void update(int node, int l, int r, int v){
    if(node<l or node>r)
        return;
    
    if(l==r){
        segTree[node] = v;
        return;
    }

    int mid = (l+r)/2;

    update(2*node + 1, l, mid, v);
    update(2*node + 2, mid+1, r, v);

    segTree[node] = min(segTree[2*node + 1],
        segTree[2*node + 2]);
}

void build(int node, int l, int r){
    if(l>r)
        return;

    if(l==r){
        segTree[node] = arr[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*node + 1, l, mid);
    build(2*node + 2, mid+1, r);

    segTree[node] = min(segTree[2*node + 1],
        segTree[2*node + 2]);
}

void util(int n){
    arr.resize(n);
    segTree.resize(5*n);

    build(0, 0, n-1);
}