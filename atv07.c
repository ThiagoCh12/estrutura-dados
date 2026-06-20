#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
/*
7. Desenvolva um programa em C que simule uma PILHA com 20 valores
aleatorios entre 10 e 125. Posteriormente, remova todos os elementos
ímpares da pilha e apresente a pilha final ao usuário. Não esqueça de liberar
a pilha toda ao encerrar o programa.
*/

void push();
void remover_impar();
void pop();
void listar();

typedef struct no{
    int valor;
    struct no *proximo;
}no;

no *topo = NULL;

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int opcao, valor, i;
    do{
	    printf("\n1-Empilhar aleatoriamente\n2-Limpar impares\n3-Listar pilha\n4-Sair\nEscolha uma opção: ");
	    scanf("%d", &opcao);
	    switch(opcao){
		    case 1:
			    for(i=0;i<20;i++){
				    valor = rand()% 116 + 10;
				    push(&topo, valor);
			    }
			    break;
            case 2:
                remover_impar(&topo);
                break;
            case 3:
                listar(topo);
                break;
        }
    }while(opcao!=4);
    pop(&topo);
    return 0;
}

void push(no **topo, int valor){
    //printf("valor: %d\\n", valor);
    no *novo = malloc(sizeof(no));
    if (novo){
        novo->valor = valor;
        novo->proximo = *topo;
        *topo = novo;
    }else{
        printf("\nErro na alocaçao;");
        return;
    }
    printf("\nAlocado com sucesso.");
}

void remover_impar(no **topo){
    while(*topo != NULL && (*topo)->valor%2 != 0){
        no *aux = *topo;
        *topo = (*topo)->proximo;
        free(aux);
    }
    no *anterior = *topo;
    while(anterior!=NULL){
        no *atual = anterior->proximo;
        if(atual != NULL && atual->valor%2 != 0){
            anterior->proximo = atual->proximo;
            free(atual);
        }else{
            anterior = anterior->proximo;
        }
    }
}

void pop(no **topo){
    if(*topo != NULL){
        no *aux;
        do{
            aux = *topo;
            *topo = (*topo)->proximo;
            free(aux);
        }while(*topo!=NULL);
    }
}

void listar(no *topo){
    if(topo){
        do{
            printf("[%d]\n", topo->valor);
            topo=topo->proximo;
        }while(topo!=NULL);
    }else{
        printf("Pilha vazia");
    }
}