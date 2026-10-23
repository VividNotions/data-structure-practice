#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int coef, exp;
	struct node *next;
}NODE;

void multiplication(NODE *head1, NODE *head2, NODE *head3){
	NODE *p = head1->next, *q;
	while(p!=NULL){
		q = head2->next;
		while(q!=NULL){
			NODE *r = head3->next;
			while(r!=NULL && r->exp != p->exp + q->exp) r = r->next;
			if(r!=NULL){
				r->coef += p->coef * q->coef;
			}else{
				NODE *s = (NODE*)malloc(sizeof(NODE));
				s->coef = p->coef * q->coef;//create a new node
				s->exp = p->exp + q->exp;
				NODE *k = head3;//locate the position to insert
				while(k->next!=NULL && k->next->exp < s->exp) k = k->next;
				s->next = k->next;//insert
				k->next = s;
			}
			q = q->next;
		}
		p = p->next;
	}
	NODE *d = head3->next, *dPrior = head3;//delete the node whose coef is 0
	while(d!=NULL){
		if(d->coef==0){
			dPrior->next = d->next;
			free(d);
			d = dPrior->next;
		}else{
			d = d->next;
			dPrior = dPrior->next;
		}
	}
	if(head3->next == NULL){
		NODE *zero = (NODE*)malloc(sizeof(NODE));
		zero->coef = 0;
		zero->exp = 0;
		zero->next = NULL;
		head3->next = zero;
	}
}

void input(NODE *head){
	int flag, sign, sum, x;
	char c;
	
	NODE *p = head;
	
	while((c=getchar()) != '\n'){
		if(c=='<'){
			sum = 0;
			sign = 1;
			flag = 1;
		}else if(c=='-'){
			sign = -1;
		}else if(c>='0' && c<='9'){
			sum = sum*10 + c-'0';
		}else if(c==','){
			if(flag==1){
				x = sign*sum;
				sum = 0;
				flag = 2;
				sign = 1;
			}
		}else if(c=='>'){
			p->next = (NODE*)malloc(sizeof(NODE));
			p->next->coef = x;
			p->next->exp = sign*sum;
			p = p->next;
			p->next = NULL;
			flag = 0;
		}
	}
}

void output(NODE *head){
	while(head->next != NULL){
		head = head->next;
		printf("<%d,%d>,", head->coef, head->exp);
	}
	printf("\n"); 
}

int main(){
	NODE *head1, *head2, *head3;
	
	head1 = (NODE*)malloc(sizeof(NODE));
	input(head1);
	
	head2 = (NODE*)malloc(sizeof(NODE));
	input(head2);
	
	head3 = (NODE*)malloc(sizeof(NODE));
	head3->next = NULL;
	multiplication(head1, head2, head3);
	
	output(head3);
	return 0;
}
