#include <bits/stdc++.h>

#define INF 1000000
using namespace std;

int sum (vector<int> v){
    int e = -INF;
    int d = -INF;
    int aux = 0;
    for(int i=v.size()/2 - 1; i>=0; i--){
        aux+=v[i];
        e = max(e, aux);
    }
    aux = 0;
    for(int i=v.size()/2; i<v.size(); i++){
        aux+=v[i];
        d = max(d, aux);
    }
    return e+d;
}
int subs(vector<int> v){
    if(v.size()==1)
        return v[0];
    vector<int> esq(v.begin(), v.begin()+v.size()/2);
    vector<int> dir(v.begin()+v.size()/2, v.end());
    int a = subs(esq), b = subs(dir), c = sum(v);
    return max(a,max(b, c));
}

int main () {
    int n;
    cin >> n;
    vector<int> vetor(n);
    for(int i=0; i<n; i++)
        cin >> vetor[i];
    cout << subs(vetor) << endl;
    return 0;
}
