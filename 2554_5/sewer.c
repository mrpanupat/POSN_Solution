#include<stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int findMin(int m,char map[][m],int pass[][m],int time,int x,int y);
int ansX,ansY;
int godOfMin=100000;
main(){
	int x,y,i,j;
	scanf("%d %d",&y,&x);
	char map[y][x];
	int pass[y][x];
	for(i=0;i<y;i++){
		for(j=0;j<x;j++){
			scanf(" %c",&map[i][j]);
			pass[i][j] = 100000;
		}
	}
	int min = findMin(x,map,pass,1,0,0);
	printf("%d\n%d %d",min,ansY,ansX);
}
int findMin(int m,char map[][m],int pass[][m],int time,int x,int y){
	int right=100000,down=100000,current=100000;
	
	if(pass[y][x]==100000) pass[y][x] = time;
	else current = pass[y][x] = MAX(pass[y][x],time);
	
	if(map[y][x]=='R'||map[y][x]=='B') right = findMin(m,map,pass,time+1,x+1,y);
	if(map[y][x]=='D'||map[y][x]=='B') down = findMin(m,map,pass,time+1,x,y+1);
	//printf("%d %d %d %d\n",current,right,down,MIN(current,MIN(right,down)));
	
	if(current==MIN(current,MIN(right,down))){
		if(current<godOfMin){
			godOfMin = current;
			ansX=x+1;
			ansY=y+1;
		}
		//printf("%d %d %d\n",ansY,ansX,current);
		return current;
	}else if(right==MIN(current,MIN(right,down))){
		return right;
	}else{
		return down;
	}
}
