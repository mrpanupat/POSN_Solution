#include<stdio.h>

main(){
	int bombCount;
	scanf("%d",&bombCount);
	int i,j,check=1;
	int bombX[bombCount];
	int bombY[bombCount];
	for(i=0;i<bombCount;i++){
		scanf("%d %d",&bombY[i],&bombX[i]);
	}
	for(i=0;i<bombCount;i++){
		check = 1;
		for(j=0;j<bombCount;j++){
			if(j==i) continue;
			if(bombY[i]<bombY[j]&&bombX[i]<bombX[j]) {
				check = 0;
				break;
			}
		}
		if(check) printf("%d %d\n",bombY[i],bombX[i]);
	}
}
