#include<stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int m;
int passX[400],passY[400];
int findMaxTemp(int map[m][m],int currentX,int currentY,int pass);
main(){
	scanf("%d",&m);
	int map[m][m];
	int startX,startY;
	scanf("%d %d",&startX,&startY);
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			scanf("%d",&map[i][j]);
		}
	}
	int max = findMaxTemp(map,startX-1,startY-1,0);
	printf("%d",max);
}
int findMaxTemp(int map[m][m],int currentX,int currentY,int pass){
	passX[pass] = currentX;
	passY[pass] = currentY;
	int isUp=1,isRight=1,isDown=1,isLeft=1;
	int up=-6,right=-6,down=-6,left=-6;
	int i;
	if(pass==m*m) return -6;
	//printf("%d %d val=%d\n",currentY,currentX,map[currentY][currentX]);
	//getch();
	for(i=0;i<pass;i++){
		
		if(passX[i]==currentX&&passY[i]==currentY-1) isUp=0; 
		if(passX[i]==currentX+1&&passY[i]==currentY) isRight=0; 
		if(passX[i]==currentX&&passY[i]==currentY+1) isDown=0; 
		if(passX[i]==currentX-1&&passY[i]==currentY) isLeft=0; 
	}
	if(isUp		&& currentY>0	&& map[currentY-1][currentX]>map[currentY][currentX] && map[currentY-1][currentX]!=100) up = findMaxTemp(map,currentX,currentY-1,pass+1);
	if(isRight	&& currentX<m-1	&& map[currentY][currentX+1]>map[currentY][currentX] && map[currentY][currentX+1]!=100) right = findMaxTemp(map,currentX+1,currentY,pass+1);
	if(isDown	&& currentY<m-1	&& map[currentY+1][currentX]>map[currentY][currentX] && map[currentY+1][currentX]!=100) down = findMaxTemp(map,currentX,currentY+1,pass+1);
	if(isLeft	&& currentX>0	&& map[currentY][currentX-1]>map[currentY][currentX] && map[currentY][currentX-1]!=100) left = findMaxTemp(map,currentX-1,currentY,pass+1);
	
	return MAX(MAX(up,right),MAX(down,MAX(left,map[currentY][currentX])));
}
