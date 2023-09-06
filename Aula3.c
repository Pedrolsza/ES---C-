//////////////////////////////////////////////
//Programa que implementa uma matriz esparsa//
//////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

////////////////////////////
// Declaração de constante//
////////////////////////////

const int MODULO = 3;

/////////////////////////////
// Declaração de Estruturas//
/////////////////////////////

struct no {
	int numero;
	struct no *proximoNo;
};

struct diretor {
	int resto;
	struct no *proximoNo;
	struct diretor *proximoDiretor;
};

////////////////////////////
// Declaração de variáveis//
////////////////////////////

struct diretor *cabeca = NULL;

//////////////////////////////////////
//Função que procura o diretor certo//
//////////////////////////////////////

struct diretor *procurarDiretor(int resto){
	struct diretor *ponteiro = cabeca;
	
	while ((ponteiro != NULL)&&(ponteiro -> resto != resto)){
		ponteiro = ponteiro -> proximoDiretor;
	}
	if (ponteiro == NULL) {
		//criar um diretor novo
		ponteiro = (struct diretor *) malloc(sizeof(struct diretor));
		ponteiro -> resto = resto;
		ponteiro -> proximoNo = NULL;
		ponteiro -> proximoDiretor = cabeca;
		
		cabeca = ponteiro;
	}
	return ponteiro;
}
void inserir(int numero){
	struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);
	
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	
	novoNo -> numero = numero;
	novoNo -> proximoNo = ponteiroDiretor -> proximoNo;
	
	ponteiroDiretor -> proximoNo = novoNo;
}

/////////////////////////////////////
//Função que imprime matriz esparsa//
/////////////////////////////////////

void imprimir(){
	struct diretor *ponteiroDiretor = cabeca;
	
	printf("================== MATRIZ ESPARSA ==================\n");
	while(ponteiroDiretor != NULL){
		struct no *ponteiroNo = ponteiroDiretor -> proximoNo;
		
		printf("%d:\t", ponteiroDiretor -> resto);
		while (ponteiroNo != NULL) {
			printf("%d\t", ponteiroNo -> numero);
			ponteiroNo = ponteiroNo -> proximoNo;
		}
		printf("\n");
		ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
	}
}

////////////////////////////////////////////
//Função principal de execução do programa//
////////////////////////////////////////////

void remover(int numero) {
	struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);
	
	if(ponteiroDiretor -> proximoNo -> numero == numero){
		//caso facil, excluir primeiro no da lista
		struct no *ponteiroExcluir = ponteiroDiretor -> proximoNo;
		ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
		free(ponteiroExcluir);
	} else {
		//caso dificil, excluir algum no meio da lista
		struct no *ponteiroAnterior = ponteiroDiretor -> proximoNo;
		
		while((ponteiroAnterior -> proximoNo != NULL)&& (ponteiroAnterior -> proximoNo -> numero != numero)){
		
		ponteiroAnterior = ponteiroAnterior -> proximoNo;
}
	if (ponteiroAnterior -> proximoNo != NULL) {
		struct no *ponteiroExcluir = ponteiroAnterior -> proximoNo;
		ponteiroAnterior -> proximoNo = ponteiroExcluir -> proximoNo;
		free(ponteiroExcluir);
	}
}
}

int main(){
	int i =  0;
	time_t t;
	int numero = 0;
	
	srand((unsigned) time(&t));
	

	for (i = 0; i <10; i++){
		inserir(rand());
	}
	
	imprimir();
	
	printf("Digite um numero para excluir: ");
	scanf("%d", &numero);
	
	remover(numero);
	
	remover(numero);
	
	imprimir();
}
























