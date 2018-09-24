#include<stdio.h>

int prison[1000000] = {0};
main(){
	int n,m,i,counter=0,mCount=1;
	scanf("%d",&n);
	scanf("%d",&m);
	
	for(i=0;i<n;i++) prison[i] = i+1;
	//for(i=0;i<n;i++) printf("%c\n",prison[i]);;
	while(counter<n){
		if(prison[i]!='\0'){
			if(mCount==m){
				printf("%d\n",prison[i]);
				mCount=1;
				prison[i]='\0';
				counter++;
			}else mCount++;
		}
		i++;
		if(i>=n) i=0; 
	}
}
