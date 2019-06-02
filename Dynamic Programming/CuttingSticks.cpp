#include<bits/stdc++.h>

using namespace std;

vector<int> vetor;

int cut(int left, int right, vector<vector<int> > &memo){
	//cout << left << " " << right << endl;
	if(memo[left][right]!=INT_MAX)
		return memo[left][right];
	
	if(left+1==right) return memo[left][right] = 0;
	
	for(int i=left+1; i<right; i++)
		memo[left][right] = min(memo[left][right], cut(left, i, memo) + cut(i, right, memo) + (vetor[right]-vetor[left]));
	
	return memo[left][right];
}

int main () {
  ios_base::sync_with_stdio(false);
	int n;
	while(cin >> n && n!=0){
		int t;
		cin >> t;
    
		vetor.resize(t+10);
		vector<int> aux(t+10, INT_MAX);
		vector<vector<int> > memo(t+10, aux);
		
		vetor[0] = 0;
		vetor[t+1] = n;
    
		for(int i=1; i<=t; i++) cin >> vetor[i];
		
		cout <<"The minimum cutting is ";
		cout << cut(0, t+1, memo) << "." << endl;
	}
	
	return 0;
}
