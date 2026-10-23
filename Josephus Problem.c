//Josephus Problem
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
//input
	//n:the total number of players
	//k:the player to start
	//m:the number of player(s) to skip
	int n, k, m, i;
	scanf("%d,%d,%d", &n, &k, &m);
	//check the input information
	if(n < 1 || k < 1 || m < 1){
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	else if(k > n){
		printf("k should not bigger than n.\n");
		return 0;
	}
//process & output
	//create the list
	struct Player {
		int no;
		struct Player *next;
	}player[n];
	for(i = 0; i < n-1; i++) {
		player[i].no = i+1;
		player[i].next = &player[i+1];
	}
	player[n-1].no = n;
	player[n-1].next = &player[0];
	//pass the sword
	struct Player *swd;
	swd = &player[k-1];
	while(swd != swd->next) {
		struct Player *p, *q;
		for(i = 1; i < m; i++) {
			swd = swd->next;
		}
		//record the player who has the sword
		printf("%d ", swd->no);
		//kill the player who has the sword
		p = swd;
		swd = swd->next;
		q = swd;
		while(q->next != p) {
			q = q->next;
		}
		q->next = p->next;
	}
	printf("%d\n", swd->no);
	return 0;
}
