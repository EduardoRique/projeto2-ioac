#include "funcoes.h"

void menu(int &x, bool &show, int qntd){
    int opcao; /**< Opcao que sera passada pelo usuario */
    do{ 
        cout << endl;
        cout << "=========================================" << endl;
        cout << "Simulador de Hierarquia de Memória" << endl;
        cout << "=========================================" << endl;
        cout << "(1) Conferir palavra" << endl;
        cout << "(2) Mostrar a cache" << endl;
        cout << "(0) Sair" << endl;

        cout << endl;
        cout << "Digite a sua opcao: ";
        cin >> opcao;

        cout << endl;
        
        if(opcao<0 || opcao>2) cout << endl << endl << "=======================" << endl << "Digite uma opcao valida" << endl << "=======================" << endl << endl;

    }while(opcao != 0 && (opcao<0 || opcao>2));

    if(opcao == 0){
        exit(0);
    }
    else if(opcao == 1){
        int palavra;
        cout << "Digite a palavra pela qual deseja buscar(de 0 a " << qntd << "): ";
        cin >> palavra;
        x = palavra;
    }
    else if(opcao == 2){
        show = true;
    }
}