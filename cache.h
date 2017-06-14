#ifndef CACHE_H
#define CACHE_H

#include <iostream>
#include <map>

using namespace std;

void Show(map<int,int> cache, int principal, int linhas, int palavras);

void Direto(map<int,int> &cache, int palavras, int linhas, int principal, int x);

void Aleatorio_TA(int palavras, int linhas, int principal);

void FIFO_TA(int palavras, int linhas, int principal);

void LFU_TA(int palavras, int linhas, int principal);

void LRU_TA(int palavras, int linhas, int principal);

void Aleatorio_PA(int palavras, int linhas, int principal, int set);

void FIFO_PA(int palavras, int linhas, int principal, int set);

void LFU_PA(int palavras, int linhas, int principal, int set);

void LRU_PA(int palavras, int linhas, int principal, int set);


#endif