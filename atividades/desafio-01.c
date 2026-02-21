#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
Desafio: Criar struct contendo nome, idade e telefone e fazer a inserção do dado, apresentando os dados no final (para conferencia) 
Converter strutura para um vetor de 5 elementos. Fazer a entrada dos dados e apresentar no final
Construir um procedimento para entrada dos dados e  outro procedimento para saída
Construir  um procedimento para classificar o vetor (por nome). Fazer a entrada, o processamento (ordenação) e saída.
Construir um procedimento para classificar o vetor (por idade). Construir menu contendo (entrada, ordenar por nome, ordenar por idade, apresentar vetor, fim)
Construir um procedimento para classificar o vetor (por fone). Adicionar ao menu possibilidade de ordenar por fone também.
Otimizar código
*/

typedef struct  {
	char nome[50];
	int idade;
	char telefone[20];
} pessoa;

void entrada(pessoa p[], int tamanho){
	int c;
	int i;
	for(i=0; i<tamanho; i++){
		printf("Nome: ");
		fgets(p[i].nome, 49, stdin);
		printf("Telefone: ");
		fgets(p[i].telefone, 30, stdin);
		printf("Idade: ");
		scanf("%d", &p[i].idade);
		 	
		while ((c = getchar()) != '\n' && c != EOF);
	}
	
}
void saida(pessoa p[], int tamanho){
	int i;
	for(i=0; i<tamanho; i++){
		printf("Nome: %s\nIdade: %d\nTelefone: %s\n---\n", p[i].nome, p[i].idade, p[i].telefone);
	}
}
void ordenar_nomes(pessoa p[], int tamanho){
	int i, j;
	
	for(i=0; i< tamanho -1; i++){
		for(j=0; j< tamanho -i -1; j++){
			if(strcmp(p[j].nome, p[j+1].nome)>0){
				pessoa tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
		}
	}
}
void ordenar_idades(pessoa p[], int tamanho){
	int i, j;
	
	for(i=0; i< tamanho -1; i++){
		for(j=0; j< tamanho -i -1; j++){
			if(p[j].idade > p[j+1].idade){
				pessoa tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
		}
	}
}
void ordenar_telefone(pessoa p[], int tamanho){
	int i, j;
  	for(i=0; i<tamanho -1; i++){
    	for(j=0; j<tamanho -i -1;j++){
          	if(strcmp(p[j].telefone, p[j+1].telefone) > 0){
              	tmp = p[j];
              	p[j] = p[j+1];
              	p[j+1] = tmp;
            }
        }
    }
}
//------------------------ Funçoes utilizando qsort -------------------------------
int comparar_nome(const void* a, const void* b){
  pessoa *pa = (pessoa *)a;
  pessoa *pb = (pessoa *)b;
  
  return strcmp(pa -> nome, pb -> nome);
}

int comparar_telefone(const void* a, const void* b){
  pessoa *pa = (pessoa *)a;
  pessoa *pb = (pessoa *)b;
  
  return strcmp(pa -> telefone, pb -> telefone);
}

int comparar_idade(const void* a, const void* b){
  pessoa *pa = (pessoa *)a;
  pessoa *pb = (pessoa *)b;
  
  return pa -> idade - pb -> idade;
}

int main() {
	pessoa p[5];
    int opcao;
	int check = 0;
  	
	do {
	    printf("\n1 - Entrada\n");
	    printf("2 - Ordenar por nome\n");
	    printf("3 - Ordenar por idade\n");
      	printf("4 - Ordenar por telefone\n");
	    printf("5 - Mostrar saída\n");
		printf("0 - Sair\n");
	    scanf("%d", &opcao);
	
	    switch(opcao) {
	    	case 0:
	    		break;
	        case 1: 
				entrada(p, 5); 
				check = 1;
				break;
	        case 2: 
	        	if (check){
					qsort(p, 5, sizeof(pessoa), comparar_nome); 
				}
				else{
					printf("\nRealize uma entrada primeiro!!");
				}
				break;
	        case 3:
	        	if (check){
					qsort(p, 5, sizeof(pessoa), comparar_idade); 
				}
				else{
					printf("\nRealize uma entrada primeiro!!");
				}
	        	break;
          	case 4:
            	if (check){
                  qsort(p, 5, sizeof(pessoa), comparar_telefone);
                }else{
                  printf("\nRealize uma entrada primeiro!!");
                }
            	break;
	        case 5:
	        	if (check){
	        		saida(p, 5);
	        	}
				else{
	        		printf("\nRealize uma entrada primeiro!!");
				}
            	break;
			default:
				printf("\nOpção inválida!\n");
				break;
	    }  
	} while(opcao != 0);
	 
}