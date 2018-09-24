#include<stdio.h>

main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	int i,j;
	int start[n];
	int finish[n];
	int pass[n];
	char result[n];
	int slot[k];
	int see[m];
	
	for(i=0;i<n;i++){
		scanf("%d",&start[i]);
		scanf("%d",&finish[i]);
		pass[i]=0;
	}
	for(i=0;i<m;i++){
		scanf("%d",&see[i]);
	}
	for(i=0;i<k;i++){
		slot[i] = -1;
	}
	
	int min = 500001;
	int min_idx;
	for(i=0;i<n;i++){
		min = 500001;
		//printf("ryu ga waka teki o kurauu\n");
		for(j=0;j<n;j++){
			if(start[j]<min&&!pass[j]){
				min = start[j];
				min_idx = j;
			}
		}
		
		for(j=0;j<k;j++){
			//printf("%d\n",min_idx);
			if(slot[j]==-1){
				slot[j] = min_idx;
				result[min_idx] = 'Y';
				break;
			}else if(finish[slot[j]]<start[min_idx]){
				slot[j] = min_idx;
				result[min_idx] = 'Y';
				break;
			}else{
				result[min_idx] = 'N';
			}		
		}
		pass[min_idx]=1;
	}
	
	for(i=0;i<m;i++){
		printf("%c ",result[see[i]-1]);
	}
}
