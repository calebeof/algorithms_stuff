#include <bits/stdc++.h>

using namespace std;
vector<int> vetor, segtree;

int getSum(int no, int qI, int qF, int left, int right){
	if(qI<=left and right<=qF)
		return segtree[no];
	
	if(left>qF or right<qI)
		return 0;
	
	int meio = (left+right)/2;
	
	return getSum(2*no + 1, qI, meio, left, right) + getSum(2*no + 2 , meio+1, qF, left, right);
}

void update(int no, int qI, int qF, int v){
	if(no<qI or no>qF)
		return;
	
	if(qI==qF){
		segTree[indice]+=v;
		return;
	}
	int meio = (qI+qF)/2;
	
	update(2*no + 1, qI, meio, v);
	update(2*no + 2, meio+1, qF, v);
	
	segtree[no] = segtree[2*no + 1] + segtree[2*no + 2];
		
	
}

void build(int no, int qI, int qF){
	if(qI>qF)
		return;
	if(qI==qF){
		segtree[no] = vetor[qI];
		return;
	}
	int meio = (qI+qF)/2;
	build(2*no + 1, qI, meio);
	build(2*no + 2, meio+1, qF);
	
	segtree[no] = segtree[2*no + 1] + segtree[2*no + 2];
}

int main () {
	int n;
	cin >> n;
	vetor.resize(n);
	segtree.resize(n*4);
	
	for(int i=0; i<n; i++) cin >> vetor[i];
	build(0, 0, n-1);
  
	return 0;
}
