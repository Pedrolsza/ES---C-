#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *proximo;
};

///////////////////////////
//Declaração de Variáveis//
///////////////////////////

struct no *cabeca = NULL;

////////////////////////////////////
//Função que Insere um no na Lista//
////////////////////////////////////

void inserir(int numero) {
	//Alocação do Espaço de memória
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		//Caso Fàcil, a lista está vazia
		cabeca = novoNo;
	} else {
		//Caso Díficil, a lista NÃO está vazia
		struct no *ponteiro = cabeca;
		
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo;
		}
		
		ponteiro -> proximo = novoNo;
	}
}
	

	void imprimir() {
		printf("===============\n");
		
		struct no *ponteiro = cabeca;
		while (ponteiro != NULL) {
			printf("%d\n", ponteiro -> numero);
			ponteiro = ponteiro -> proximo;
		} 
	}
	void remover(int numero) {
		if (cabeca != NULL) {
			if (cabeca -> numero == numero) {
				//caso facil, excluir o primeiro no da lista
				struct no *ponteiroExcluir = cabeca;
				cabeca = cabeca -> proximo;
				free(ponteiroExcluir);
			} else {
				//Caso dificil, excluir algum no meio da linha
				struct no *ponteiroAnterior = cabeca;
				
				while ((ponteiroAnterior -> proximo != NULL) && (ponteiroAnterior -> proximo -> numero != numero)) 
					ponteiroAnterior = ponteiroAnterior -> proximo;
				
				if (ponteiroAnterior -> proximo != NULL) {
					struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
					ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
					free(ponteiroExcluir);
				}
			}
		}
	}

int inserir_remover(int argc, char *argv[]) {
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	
	imprimir ();
	
	remover(100);
	remover(1);
	remover(3);
	remover(6);
	
	imprimir();
}

int main(int argc, char *argv[]) {
	int opcao = 0;
	int numero = 0;
	
	while (opcao != 4) {
		printf("+==========+\n");
		printf("| Menu de opcoes |\n");
		printf("+==========+\n");
		printf("| 1 - inserir |\n");
		printf("| 2  - remover |\n");
		printf("| 3 - imprimir |\n");
		printf("| 4 - sair |\n");
		printf("+==========+\n");
		printf("digite a opcao");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				printf("digite o numero: ");
				scanf("%d", &numero);
				remover(numero);
				break;
			case 2:
				printf("digite o numero: ");
				scanf("%d", &numero);
				remover(numero);
				break;
			case 3:
				imprimir();
				break;
		}
	}
}
