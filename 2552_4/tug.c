#include<stdio.h>
#include<math.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int n;

int pair(int uni[],int dara[],int used[],int size);
main(){
	int i;
	scanf("%d",&n);
	int uni[n],dara[n],used[n];
	for(i=0;i<n;i++){
		scanf("%d",&uni[i]);
		used[i] = -1;
	}
	for(i=0;i<n;i++){
		scanf("%d",&dara[i]);
	}
	//printf("-----------\n");
	int min = pair(uni,dara,used,0);
	printf("%d",min);
}
int pair(int uni[],int dara[],int used[],int size){
	int i,j,flag=1,min=500000;
	int result;
	if(size<n) for(i=0;i<n;i++){
		flag=1;
		for(j=0;j<size;j++){
			if(i==used[j]) flag=0;
		}
		if(flag){
			used[size] = i;
			result = pair(uni+1,dara,used,size+1) + abs(uni[0]-dara[i]);
			//printf("%d\n",result);
			if(result<min) min = result;
		}
	}else min = 0;
	
	return min;
}
