///////////////////////////////////////////////
//Programa que  implementa uma lista circular//
///////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////
//Declaracao do no//
////////////////////

struct no {
	int numero;
	struct no *proximo;
};

///////////////////////////
//declaracao de variaveis//
///////////////////////////

struct no * cabeca;

////////////////////////////////////
//funcao que insere um no na lsita//
////////////////////////////////////

void inserir(int numero){
	//alocacao de memoria
	struct no *novoNo = (struct no*) malloc (sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	if(cabeca == NULL){
		cabeca = novoNo;
		novoNo -> proximo = cabeca;
		
	} else {
		struct no *ponteiro = cabeca;
		while(ponteiro -> proximo != cabeca) 
			ponteiro = ponteiro -> proximo;
		ponteiro -> proximo = novoNo;
	}
}
	
		
void imprimir(){

	struct no *ponteiro = cabeca;
	
	if(ponteiro != NULL){
		while(1){
			printf("%d\n", ponteiro -> numero);
			ponteiro = ponteiro -> proximo;
			if(ponteiro == cabeca)
				break;
		}
	}

	printf("===================\n");
}
void remover(int numero){
	if (cabeca != NULL){
		if (cabeca -> numero == numero){
			if(cabeca -> proximo == cabeca){
				//casp facil, so tem 1 elemento na lista 
				free(cabeca);
				cabeca = NULL;
			}else{
			//Caso difícil, excluir o primeiro no da lista
			struct no *ponteiroExcluir = cabeca;
			cabeca = cabeca -> proximo;
			
			struct no *ponteiroAnterior = cabeca;
			
			while(ponteiroAnterior -> proximo != ponteiroExcluir){
				ponteiroAnterior = ponteiroAnterior -> proximo;
			}
				ponteiroAnterior -> proximo = cabeca;
				free (ponteiroAnterior);
			}
		} else {
			//caso dificil excluir no meio da lista
			struct no *ponteiroAnterior = cabeca;
			
			while ((ponteiroAnterior -> proximo != cabeca)&&
			       (ponteiroAnterior -> proximo -> numero != numero))
			    ponteiroAnterior = ponteiroAnterior -> proximo;
		
		if(ponteiroAnterior -> proximo != cabeca){
			struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
			ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
			free(ponteiroExcluir);
		}
	}
	}
	}
int main(){
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	imprimir();
	remover(3);
	imprimir();
	
}
