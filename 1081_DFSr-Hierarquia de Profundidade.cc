#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int adj[21][21],conta,pre[25];
void pathR(int s, int v,string msg);

void grafoDfs(int v){
    string t = "  ";
    conta=0;
    for(int i=0;i<v;i++){ //Percorre todos os vertices
            if(pre[i]==-1){ //Se o vertice no pre for igual a - 1 chama a função pathR
                    pathR(i,v,t);
                    cout<<endl; //Equilave a um printf "\n"
            }
    }
    return;

}

void pathR(int s, int v,string msg){ //S = Vertice a ser visitado, V = numero de vertices, msg = String que ira printar o visitado e o outro vetor adjacente a ele
    pre[s]=conta++; //Adiciona visitado no pre
    for(int i=0;i<v;i++){ //percorre o numero de vertices
        if(adj[s][i]==1){ //Se houver alguma adjacencia entre o vertice a ser visitado e outro vertice
             cout<<msg<<s<<"-"<<i; //imprime a mensagem do vertice visitado e seu adjacente
              if(pre[i]==-1){   //se o vertice adjacente NAO foi visitado
                printf(" pathR(G,%d)\n",i); //IMPRIME o Vertice adjacente
                msg.insert(0,"  "); //isere a partir da posição 0 "  " na string
                pathR(i,v,msg); //Chama a função novamente
                msg.erase(0,2); //Apaga o espaço " " da string msg
              }
              else cout<<endl; //Equivale a um printf"\n printa vazio "
        }
    }
}

void init(int v){ //Inicializa a matriz de adjacencia e o vetor de pre em 0
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)adj[i][j]=0;
        pre[i]=0;
    }
}

int main(){
    int v, e,s,t; //Declarando variaveis
    int n; //Numero de casos
    cin>>n; //Lendo numero de casos
    for(int j=1;j<=n;j++){ //Enquanto numero de casos não for zero
        cin>>v>>e; //Le quantidade de vertices e Arestas
        init(v);  //Inicializa a matriz de adjancencias com 0 e vetor de preprocessado com 0
        for(int i=0;i<e;i++){
            cin>>s>>t; //lendo as arestas
            adj[s][t]=1; //preenchendo a matriz
            pre[s]=-1;pre[t]=-1; //adicionando -1 nos vertices das arestas pre processadas
        }
        cout<<"Caso "<<j<<":"<<endl; //Imprimindo qual caso
        grafoDfs(v); //chamando a função DFS
    }
    return 0;
}
