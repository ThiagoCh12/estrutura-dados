#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int x = 10;
	int y = 20;
	int z = 100;
	char tc = 'c';
	int n = 24;
	int *ptr1 = &x;
	int *ptr2 = &y;
	int *ptr3 = &z;
	char *ptr4 = &tc;
	int *ptrN = &n;
	
	printf("valor x = %d\n", x);
	printf("valor y = %d\n", y);
	printf("valor z = %d\n", z);
	printf("valor n = %d\n", n);
	printf("valor tc = %c\n", tc);
	printf("-----------------------------------------\n");
	printf("End. Mem. x = %p\n", &x);
	printf("End. Mem. y = %p\n", &y);
	printf("End. Mem. z = %p\n", &z);
	printf("End. Mem. N = %p\n", &n);
	printf("End. Mem. tc = %p\n", &tc);
	printf("-----------------------------------------\n");
	printf("End. Mem ptr1 = %p\n", &ptr1);
	printf("End. Mem ptr2 = %p\n", &ptr2);
	printf("End. Mem ptr3 = %p\n", &ptr3);
	printf("End. Mem ptr4 = %p\n", &ptr4);
	printf("End. Mem ptrN = %p\n", &ptrN);
	printf("-----------------------------------------\n");
	printf("valor ptr1 = %p\n", ptr1);
	printf("valor ptr2 = %p\n", ptr2);
	printf("valor ptr3 = %p\n", ptr3);
	printf("valor ptr4 = %p\n", ptr4);
	printf("valor ptrN = %p\n", ptrN);
	printf("-----------------------------------------\n");
	printf("Vlr. onde ptr1 aponta = %d\n", *ptr1);
	printf("Vlr. onde ptr2 aponta = %d\n", *ptr2);
	printf("Vlr. onde ptr3 aponta = %d\n", *ptr3);
	printf("Vlr. onde ptr4 aponta = %c\n", *ptr4);
	printf("Vlr. onde ptrN aponta = %d\n", *ptrN);
	printf("-----------------------------------------\n");
	printf("End. Mem onde ptr1 aponta = %p\n", &*ptr1);
	printf("End. Mem onde ptr2 aponta = %p\n", &*ptr2);
	printf("End. Mem onde ptr3 aponta = %p\n", &*ptr3);
	printf("End. Mem onde ptr4 aponta = %p\n", &*ptr4);
	printf("End. Mem onde ptrN aponta = %p\n", &*ptrN);
	char nome[40];
	printf("Insira seu nome: ");
	gets(nome);
	int i;
	for(i=0;i<strlen(nome);i++){
		printf("ENDERECO DO CARACTER %c: %p\n",nome[i], &nome[i]);
	}
	
}
