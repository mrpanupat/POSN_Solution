#include<stdio.h>

char checkTree();
main(){
	char result[5];
	int i=0;
	for(i=0;i<5;i++){
		result[i] = checkTree();
	}
	for(i=0;i<5;i++){
		printf("%c",result[i]);
	}
	
}
char checkTree(){
	int n,i,j;
	scanf("%d",&n);
	int edget1a[n-1],edget1b[n-1];
	int edget2a[n-1],edget2b[n-1];
	for(i=0;i<(n-1);i++){
		scanf("%d",&edget1a[i]);
		scanf("%d",&edget1b[i]);
	}
	for(i=0;i<(n-1);i++){
		scanf("%d",&edget2a[i]);
		scanf("%d",&edget2b[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((edget1a[i]==edget2a[j]&&edget1b[i]==edget2b[j])
			||(edget1a[i]==edget2b[j]&&edget1b[i]==edget2a[j])){
				edget1a[i]=0;
				edget1b[i]=0;
				edget2a[j]=0;
				edget2b[j]=0;
			}
		}
	}
	int flag=1;
	for(i=0;i<n-1;i++){
		//printf("%d %d %d %d\n",edget1a[i],edget1b[i],edget2a[i],edget2b[i]);
		if(edget1a[i]!=0||edget1b[i]!=0||edget2a[i]!=0||edget2b[i]!=0){
			flag=0;
			break;
		}
	}
	if(flag) return 'Y';
	else return 'N';
}
