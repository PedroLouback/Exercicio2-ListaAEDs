#include "lista.hpp"

void Swap(Item *a, Item *b){
	Item aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void FLVazia(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void LInsert(Lista *l, Item d){
	if (l->last >= MAXTAM){
		cout << "LISTA CHEIA!" << endl;
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void LRemove(Lista *l, Item d){
	bool ok = false;

	if(l->first == l->last)
		cout << "LISTA VAZIA!" << endl;
	else{
		for(int i=l->first; i<l->last; i++)
			if(l->vet[i].nomes == d.nomes){
				Swap(&l->vet[i], &l->vet[i+1]);
				ok = true;	
			}
	
		if(ok)
			l->last --;
	}
}

void LImprime(Lista *l){
	for(int i=l->first; i<l->last; i++)
	cout << l->vet[i].nomes << endl;
}

void RemoveIgualdade(Lista *l){
	int i=0, j=0, count=0;
	bool invalida = false;
	for(i=l->first; i<l->last; i++){
		for(j=i+1; j<l->last; j++){
			if(l->vet[i].nomes == l->vet[j].nomes){
				l->vet[j].nomes = invalida;
				count++;
			}
		}
	}
	if (count > 1){
		cout << "\nTodos os nomes iguais que foram encontrados foram removidos com sucesso, segue a lista sem a igualidade nos nomes: " << endl;
		LImprime(l);
	}else 
		cout << "\nFoi feita a verificação de igualdade e não foi encontrado nenhum nome igual!" << endl;
	
}





