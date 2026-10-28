#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define ADD_STACK 10

typedef struct {
	char *top;
	char *base;
	int stacksize;
} SqStack;

bool InitStack (SqStack &S)
{
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (S.base == NULL) return false;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return true;
}

bool StackEmpty (SqStack S)
{
	return S.top == S.base;
}

bool Push (SqStack &S, char e)
{
	if (S.top - S.base == S.stacksize) {
		char *newbase = (char*)realloc(S.base, (S.stacksize + ADD_STACK) * sizeof(char));
		if (newbase == NULL) return false;
		S.base = newbase;
		S.top = S.base + S.stacksize;
		S.stacksize += 	ADD_STACK;
	}
	*S.top++ = e;
	return true;
}

bool Pop (SqStack &S, char &e)
{
	if (StackEmpty(S)) return false;
	e = *(--S.top);
	return true;
}

bool GetTop (SqStack S, char &e)
{
	if (StackEmpty(S)) return false;
	e = *(S.top - 1);
	return true;
}

int Priority(char op)
{
	switch (op) {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		default : return 0;
	}
}

void Convert()
{
	SqStack S;
	if (!InitStack(S)) exit(EXIT_FAILURE);
	
	char ch, e;
	while (scanf(" %c", &ch) == 1 && ch != '#') {
		if (ch >='A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
			putchar(ch);
		} else if (ch == '(') {
			if (!Push (S, ch)) exit(EXIT_FAILURE);
		} else if (ch == ')') {
			GetTop (S, e);
			while (e != '(') {
				Pop (S, e);
				putchar (e);
				GetTop (S, e);
			}
			Pop (S, e);
		} else {
			while (!StackEmpty(S)) {
				GetTop (S, e);
				if (e == '(') break;
				if (Priority(e) > Priority(ch) || Priority(e) == Priority(ch) && ch != '^') {
					Pop (S, e);
					putchar(e);
				} else {
					break;
				}
			}
			if (!Push (S, ch)) exit(EXIT_FAILURE);
		}
	}
	while (!StackEmpty(S)) {
		Pop (S, e);
		putchar(e);
	}
	printf("\n");
	free(S.base);
}

int main()
{
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		Convert();
	}
	return 0;
}
