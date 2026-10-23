//LinkList.cpp
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *pNode;

void CreatList(pNode &Head){
	Head = (LNode*)malloc(sizeof(LNode));
	Head->next = NULL;
	LNode *tail = Head;
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		LNode *s = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &s->data);
		s->next = NULL;
		tail->next = s;
		tail = s;
	}
}

LNode* Find(LNode *Head, ElemType e){
	LNode *p = Head->next;
	while(p!=NULL && p->data!=e) p=p->next;
	return p;
}

LNode* FindKth(LNode *Head, int k){
	if(k<0) return NULL;
	LNode *p = Head;
	int i = 0;
	while(p!=NULL && i<k){
		p = p->next;
		i++;
	}
	return p;
}

bool Insert(LNode *Head, int i, ElemType e){
	LNode *p = FindKth(Head, i-1);
	if(p==NULL) return false;
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
