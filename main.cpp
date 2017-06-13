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

        if(mapeamento == 1){
                
                if(show){
                    Show();
                }
                
                if(x>=0 && x<= (palavras*principal) && !show){
                    Direto(palavras, linhas, principal);
                }
                show = false;    
        }

        else if(mapeamento == 2){
                
                if(show){
                    Show();
                }
                if(x>=0 && x<= (palavras*principal) && !show){
                    Totalmente_Associativo(palavras, linhas, principal, mapeamento, substituicao);
                }
                show = false; 
        }

        else if(mapeamento == 3){
                
                if(show){
                    Show();
                    cout << "SHOW CACHE" << endl;
                }
                
                if(x>=0 && x<= (palavras*principal) && !show){
                    Parcialmente_Associativo(palavras, linhas, principal, set, mapeamento, substituicao);
                     cout << "HIT OU MISS" << endl;
                }
                show = false;
        }

    }while(1);


    return 0;
}