#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> aux, auxSeg;
vector<vector<int> > matriz;
vector<vector<int> > segTree; 
vector<vector<int> > matrizSegs; 

void build(int y_i, int y_f, int no){
	int ts = segTree[no].size();
	if(y_i == y_f){
		for(int i=0; i<ts; i++)
			segTree[no][i] = matrizSegs[y_i][i];
		return;
	}
	
	int meio = (y_i+y_f)/2;
	build(y_i, meio, 2* no + 1);
	build(meio+1, y_f, 2*no + 2);
	
	for(int i=0; i<ts; i++)
		segTree[no][i] = segTree[2*no + 1][i] + segTree[2*no + 2][i];
}

void buildSegs(int nSeg, int no, int qI, int qF){
	if(qI > qF) return;
	
	if(qI==qF){
		matrizSegs[nSeg][no] = matriz[nSeg][qI];
		return;
	}
	
	
	int meio = (qI+qF)/2;
	
	buildSegs(nSeg, 2*no + 1, qI, meio);
	buildSegs(nSeg, 2*no + 2, meio+1, qF);
	
	matrizSegs[nSeg][no] = matrizSegs[nSeg][2*no + 1] + matrizSegs[nSeg][2*no + 2];
}

int queryAux(int numSeg, int x_i, int x_f, int no, int qI, int qF) {
	if(qI>=x_i and x_f<=qF)
		return segTree[numSeg][no];
	
	if(x_i>qF or x_f<qI) return 0;
	
	int meio = (qI+qF)/2;
	
	return queryAux(numSeg, qI, meio, 2*no + 1, 0, n-1) + queryAux(numSeg, meio+1, qF, 2*no + 2, 0, n-1);
}

int query(int y_i, int y_f, int x_i, int x_f, int no, int qI, int qF){
	if(y_i>qF or y_f<qI) return 0;
	
	if(qI>=y_i and y_f<=qF)
		return queryAux(no, x_i, x_f, 0, 0, n-1);
	
	int meio = (qI+qF)/2;
	
	return query(qI, meio, x_i, x_f, 2*no + 1, qI, qF) + query(meio+1, qF, x_i, x_f, 2*no + 2, qI, qF);
}

/*
4
37 1 -5 9
3 66 19 20
24 69 120 0
18 0 0 0 
*/

int main () {
	cin >> n;
	
	aux.resize(n);
	auxSeg.resize(4*n);
	matriz.resize(n, aux);
	segTree.resize(4*n, auxSeg);
	matrizSegs.resize(4*n, auxSeg);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> matriz[i][j];
	
	for(int i=0; i<n; i++)
		buildSegs(i, 0, 0, n-1);
	
	build(0, n-1, 0);
	
	for(int i=0; i<matrizSegs.size(); i++){
		for(int j=0; j<matrizSegs[i].size(); j++){
			cout << matrizSegs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for(int i=0; i<segTree.size(); i++){
		for(int j=0; j<segTree[i].size(); j++)
			cout << segTree[i][j] << " ";
		cout << endl;
	}
	
	cout << query(0, 3, 0, 3, 0, 0, n-1) << endl;
	cout << query(1, 2, 1, 2,  0, 0, n-1) << endl;
	return 0;
}
