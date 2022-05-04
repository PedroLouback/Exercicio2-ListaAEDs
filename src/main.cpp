#include "lista.hpp"

int main(){

	Lista l;
	Item aux;
	string nome_arquivo;
	ifstream arq;

	FLVazia(&l);

	cout << "\nInforme o nome do arquivo em que contém a lista de 100 nomes: ";
	getline(cin, nome_arquivo);

	arq.open(nome_arquivo);

	while(!arq.eof()){
		getline(arq, aux.nomes);
		LInsert(&l, aux);
	}
	arq.close();

	cout << "\nSegue a lista com os nomes: " << endl;
	LImprime(&l);

	RemoveIgualdade(&l);
	
	// LImprime(&l);

	// aux.val = 10;
	// LInsert(&l, aux);
	// aux.val = 20;
	// LInsert(&l, aux);
	// aux.val = 30;
	// LInsert(&l, aux);

	// LImprime(&l);

	// aux.val = 20;
	// LRemove(&l, aux);

	// LImprime(&l);

	return 0;
}
