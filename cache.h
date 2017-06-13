#ifndef CACHE_H
#define CACHE_H

#include <iostream>
//#include <map>

void Show();

void Direto(int palavras, int linhas, int principal);

void Totalmente_Associativo(int palavras, int linhas, int principal, int mapeamento, int substituicao);

void Parcialmente_Associativo(int palavras, int linhas, int principal, int set, int mapeamento, int substituicao);


#endif