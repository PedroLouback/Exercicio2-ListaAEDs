#ifndef LISTA_HPP 
#define LISTA_HPP

#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#define MAXTAM 100

typedef struct Item{
	string nomes;
}Item;

typedef struct Lista{
	Item vet[MAXTAM];
	int first;
	int last;
}Lista;

void FLVazia(Lista *l);
void LInsert(Lista *l, Item d);
void LRemove(Lista *l, Item d);
void Swap(Item *a, Item *b);
void LImprime(Lista *l);
void RemoveIgualdade(Lista *l);

#endif