#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SqList;

int Find(SqList L, ElemType e){
	int i;
	for(i = 0; i < L.length; i++)
		if(L.data[i] == e) return i+1;
	return -1;
}

Status Insert(SqList &L, int i, ElemType e){
 	if(L.length == MAXSIZE) return FALSE; 
	if(i<1 || i>L.length+1) return FALSE;
	int j;
	for(j = L.length; j >= i; j--)
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;0
	L.length++;
	return TRUE;
}

Status Delete(SqList &L, int i){
	if(i<1 || i>L.length) return FALSE;
	int j;
	for(j = i-1; j < L.length-1; j++)
		L.data[j] = L.data[j+1];
	L.length--;
	return TRUE;
}


