vector<int> arr, segTree, lazy;

void update(int node, int l, int r, int Ql, int qR, int val){

    if(lazy[node]){
        if(l!=r){
            lazy[2*node + 1]+=lazy[node];
            lazy[2*node + 2]+=lazy[node];
        }
        segTree[node]+=(r-l+1)*lazy[node];
        lazy[node] = 0;
    }

    if(l>r or r<qL or l>qR)
        return;

    if(l>=qL and r<=qR){
        segTree[node]+=(r-l+1)*val;
        if(l!=r){
            lazy[2*node + 1]+=val;
            lazy[2*node + 2]+=val;    
        }
        return;
    }

    int mid = (l+r)/2;

    update(2*node + 1, l, mid, qL, qR, val);
    update(2*node + 2, mid+1, r, qL, qR, val);

    segTree[node] = segTree[2*node + 1] + segTree[2*node + 2];
}

int query(int node, int l, int r, int qL, int qR){
    
    if(lazy[node]){
        if(l!=r){
            lazy[2*node + 1] += lazy[node];
            lazy[2*node + 2] += lazy[node];
        }
        segTree[node]+=(r-l+1)*lazy[node];
        lazy[node] = 0;
    }

    if(l>r or r<qL or l>qR)
        return 0;
    
    if(l>=qL and r<=qR)
        return seg[node];
    
    int mid = (l+r)/2;

    return query(2*node + 1, l, mid, qL, qR)+
        query(2*node + 2, mid+1, qL, qR);
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
	
	segTree[node] = segTree[2*node + 1] + segTree[2*node + 2];
}

void util(int n){
    arr.resize(n);
    segTree.resize(5*n);
    lazy.resize(5*n);

    build(0, 0, n-1);
}