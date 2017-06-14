#include "cache.h"
#include "funcoes.h"

void Show(map<int,int> cache, int principal, int linhas, int palavras){

    int aux=0;
    for(int i=0; i < linhas; i++){
        for(int j=0; j < palavras; j++){
            if(cache[i] >= 0 && cache[i] <= principal){
                cout << i << "  -   "<< cache[i] << "   -   " <<(cache[i]*palavras) + aux%palavras << endl;
            }
            else{
                cout << "x  -   x   -   x" << endl;
            }
            aux++;
        }
    }
    
}
/////////////////////////////////////////////////
void Direto(map<int,int> &cache, int palavras, int linhas, int principal, int x){
    int b = x/palavras;
    int cont=0;
    for (auto it = cache.cbegin(); it != cache.cend(); ++it){
        if((*it).second == b){
            cout << endl;
            cout << "HIT - linha " << (*it).first << endl; 
            cont++;
        }
    }
    if(cont == 0){
        cout << endl;
        cout << "MISS - Alocado na linha " << b%linhas << " - bloco " << b << " substituido" << endl;
        cache.find(b%linhas)->second = b;
    }

}
/////////////////////////////////////////////////
void Aleatorio_TA(int palavras, int linhas, int principal){

}
/////////////////////////////////////////////////
void FIFO_TA(int palavras, int linhas, int principal){

}
/////////////////////////////////////////////////
void LFU_TA(int palavras, int linhas, int principal){

}

void LRU_TA(int palavras, int linhas, int principal){

}
/////////////////////////////////////////////////
void Aleatorio_PA(int palavras, int linhas, int principal, int set){

}
/////////////////////////////////////////////////
void FIFO_PA(int palavras, int linhas, int principal, int set){

}
/////////////////////////////////////////////////
void LFU_PA(int palavras, int linhas, int principal, int set){

}
/////////////////////////////////////////////////
void LRU_PA(int palavras, int linhas, int principal, int set){

}