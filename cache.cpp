#include "cache.h"

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
void Aleatorio_TA(map<int,int> &cache, int palavras, int linhas, int principal, int x){
    int b = x/palavras;
    int cont=0, cheio = 0;
    for (auto it = cache.cbegin(); it != cache.cend(); ++it){
        if((*it).second == -1){
            cheio++;
        }
        if((*it).second == b){
            cout << endl;
            cout << "HIT - linha " << (*it).first << endl; 
            cont++;
        }
    }
    if(cheio > 0 && cont == 0){
        for (auto it = cache.cbegin(); it != cache.cend(); ++it){
            if((*it).second == -1){
                cout << endl;
                cout << "MISS - Alocado na linha " << (*it).first << " - bloco " << b << " substituido" << endl;
                cache.find((*it).first)->second = b;
                break;
            }
        }
    }
    if(cheio == 0 && cont == 0){
        srand(time(0));
        int random = rand()%linhas;
        cout << endl;
        cout << "MISS - Alocado na linha " << random << " - bloco " << b << " substituido" << endl;
        cache.find(random)->second = b;
    }


}
/////////////////////////////////////////////////
void FIFO_TA(map<int,int> &cache, int palavras, int linhas, int principal, int x, int* fifo){
    
    int b = x/palavras;
    int cont=0, cheio = 0;
    
    for (auto it = cache.cbegin(); it != cache.cend(); ++it){
        if((*it).second == -1){
            cheio++;
        }
        if((*it).second >= 0 && (*it).second <= principal){
            fifo[(*it).first]++;
        }
        if((*it).second == b){
            cout << endl;
            cout << "HIT - linha " << (*it).first << endl; 
            cont++;
        }
    }
    
    if(cheio > 0 && cont == 0){
        for (auto it = cache.cbegin(); it != cache.cend(); ++it){
            if((*it).second == -1){
                cout << endl;
                cout << "MISS - Alocado na linha " << (*it).first << " - bloco " << b << " substituido" << endl;
                cache.find((*it).first)->second = b;
                break;
            }
        }
    }
    
    if(cheio == 0 && cont == 0){
        int maior = 0;
        for (int i=0; i<linhas; i++){
            if(fifo[i] > fifo[maior]) maior = i;
        }
        cout << endl;
        cout << "MISS - Alocado na linha " << maior << " - bloco " << b << " substituido" << endl;
        cache.find(maior)->second = b;
        fifo[maior] = 0;
    }

}
/////////////////////////////////////////////////
void LFU_TA(map<int,int> &cache, int palavras, int linhas, int principal, int x, int* lfu){

    int b = x/palavras;
    int cont=0, cheio = 0;
    
    for (auto it = cache.cbegin(); it != cache.cend(); ++it){
        if((*it).second == -1){
            cheio++;
        }
        if((*it).second == b){
            cout << endl;
            cout << "HIT - linha " << (*it).first << endl; 
            cont++;
            lfu[(*it).first]++;
        }
    }
    
    if(cheio > 0 && cont == 0){
        for (auto it = cache.cbegin(); it != cache.cend(); ++it){
            if((*it).second == -1){
                cout << endl;
                cout << "MISS - Alocado na linha " << (*it).first << " - bloco " << b << " substituido" << endl;
                cache.find((*it).first)->second = b;
                break;
            }
        }
    }
    
    if(cheio == 0 && cont == 0){
        int menor = 0;
        for (int i=0; i<linhas; i++){
            if(lfu[i] < lfu[menor]) menor = i;
        }
        cout << endl;
        cout << "MISS - Alocado na linha " << menor << " - bloco " << b << " substituido" << endl;
        cache.find(menor)->second = b;
        lfu[menor] = 0;
    }

}

void LRU_TA(map<int,int> &cache, int palavras, int linhas, int principal, int x, int* lru){

    int b = x/palavras;
    int cont=0, cheio = 0;
    
    for (auto it = cache.cbegin(); it != cache.cend(); ++it){
        if((*it).second == -1){
            cheio++;
        }
        if((*it).second >= 0 && (*it).second <= principal){
            lru[(*it).first]++;
        }
        if((*it).second == b){
            cout << endl;
            cout << "HIT - linha " << (*it).first << endl; 
            cont++;
            lru[(*it).first] = 0;
        }
    }
    
    if(cheio > 0 && cont == 0){
        for (auto it = cache.cbegin(); it != cache.cend(); ++it){
            if((*it).second == -1){
                cout << endl;
                cout << "MISS - Alocado na linha " << (*it).first << " - bloco " << b << " substituido" << endl;
                cache.find((*it).first)->second = b;
                break;
            }
        }
    }
    
    if(cheio == 0 && cont == 0){
        int maior = 0;
        for (int i=0; i<linhas; i++){
            if(lru[i] > lru[maior]) maior = i;
        }
        cout << endl;
        cout << "MISS - Alocado na linha " << maior << " - bloco " << b << " substituido" << endl;
        cache.find(maior)->second = b;
        lru[maior] = 0;
    }
}