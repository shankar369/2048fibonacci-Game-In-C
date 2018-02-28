#ifndef HEADER_H
#define HEADER_H

//int fib(int);

int check(int**, int);
void merge(int*,int,char,int*);
void move_top(int**,int ,int*);
void move_left(int**, int, int*);
void move_right(int**, int, int*);
void move_down(int**, int, int*);
void print(int**,int,int);
char take_input();
int isValidInput(char);
void redraw();
void print_result(struct user *);
#endif
