#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Header.h"

int check(int **ss, int n){
	long long int s[50] = { 13, 1597, 2178309, 12586269025 };
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++){
			if (s[n-2] == ss[i][j])
				return 0;
		}
	return 1;
}

