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

Lista AbreArquivo(Lista *l){
	string nome_arquivo;
	ifstream arq;
	Item aux;
	cout << "\nInforme o nome do arquivo em que contém a lista de 100 nomes: ";
	getline(cin, nome_arquivo);

	arq.open(nome_arquivo);

	while(!arq.eof()){
		getline(arq, aux.nomes);
		LInsert(l, aux);
	}
	arq.close();

	return *l;
}

void RemoveIgualdade(Lista *l){
	int i=0, j=0, k=0, count=0;
	bool repete = false;
	bool invalida = false;
	string aux_nomes[MAXTAM];
	for(i=l->first; i<l->last; i++){
		for(j=i+1; j<l->last; j++){
			if(l->vet[i].nomes == l->vet[j].nomes){
				//Aqui é feita a busca para verificar se o nome já foi repetido alguma vez percorrendo o vetor aux
				for(k=0; k<i; k++){ //máximo é o i pois foi até a onde a lista chegou até agora na verificação
					if(aux_nomes[k]==l->vet[i].nomes){ //Se existir quer dizer que já repetiu e repete virá true
						repete=true;
					}
				}
				if(repete==false){
					count++;
					aux_nomes[i]=l->vet[i].nomes;
				} //Se não existir vai manter false e adicionar no vetor
				l->vet[j].nomes = invalida;
			}
		}
	}
	cout << "\nExistem " << count << " nomes iguais!" << endl;
	cout << "\nOs nomes que apareceram iguais são: " << endl;
	for (i=0;i<count;i++){
		if(aux_nomes[i].size()!=0) //verifica se a string ta vazia antes de imprimir, para n imprimir todos as posições msm sem nada
			cout << aux_nomes[i] << endl;
	}
	if (count > 1){
		cout << "\nTodos os nomes iguais que foram encontrados foram removidos com sucesso, segue a lista sem a igualidade nos nomes: " << endl;
			for(int i=l->first; i<l->last; i++){
				if(l->vet[i].nomes.size()!= 0)
					cout << l->vet[i].nomes << endl;
			}
	}else 
		cout << "\nFoi feita a verificação de igualdade e não foi encontrado nenhum nome igual!" << endl;
	
}




