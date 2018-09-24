#include<stdio.h>

int isBaseTwo(int num,int max);
int printBaseTwo(int num);
int d;
main(){
	int i,j,townCount=1;
	scanf("%d",&d);
	for(i=0;i<d;i++) townCount = townCount*2;
	
	for(i=0;i<townCount;i++){
		for(j=i+1;j<townCount;j++){
			if(isBaseTwo(i^j,townCount)){
				printBaseTwo(i);
				printf(" ");
				printBaseTwo(j);
				printf("\n");
			}
		}
	}
}
int isBaseTwo(int num,int max){
	int i;
	for(i=1;i<=max;i=i*2){
		//printf("%d %d\n",num,i);
		if(num==i) return 1;
	}
	//printf("-------\n");	1
	return 0;
}
int printBaseTwo(int num){
	char str[d+1];
	str[d] = '\0';
	int i;
	for(i=0;i<d;i++){
		if(num%2==0) str[d-i-1]='0';
		if(num%2==1) str[d-i-1]='1';
		num = num/2;
	}
	printf("%s",str);
}
