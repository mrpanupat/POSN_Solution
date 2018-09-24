#include<stdio.h>

int n,m;

char gem();
char genGem(int optionA[],int optionB[],int hateA[],int hateB[],int gemStr[],int size);
main(){
	int i;
	char str[6] = {};
	for(i=0;i<5;i++){
		str[i] = gem();
	}
	printf("%s",str);
}
char gem(){
	int i,j;
	scanf("%d",&n);
	scanf("%d",&m);
	int optionA[n];
	int optionB[n];
	int hateA[m];
	int hateB[m];
	int gemStr[n];
	for(i=0;i<n;i++){
		scanf("%d",&optionA[i]);
		scanf("%d",&optionB[i]);
	}
	for(i=0;i<m/2;i++){
		scanf("%d",&hateA[i]);
		scanf("%d",&hateB[i]);
	}
	return genGem(optionA,optionB,hateA,hateB,gemStr,0);
}
char genGem(int optionA[],int optionB[],int hateA[],int hateB[],int gemStr[],int size){
	if(size==n){
		int i,j,k;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=0;k<m;k++){
					if((gemStr[i]==hateA[k]&&gemStr[j]==hateB[k])||(gemStr[i]==hateB[k]&&gemStr[j]==hateA[k])) return 'N';
				}		
			}
		}
		return 'Y';
	}
	gemStr[size] = optionA[size];
	char result1 = genGem(optionA,optionB,hateA,hateB,gemStr,size+1);
	gemStr[size] = optionB[size];
	char result2 = genGem(optionA,optionB,hateA,hateB,gemStr,size+1);
	
	if(result1=='Y') return result1;
	else return result2;
}
