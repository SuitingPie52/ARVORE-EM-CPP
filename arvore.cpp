////////////////////////////////////////////////////
// PROGRAMA QUE IMPLEMENTA UMA ÁRVORE DE ORDEM 5 //
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>                
#include <time.h>       
#include <string.h>

struct no {
	
	int numero;
	struct no *filho1;
	struct no *filho2;
	struct no *filho3;
	struct no *filho4;
	struct no *filho5;
	
};

time_t t;


struct no *raiz = NULL;

struct no *inserir (struct no *raiz, int numero) {
	
	if (raiz == NULL) { // caso fácil: raiz nula (subárvore vazia)
		
		raiz = (struct no*) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> filho1 = NULL; 
		raiz -> filho1 = NULL; 
		raiz -> filho2 = NULL; 
		raiz -> filho3 = NULL; 
		raiz -> filho4 = NULL; 
		raiz -> filho5 = NULL; 
		
	} else { // caso difícil sortear um filho para inserir na árvore
		
		int sorteio = rand() % 5;
		
		if (sorteio == 0) {

			raiz -> filho1 = inserir(raiz -> filho1, numero);
		
		} else if (sorteio == 1) {
			
			raiz -> filho2 = inserir(raiz -> filho2, numero);
			
		} else if (sorteio == 2) {
			
			raiz -> filho3 = inserir(raiz -> filho3, numero);
			
		} else if (sorteio == 3) {
			
			raiz -> filho4 = inserir(raiz -> filho4, numero);
			
		} else if (sorteio == 4) {
			
			raiz -> filho5 = inserir(raiz -> filho5, numero);
			
		} 
	
	}
	
	return raiz;
	
}

void imprimir(struct no *raiz, char *endentador) {
	
	if (raiz != NULL) {

		printf("%s%d\n", endentador, raiz -> numero);
		
		char *temp = (char *) malloc(1024 * sizeof(char));
		strcpy(temp, endentador);
		strcat(temp, "---");
	
		imprimir(raiz -> filho1, temp);
		imprimir(raiz -> filho2, temp);
		imprimir(raiz -> filho3, temp);
		imprimir(raiz -> filho4, temp);
		imprimir(raiz -> filho5, temp);

	}
	
}

int main() {
	
	srand((unsigned) time(&t));
	
	char *edentador = (char *) malloc(1024 * sizeof(char));
	strcpy(edentador, "");
	
	int i;
	for (i = 0; i < 1000; i++) {
		
		raiz = inserir(raiz, i);
		
	}
	
	imprimir(raiz, edentador);
	
	
	
}
