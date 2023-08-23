#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};

struct no *cabeca = NULL;

void inserir(int numero){
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	if (cabeca == NULL) {
		cabeca = novoNo;
	}else {
		struct no *ponteiro = cabeca;
//procura o ultimo no da lista
		while (ponteiro -> proximo != NULL) {
ponteiro = ponteiro -> proximo;
}
//executa os apontamenstos
	ponteiro -> proximo = novoNo;
	novoNo -> anterior = ponteiro;
}
}

void imprimir() {
	struct no *ponterio = cabeca;
	while (ponterio != NULL) {
		printf("%d\n", ponterio -> numero);
		ponterio = ponterio -> proximo;
}

	printf("=======\n");
}
/////////////////////////////////////	
// Função que remove um no na lista//
/////////////////////////////////////

void remover(int numero){
			struct no *ponteiro = cabeca;
			
			while(ponteiro != NULL){
				if (ponteiro -> numero == numero){
					if (ponteiro -> anterior == NULL){
						//Excluir o primeiro no da lista
						cabeca = cabeca -> proximo;
						if (cabeca != NULL){
							cabeca -> anterior = NULL;
						}
						free(ponteiro);
						ponteiro = cabeca;
					}else if(ponteiro -> proximo == NULL){
						//Excluir o ultimo no da lista
						struct no *temp = ponteiro;
						ponteiro = ponteiro -> anterior;
						ponteiro -> proximo = NULL;
						free(temp);
					} else{
						//Excluir um no no meio da lista
						struct no *temp = ponteiro;
						ponteiro = ponteiro -> anterior;
						temp -> anterior -> proximo = ponteiro -> proximo;
						temp -> proximo -> anterior = ponteiro -> anterior;
						free(temp);
					}
				}
			}
		}

int main(){
	remover(1);
	imprimir();
	
	inserir(1);
	remover(1);
	imprimir();
	
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	imprimir();
}
