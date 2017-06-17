#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "cache.h"
#include "cache_pa.h"
#include "funcoes.h"

using namespace std;

int main(){

    //lendo arquivo
    ifstream entrada("config");
	if(!entrada) {
		cerr << "O arquivo de entrada nao foi encontrado!" << endl;
		return 0;
    }
    string aux;
    int palavras, linhas, principal, set, mapeamento, substituicao;

    getline(entrada, aux);
    palavras = stoi(aux);
    
    getline(entrada, aux);
    linhas = stoi(aux);
    
    getline(entrada, aux);
    principal = stoi(aux);
    
    getline(entrada, aux);
    mapeamento = stoi(aux);
    
    getline(entrada, aux);
    set = stoi(aux);
    
    getline(entrada, aux);
    substituicao = stoi(aux);

    //Iniciando a cache
    map<int,int> cache;
    map<int,int>::iterator it = cache.begin();  
    for(int i=0; i<linhas; i++){
        cache.insert (it, pair<int,int>(i,-1));
    }  
    //Iniciando vetor auxiliar do fifo,lru e lfu
    int *vetor = new int[linhas];
    
    for(int i=0; i<linhas; i++){
        vetor[i] = 0;
    }

    //
    int x = -1;
    bool show = false;

    if(mapeamento == 3){
        cout << endl;
        cout << "!!!Reconfigure o arquivo de entrada. Mapeamento parcialmente associativo não disponível!!!" << endl;
    }

    do{

        menu(x, show, (palavras*principal));

        if(show && mapeamento == 3){
            Show_PA(cache, principal, linhas, palavras, set);
        }

        if(show && (mapeamento == 1 || mapeamento == 2)){
            Show(cache, principal, linhas, palavras);
        }

        if(mapeamento == 1){
                
                if(x>=0 && x<= (palavras*principal) && !show){
                    Direto(cache, palavras, linhas, principal, x);
                }
        }

        else if(mapeamento == 2){
                if(x>=0 && x<= (palavras*principal) && !show){
                    if(substituicao == 1){
                        Aleatorio_TA(cache, palavras, linhas, principal, x);
                    }
                    else if(substituicao == 2){
                        FIFO_TA(cache, palavras, linhas, principal, x, vetor);
                    }
                    else if(substituicao == 4){
                        LRU_TA(cache, palavras, linhas, principal, x, vetor);
                    }
                    else if(substituicao == 3){
                        LFU_TA(cache, palavras, linhas, principal, x, vetor);
                    }
                }
        }

        else if(mapeamento == 3){
                
                if(x>=0 && x<= (palavras*principal) && !show){
                    if(substituicao == 1){
                        Aleatorio_PA(cache, palavras, linhas, principal, set, x);
                    }
                    else if(substituicao == 2){
                        FIFO_PA(cache, palavras, linhas, principal, set, x, vetor);
                    }
                    else if(substituicao == 4){
                        LRU_PA(cache, palavras, linhas, principal, set, x, vetor);
                    }
                    else if(substituicao == 3){
                        LFU_PA(cache, palavras, linhas, principal, set, x, vetor);
                    }
                }
        }
        show = false;
        x = -1;

    }while(1);


    return 0;
}