#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Header.h"

int check_merge(int a, int b){

	int fib[50] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040 };
	int i;
	
	if (a < b){
		for (i = 0; i < 20; i++)
			if ((fib[i] == a)&&(fib[i + 1] == b))
				return 1;
	}
	else if (a>= b)
	{
		for (i = 0; i < 20; i++)
			if ((fib[i] == b)&&(fib[i + 1] == a))
				return 1;
	}
	return 0;
}

void make_order(int *a,char s,int n){
	int i, j = 0,b[10];

	for (i = 0; i < n; i++)
		b[i] = a[i];

	if (s == 'l'){
		j = 0;
		for (i = 0; i < n; i++)
			if (b[i] != 0)
				a[j++] = b[i];
		for (i = 0; i < n; i++)
			if (b[i] == 0)
				a[j++] = b[i];
	}
	else if (s == 'r'){
		j = 0;
		for (i = 0; i < n; i++)
			if (b[i] == 0)
				a[j++] = b[i];
		for (i = 0; i < n; i++)
			if (b[i]!=0)
				a[j++] = b[i];
	}
}


void merge(int *ss, int n, char s,int *p){
	int i, j;
	if (s == 'l'){

		for (i = 0; i < n ; i++){
			if (ss[i] != 0){
				for (j = i + 1; j < n; j++){
					if (ss[j] == 0)
						continue;
					if (check_merge(ss[i], ss[j])){

						ss[j] = ss[i] + ss[j];
						(*p) = (*p) + ss[j];
						ss[i] = 0;
						i = j + 1;
					}
					else{
						i = j ;
						j = i + 1;
						break;
					}
				}
			}
		}
		make_order(ss, 'l', n);
	}

	else if (s == 'r'){

		for (i = n - 1; i >=0; i--){
			if (ss[i] != 0){
				for (j = i - 1; j >= 0; j--){
					if (ss[j] == 0)
						continue;
					if (check_merge(ss[i], ss[j])){

						ss[j] = ss[i] + ss[j];
						(*p) = (*p) + ss[j];
						ss[i] = 0;
						i = j - 1;
					}
					else{
						i = j ;
						j = i - 1;
						break;						
					}
				}
			}
		}
		make_order(ss, 'r', n);
	}
	
}

void move_top(int **ss, int n,int *p){

	int i, j;
	int *a = (int*)calloc(sizeof(int), n);
	for (j = 0; j < n; j++){
		for (i = 0; i < n; i++){
			a[i] = ss[i][j];
		}
	merge(a, n, 'l',p);
	for (i = 0; i < n; i++)
		ss[i][j] = a[i];
}
	free(a);
	redraw();
	print(ss, n,*p);
}


void move_left(int **ss, int n, int *p){
	int i, j;
	int *a = (int*)calloc(sizeof(int), n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			a[j] = ss[i][j];
		}
		merge(a, n, 'l',p);
		for (j = 0; j < n; j++)
			ss[i][j] = a[j];
	}
	free(a);
	redraw();
	print(ss, n,*p);
}


void move_right(int **ss, int n, int *p){
	int i, j;
	int *a = (int*)calloc(sizeof(int), n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			a[j] = ss[i][j];
		}
		merge(a, n, 'r',p);
		for (j = 0; j < n; j++)
			ss[i][j] = a[j];
	}
	free(a);
	redraw();
	print(ss, n,*p);
}


void move_down(int **ss, int n, int *p){
	int i, j;
	int *a = (int*)calloc(sizeof(int), n);
	for (j = 0; j < n; j++){
		for (i = 0; i < n; i++){
			a[i] = ss[i][j];
		}
		merge(a, n, 'r',p);
		for (i = 0; i < n; i++)
			ss[i][j] = a[i];
	}
	free(a);
	redraw();
	print(ss, n,*p);
}