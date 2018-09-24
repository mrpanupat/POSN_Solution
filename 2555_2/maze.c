#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int beforeX[50] = {0};
int beforeY[50] = {0};
	
void paintColor(int m,int n,int map[][n],int color,int px,int py);
int shortestPath(int m,int n,int map[][n],int px,int py,int ex,int ey,int pass);
int main()
{
    int x,y;
	scanf("%d",&y);
	scanf("%d",&x);
	int charX,charY;
	int exitX,exitY;
	scanf("%d %d",&charY,&charX);
	scanf("%d %d",&exitY,&exitX);
	int map[y+2][x+2];
	int i,j;
	for(i=0;i<=y+1;i++){
	    for(j=0;j<=x+1;j++){
	        if(i==0||j==0||i==y+1||j==x+1) map[i][j]=0;
	        else scanf("%d",&map[i][j]);
	    }
	}
    paintColor(y+2,x+2,map,2,charX,charY);
    paintColor(y+2,x+2,map,3,exitX,exitY);
	int breakable=0;
	for(i=1;i<=y;i++){
	    for(j=1;j<=x;j++){
	       if(map[i+1][j]==2||map[i-1][j]==2||map[i][j+1]==2||map[i][j-1]==2)
	            if(map[i+1][j]==3||map[i-1][j]==3||map[i][j+1]==3||map[i][j-1]==3){
	            	map[i][j] =1;
	            	breakable++;
				}
	                
	    }
	}
	printf("%d\n",breakable);
	int shortest = shortestPath(y+2,x+2,map,charX,charY,exitX,exitY,0);
    printf("%d\n",shortest);
    return 0;
}

void paintColor(int m,int n,int map[][n],int color,int px,int py){
    map[py][px] = color;
    
    if(map[py+1][px]==1) paintColor(m,n,map,color,px,py+1);
    if(map[py-1][px]==1) paintColor(m,n,map,color,px,py-1);
    if(map[py][px+1]==1) paintColor(m,n,map,color,px+1,py);
    if(map[py][px-1]==1) paintColor(m,n,map,color,px-1,py);
}
int shortestPath(int m,int n,int map[][n],int px,int py,int ex,int ey,int pass){
	int i,j;
	// print map
	/*for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i==py&&j==px) printf("T ");
			else printf("%d ",map[i][j]);
		}
		printf("\n");
	}*/
    if(px==ex&&py==ey) return 1;
	
    int up=200,down=200,left=200,right=200;
    int nUp=0,nDown=0,nLeft=0,nRight=0;
    //printf("n=%d m=%d x=%d y=%d \n",ex,ey,px,py);
    
	beforeX[pass] = px;
    beforeY[pass] = py;
    
    for(i=0;i<pass;i++){
    	if(beforeY[i]==py+1&&beforeX[i]==px) nUp = 1;
    	if(beforeY[i]==py-1&&beforeX[i]==px) nDown = 1;
    	if(beforeY[i]==py&&beforeX[i]==px+1) nRight = 1;
    	if(beforeY[i]==py&&beforeX[i]==px-1) nLeft = 1;
	}
    
	if(py<=m-1&&nUp==0){
        if(map[py+1][px]!=0)
            up = (shortestPath(m,n,map,px,py+1,ex,ey,pass+1) + 1);
    }
    if(py>=1&&nDown==0){
        if(map[py-1][px]!=0)
            down = (shortestPath(m,n,map,px,py-1,ex,ey,pass+1) + 1);
    }
    if(px>=1&&nLeft==0){
        if(map[py][px-1]!=0)
            left = (shortestPath(m,n,map,px-1,py,ex,ey,pass+1) + 1);
    }
    if(px<=n-1&&nRight==0){
        if(map[py][px+1]!=0)
            right = (shortestPath(m,n,map,px+1,py,ex,ey,pass+1) + 1);
    }
    return MIN(MIN(up,down),MIN(left,right));
}
