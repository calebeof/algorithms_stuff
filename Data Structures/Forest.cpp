#include <bits/stdc++.h>

#define INF 10000

using namespace std;

int tree[INF], pais[INF]={}, niveis[INF]={};

int recursivo (int indice){
    if (indice/2==0){ 
        niveis[indice] = 0; 
        return 0; 
    }
    pais[indice] = tree[indice/2]; 
    if (niveis[indice/2]){ 
        niveis[indice] = niveis[indice/2]+1; 
    }
    else niveis [indice] = recursivo (indice/2)+1;
    return niveis[indice]; 
}

int main () {

    for (int i=1; i<=10; i++)
        cin >> tree[i];

    cout << "NIVEIS:\n";

    for (int i=1; i<=10; i++){
        cout << recursivo (i) << " ";
    }
    cout << endl;
    cout << "PAIS:\n";
    for (int i=1; i<=10; i++){
        cout << pais[i] << " ";
    }
    cout << endl;

    return 0;
}
