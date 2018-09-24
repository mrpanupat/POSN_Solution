#include<stdio.h>

main(){
	int n,k,i,j,max=0;
	scanf("%d %d",&n,&k);
	int line[n];
	int count;
	for(i=0;i<n;i++){
		scanf("%d",&line[i]);
	}
	for(i=0;i<n;i++){
		int jumpEnd = line[i] + k;
		count=0;
		for(j=i+1;j<n;j++){
			//printf("%d %d\n",line[j],jumpEnd);
			if(jumpEnd>=line[j]) count++;
			else break;
		}
		//printf("-----------\n");
		if(count > max) max=count;
	}
	printf("%d",max);
}
