#ifndef CACHE_PA_H
#define CACHE_PA_H

#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

void Show_PA(map<int,int> cache, int principal, int linhas, int palavras, int set);

void Aleatorio_PA(map<int,int> &cache, int palavras, int linhas, int principal, int set, int x);

void FIFO_PA(map<int,int> &cache, int palavras, int linhas, int principal, int set, int x, int* fifo);

void LFU_PA(map<int,int> &cache, int palavras, int linhas, int principal, int set, int x, int* lfu);

void LRU_PA(map<int,int> &cache, int palavras, int linhas, int principal, int set, int x, int* lru);

#endif