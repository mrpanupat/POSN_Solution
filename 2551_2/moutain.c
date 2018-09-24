#include<stdio.h>

main(){
	int n,i,j,k;
	scanf("%d",&n);
	int start[n];
	int high[n];
	int maxH=0,end=0;
	for(i=0;i<n;i++){
		scanf("%d %d",&start[i],&high[i]);
		if(high[i]>maxH) maxH = high[i];
		if(start[i]+(high[i] * 2)-1>end) end = start[i]+(high[i] * 2)-1;
	}
	char map[maxH][end];
	//init
	for(i=0;i<maxH;i++){
		for(j=0;j<end;j++){
			map[i][j] = '.';
		}
	}
	//draw
	for(k=0;k<n;k++){
		for(i=0;i<high[k];i++){
			for(j=0;j<(high[k]-i)*2;j++){
				if(j==0){
					if(map[i][start[k]+j+i-1] == '\\')
						map[i][start[k]+j+i-1] = 'v';
					else if(map[i][start[k]+j+i-1] == '.')
						map[i][start[k]+j+i-1] = '/';
				}else if(j==(high[k]-i)*2 - 1){
					if(map[i][start[k]+j+i-1] == '/')
						map[i][start[k]+j+i-1] = 'v';
					else if(map[i][start[k]+j+i-1] == '.')
						map[i][start[k]+j+i-1] = '\\';
				}else{
					map[i][start[k]+j+i-1] = 'X';
				}
			}
		}
	}
	//print 
	for(i=maxH-1;i>=0;i--){
		for(j=0;j<end;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
