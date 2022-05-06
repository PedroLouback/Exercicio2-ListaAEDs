#include "lista.hpp"

int main(){

	Lista l;

	FLVazia(&l);

	AbreArquivo(&l);

	cout << "\nSegue a lista com os nomes: " << endl;
	LImprime(&l);

	RemoveIgualdade(&l);

	return 0;
}
