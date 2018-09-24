#include<stdio.h>

int n;
int m;
void samplePrint(int data[],int size,int shown[],int noFirst[]);
main(){
	
	scanf("%d",&n);
	scanf("%d",&m);
	int i,j=0,k=0;
	int notFirst[m];
	int data[n];
	for(i=0;i<m;i++){
		scanf("%d",&notFirst[i]);
	}
	i=0;
	for(i=0;i<n;i++){
		data[i] = i+1;
	}
	
	int shown[m];
	samplePrint(data,n,shown,notFirst);
}
void samplePrint(int data[],int size,int shown[],int noFirst[]){
	int i,j,flag=1;
	if(size==0) {
		for(i=0;i<n;i++) {
			if(shown[0]==noFirst[i]){
				flag = 0;
				break;
			}
		}
		if(flag){
			for(i=0;i<n;i++) printf("%d ",shown[i]);
			printf("\n");
		}
		return;
	}
	for(i=0;i<n;i++){
		flag=1;
		for(j=0;j<n-size;j++){
			if(shown[j]==data[i]) {
				flag=0;
				break;
			}
		}
		if(flag){
			shown[n-size] = data[i];
			samplePrint(data,size-1,shown,noFirst);
		}
	}
}
