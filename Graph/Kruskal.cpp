#include<bits/stdc++.h>
#define TAM 100
using namespace std;

int pais[TAM],niveis[TAM];
typedef struct{
    int peso,v1,v2;
}Aresta;

bool comp(Aresta a1,Aresta a2){
    return a1.peso<a2.peso;
}
int find(int v){
    if(pais[v]!=v)
        pais[v]=find(pais[v]);
    return pais[v];
}
void uniao(int v1,int v2){
    //Função que une dois conjuntos. Para isso,
    //Verificamos o nível de cada um dos vértices,
    //O que tem o maior nível se torna pai do de
    //menor nível.
    if(niveis[v1]>niveis[v2])
        pais[v2]=v1;
    else{
        pais[v1]=v2;
        //Se eles ambos os vértices possuírem o mesmo nível,
        //Escolhemos um para se tornar pai do outro e aumentamos o nível
        //do escolhido.
        if(niveis[v1]==niveis[v2])
            niveis[v2]++;

    }
}
bool union_find(int v1,int v2){
    int pai1=find(v1);
    int pai2=find(v2);
    if(pai1==pai2)
        return true;
    //Se chegarmos nessa linha, os vértices não pertecem ao mesmo conjunto
    //e não temos um ciclo. Então "unimos" os conjuntos e retornamos falso.
    uniao(pai1,pai2);
    return false;
}
int kruskal(Aresta *lista_de_arestas,int tam){
    //A função kruskal retornará o somatório
    //do peso das arestas que fazem parte das
    //árvore geradora mínima.
    int soma=0;
    for(int i=0;i<tam;i++){
        if(!union_find(lista_de_arestas[i].v1,lista_de_arestas[i].v2)){
            soma+=lista_de_arestas[i].peso;
        }
    }
    return soma;
}
int main(){
    int v,a;
    Aresta lista_de_arestas[TAM];
    cin>>v>>a;
    for(int i=1;i<=v;i++){
        pais[i]=i;
        niveis[i]=0;
    }
    for(int i=0;i<a;i++){
        //Lemos cada uma das arestas.
        //Estamos considerando que primeiramente é informado
        //o peso da aresta.
        cin>>lista_de_arestas[i].peso>>lista_de_arestas[i].v1>>lista_de_arestas[i].v2;
    }
    //Ordenamos a lista de arestas da que tem o menor peso até a que tem o maior peso.
    sort(lista_de_arestas,lista_de_arestas+a,comp);
    //Imprimimos o somatório do peso das arestas
    //que compõem a árvore geradora mínima.
    cout<<kruskal(lista_de_arestas,a)<<"\n";
}
