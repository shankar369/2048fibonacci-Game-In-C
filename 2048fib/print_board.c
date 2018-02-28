#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Header.h"

void redraw(){
	system("cls");
	
}


void print(int **s, int n,int p){
	int i, j, k;
	printf("\n\n\t\t w : move up  a : move left  s : move down  d : move right\n\n\n");
	printf("\t\tScore : %d", p);
	for (i = 0; i < n; i++){
		printf("\t\t\t"); printf("\n");
		printf("\t\t\t"); printf(" + ");
		
		for (k = 0; k < n; k++)
			 printf("________");
		 printf(" + ");
		 printf("\n");
		printf("\t\t\t");
		for (j = 0; j < n; j++){
			printf(" | ");
			printf("%5d ", s[i][j]);
		}
		 printf(" | ");
		//printf("\n");
	}
	printf("\t\t\t"); printf("\n");

	printf("\t\t\t"); printf(" + ");
	
	for (i = 0; i < n; i++)
		printf("________");
	printf(" + ");

	printf("\n\n\t\tEnter your move :  ");
}



