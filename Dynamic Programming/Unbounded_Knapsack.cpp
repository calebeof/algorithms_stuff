#include<bits/stdc++.h>

#define TAM 10100

using namespace std;

int knapsack (int tamanho, vector<int> &seq){
    vector<int> vetor(seq.size()+1, 0);
    for(int i=0; i<seq.size(); i++){
        for(int j=i+1; j<=tamanho; j++){
            vetor[j] = max(vetor[j], seq[i]+vetor[j-i-1]);
        }
    }
    return vetor[tamanho];
}

int main () {
    int n;
    vector <int> seq;

    while (cin >> n){
        for(int i=0; i<5; i++){
            int a;
            cin >> a;
            seq.push_back(a);
        }
        cout << knapsack(n, seq) << "\n";
        seq.clear();
    }
    return 0;
}

