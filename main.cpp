#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "cache.h"
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

    //
    int x = -1;
    bool show = false;

    do{

        menu(x, show, (palavras*principal));

        if(show){
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
                        Aleatorio_TA(palavras, linhas, principal);
                    }
                    else if(substituicao == 2){
                        FIFO_TA(palavras, linhas, principal);
                    }
                    else if(substituicao == 3){
                        LRU_TA(palavras, linhas, principal);
                    }
                    else if(substituicao == 4){
                        LFU_TA(palavras, linhas, principal);
                    }
                }
        }

        else if(mapeamento == 3){
                
                if(x>=0 && x<= (palavras*principal) && !show){
                    if(substituicao == 1){
                        Aleatorio_PA(palavras, linhas, principal, set);
                    }
                    else if(substituicao == 2){
                        FIFO_PA(palavras, linhas, principal, set);
                    }
                    else if(substituicao == 3){
                        LRU_PA(palavras, linhas, principal, set);
                    }
                    else if(substituicao == 4){
                        LFU_PA(palavras, linhas, principal, set);
                    }
                }
                }
        }
        show = false;
        x = -1;

    }while(1);


    return 0;
}