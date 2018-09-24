#include<stdio.h>

int row;
void domino(int n,char map[n][2],int size);
main(){
	scanf("%d",&row);
	char map[row][2];
	int i;
	for(i=0;i<row;i++){
		map[i][0] = 0;
		map[i][1] = 0;
	}
	domino(row,map,0);
}
void domino(int n,char map[n][2],int size){
	if(size==n){
		int i,j,count=0;;
		for(i=0;i<n&&count<n;i++){
			if(map[i][0]==0&&map[i][1]==0) 
				continue;
			if(map[i][0]=='-'&&map[i][1]=='-')
				printf("%c%c\n",map[i][0],map[i][1]);
			if(map[i][0]=='|'&&map[i][1]=='|'){
				printf("%c%c\n",map[i][0],map[i][1]);
				i++;
			}
		}
		printf("E\n");
		return;
	}else if(size>n){
		return;
	}else{
		map[size][0] = '-';
		map[size][1] = '-';
		domino(n,map,size+1);
		map[size][0] = '|';
		map[size][1] = '|';
		domino(n,map,size+2);
	}
}
