#include <bits/stdc++.h>

using namespace std;

int vertices;

vector < vector <int> > adjacencias;
vector < int > marcacao;

vector < vector <int> > adjacencias_transposto;
vector < bool > marcacao_transposto;

vector < int > ordenacao;  

map < int , vector < int > > comp_conex;

void dfs (int origem, int k){

    marcacao[origem] = k;

    cout << origem << " ";

    comp_conex[k].push_back(origem);

    for(int i = 0 ; i < adjacencias[origem].size() ; i++){ 
        if( marcacao[ adjacencias[origem][i] ] == 0)                   
        dfs( adjacencias[origem][i] , k );    
    }
}

void dfs_transposto (int origem){

    marcacao_transposto[origem] = true;

    for(int i = 0 ; i < adjacencias_transposto[origem].size() ; i++){  
        if( !marcacao_transposto[ adjacencias_transposto[origem][i] ] ) 
            dfs_transposto( adjacencias_transposto[origem][i] );       
    }

    ordenacao.push_back(origem);

}

void kosaraju (){

    for(int i = 0 ; i < vertices ; i++){    
        if( !marcacao_transposto[i] )     
            dfs_transposto(i);
    }

    int k = 1;
    for(int i = vertices-1 ; i > -1 ; i--){
        if(marcacao[ordenacao[i]] == 0){
            //[PARA IMPRIMIR]
            //cout << "Componentes conexos : ";
            dfs(ordenacao[i],k++);
            //[PARA IMPRIMIR]
            //cout << "\n";
        }

    }
}
int main (){
    int qtde;

    cin >> vertices >> qtde;

    vector <int> aux;
    for(int i = 0 ; i < vertices ; i++){
        adjacencias.push_back(aux);
        adjacencias_transposto.push_back(aux);
        marcacao.push_back(0);
        marcacao_transposto.push_back(false);
    }

    int v1,v2; 
    for(int i = 0 ; i < qtde ; i++){
        cin >> v1 >> v2;
        adjacencias[v1].push_back(v2);
        adjacencias_transposto[v2].push_back(v1); 
    }

    kosaraju();

    for(int i = 0 ; i < vertices ; i++){
        cout << "Vertice " << i << " componente: " << marcacao[i] << "\n";
    }


    for( map < int, vector < int > >::iterator it = comp_conex.begin() ; it != comp_conex.end() ; it++){
        cout << "Componentes conexos: ";
        for(int i = 0 ; i < it->second.size() ; i++){
            cout << it->second[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
