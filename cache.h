#ifndef CACHE_H
#define CACHE_H

#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

void Show(map<int,int> cache, int principal, int linhas, int palavras);

void Direto(map<int,int> &cache, int palavras, int linhas, int principal, int x);

void Aleatorio_TA(map<int,int> &cache, int palavras, int linhas, int principal, int x);

void FIFO_TA(map<int,int> &cache, int palavras, int linhas, int principal, int x, int* fifo);

void LFU_TA(map<int,int> &cache, int palavras, int linhas, int principal, int x, int* lfu);

void LRU_TA(map<int,int> &cache, int palavras, int linhas, int principal, int x, int* lru);

#endif