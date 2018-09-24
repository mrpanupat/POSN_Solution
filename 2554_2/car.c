#include<stdio.h>

int time;
int solution[100];

void findMap(int m,int map[][m],int current,int px);
void printSolution();
main(){
	int m;
	int start;
	scanf("%d",&m);
	scanf("%d",&start);
	scanf("%d",&time);
	int map[time+1][m];
	int i,j;
	
	for(i=1;i<=time;i++){
		for(j=0;j<m;j++){
			if(i==0) map[i][j]=0;
			else scanf("%d",&map[i][j]);	
		}
	}
	findMap(m,map,0,start-1);
}
void findMap(int m,int map[][m],int current,int px){
	if(current == time&&map[current][px]==0){
		printSolution();
		return;
	} 
	if(px>0) {
		if(map[current+1][px-1]==0){
			solution[current] = 1;
			findMap(m,map,current+1,px-1);
		}
	}
	if(map[current+1][px]==0){
		solution[current] = 3;
		findMap(m,map,current+1,px);
	}
	if(px<m-1) {
		if(map[current+1][px+1]==0){
			solution[current] = 2;
			findMap(m,map,current+1,px+1);
		}
	}
}
void printSolution(){
	int i;
	for(i=0;i<time;i++){
		printf("%d\n",solution[i]);
	}
}
