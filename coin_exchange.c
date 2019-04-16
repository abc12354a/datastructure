#include <stdio.h>
#include <stdlib.h>
#include<iostream>
const int coin[3] = { 1,3,5 };
const int num = 3;
const int INF = 65535;
typedef struct {
	int nCoin;
	int lastsum;
	int addCoin;
}state;
int main() {
	int totall;
	scanf("%d", &totall);
	state(*sum) = (state*)malloc(sizeof(state)*(totall + 1));
	for (int i = 1; i <= totall; i++) {
		sum[i].nCoin = INF;
	}
	sum[0].nCoin = 0;
	sum[0].lastsum = 0;
	for (int i = 1; i <= totall; i++) {
		for (int j = 0; j < num; j++) {
			if (i - coin[j] >= 0 && sum[i - coin[j]].nCoin + 1 < sum[i].nCoin) {
				sum[i].nCoin = sum[i - coin[j]].nCoin + 1;
				sum[i].lastsum = j;
				sum[i].addCoin = coin[j];
				printf("in progress, nCoin is %d\n", sum[i].nCoin);
			}
		}
	}
	if (sum[totall].nCoin == INF) {
		printf("no existting change");
	}
	else {
		printf("min is %d", sum[totall].nCoin);
	}
	system("pause");
	return 0;
}
