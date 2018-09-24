#include <stdio.h>

int main()
{
	int x,y,k;
	scanf("%d",&y);
	scanf("%d",&x);
	scanf("%d",&k);
	
	int map[y][x];
	int i,j,m,n;
	int max=0;
	for(i=0;i<y;i++){
	    for(j=0;j<x;j++){
	        scanf("%d",&map[i][j]);
	    }
	}
	int tmp;
	for(i=0;i<y+1-k;i++){
	    for(j=0;j<x+1-k;j++){
	        for(m=0;m<k;m++)
	            for(n=0;n<k;n++)
	                tmp = tmp+map[i+m][j+n];
	        if(tmp>max) max=tmp;
	        tmp=0;
	    }
	}
	printf("%d\n",max);
}
