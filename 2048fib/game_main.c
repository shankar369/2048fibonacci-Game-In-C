#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Header.h"
#include<stdlib.h>
#include<string.h>
#include"Header.h"

struct user{
	char s[20];
	int points;
};


void print_result(struct user *ss){
	printf("\n\n\t\t\t\t\t *******Name : %s*********", ss->s);
	printf("\n\t\t\t\t\t*******Score is : %d***********", ss->points);
}

int isValidInput(char letter){
	if (letter == 'a' || letter == 'A' || letter == 'S' || letter == 's' || letter == 'w' || letter == 'W' || letter == 'd' || letter == 'D')
		return 1;
	return 0;
}


char take_input()
{
	char c;
	printf("\n");

	scanf(" %c ", &c);
	fflush(stdin);

	while (isValidInput(c) == 0){
		scanf(" %c ", &c);
		fflush(stdin);
	}

	return c;

}





int main(){
	struct user *ss = (struct user*)calloc(1,sizeof(struct user));
	int n,i,r1,r2,score=0;
	char ch;
	
	printf("Enter the user name : ");
	scanf("%s", ss->s);
	printf("\nEnter the size of board (n*n)  : ");
	scanf("%d", &n);
	int **a = (int**)calloc(n,sizeof(int));

	for (i = 0; i < n; i++)
		a[i] = (int*)calloc(n,sizeof(int));

	/*for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);*/
	redraw();
	
	/*printf("\nif\n");
	scanf("%d", &k);
	while (k){
		a[0][0] = a[1][1] =  99;
		system("cls");
		print(a, n);
		k = 0;
	}*/

	ss->points = 0;
	while (check(a,n)){
		r1 = rand() % (n);
		r2 = rand() % (n);
		if (a[r1][r2] == 0){
			a[r1][r2] = 1;
			redraw();
			print(a, n, ss->points);
		}
		else{
			
			while (a[r1][r2] != 0){
				r1 = rand() % (n);
				r2 = rand() % (n);
			}
			a[r1][r2] = 1;
			redraw();
			print(a, n, ss->points);
		}
		ch = getchar();
		fflush(stdin);

		if (ch== 'a' || ch == 'A')
			move_left(a, n, &(ss->points));
		else if (ch == 'w' || ch == 'W')
			move_top(a, n, &(ss->points));
		else if (ch == 'd' || ch == 'D')
			move_right(a, n, &(ss->points));
		else if (ch == 's' || ch == 'S')
			move_down(a, n, &(ss->points));
		
		
		/*if (take_input() == 'a' || take_input() == 'A')
			move_left(a,n);
		else if (take_input() == 'w' || take_input() == 'W')
			move_top(a, n);
		else if (take_input() == 'd' || take_input() == 'D')
			move_right(a, n);
		else if (take_input() == 's' || take_input() == 'S')
			move_down(a, n);*/
	}
	redraw();
	printf("\n\n\n\n\n\t\t\t*******************->YOU WON<-*************************");
	print_result(ss);

	getchar();
	system("pause");
	return 0;
}