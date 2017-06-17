#include "cache_pa.h"
#include "funcoes.h"

void Show_PA(map<int,int> cache, int principal, int linhas, int palavras, int set){

    int aux = 0, via = -1;
    for(int i=0; i < linhas; i++){
        if(i%set == 0) via++;
        for(int j=0; j < palavras; j++){
            if(cache[i] >= 0 && cache[i] <= principal){
                cout << via << "  -  " << i%set << "  -   "<< cache[i] << "   -   " <<(cache[i]*palavras) + aux%palavras << endl;
            }
            else{
                cout << "x   -   x   -   x   -   x" << endl;
            }
            aux++;
        }
    }
}
/////////////////////////////////////////////////
void Aleatorio_PA(map<int,int> &cache, int palavras, int linhas, int principal, int set, int x){
    int b = x/palavras;
    int via = b%set;
    int cont=0, cheio = 0;

    for (auto it = cache.cbegin(); it != cache.cend(); ++it){
        if((*it).second == -1){
            cheio++;
        }
        if((*it).second == b){
            cout << endl;
            cout << "HIT - via " << via << " - linha " << (*it).first%set << endl; 
            cont++;
        }
    }
    if(cheio > 0 && cont == 0){
        for (auto it = cache.cbegin(); it != cache.cend(); ++it){
            if((*it).second == -1){
                cout << endl;
                cout << "MISS - Alocado na via " << via << " - linha " << (*it).first%set << " - bloco " << b << " substituido" << endl;
                cache.find((*it).first)->second = b;
                break;
            }
        }
    }
    if(cheio == 0 && cont == 0){
        srand(time(0));
        int random = rand()%linhas;
        cout << endl;
        cout << "MISS - Alocado na via " << via << " - linha " << random << " - bloco " << b << " substituido" << endl;
        cache.find(random)->second = b;
    }

}
/////////////////////////////////////////////////
void FIFO_PA(map<int,int> &cache, int palavras, int linhas, int principal, int set, int x, int* fifo){

}
/////////////////////////////////////////////////
void LFU_PA(map<int,int> &cache, int palavras, int linhas, int principal, int set, int x, int* lfu){

}
/////////////////////////////////////////////////
void LRU_PA(map<int,int> &cache, int palavras, int linhas, int principal, int set, int x, int* lru){

}