#include<stdio.h>

void addTenPercen(int m,int n,double map[m][n],int x,int y);
double findMin(int m,int n,double map[m][n],int pass);
main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int i,j,k;
	double map[m][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&map[i][j]);
		}
	}
	double sum = findMin(m,n,map,0);
	printf("%.2lf",sum);
}
void addTenPercen(int m,int n,double map[m][n],int y,int x){
	double tenPercent = map[y][x]/10;
	if(y>0&&x>0&&map[y-1][x-1]!=-1) map[y-1][x-1] += tenPercent;
	if(y>0&&map[y-1][x]!=-1) map[y-1][x] += tenPercent;
	if(y>0&&x<n-1&&map[y-1][x+1]!=-1) map[y-1][x+1] += tenPercent;
	if(x>0&&map[y][x-1]!=-1) map[y][x-1] += tenPercent;
	if(x<n-1&&map[y][x+1]!=-1) map[y][x+1] += tenPercent;
	if(y<m-1&&x>0&&map[y+1][x-1]!=-1) map[y+1][x-1] += tenPercent;
	if(y<m-1&&map[y+1][x]!=-1) map[y+1][x] += tenPercent;
	if(y<m-1&&x<n-1&&map[y+1][x+1]!=-1) map[y+1][x+1] += tenPercent;
}
double findMin(int m,int n,double map[m][n],int pass){
	int i,j,k,flag;
	double minPrice=1000000000;
	double price;
	if(pass==m*n) return 0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			
			if(map[i][j]==-1) continue;
			double tmp[m][n];
			memcpy(tmp, map, sizeof(tmp));
			addTenPercen(m,n,tmp,i,j);
			tmp[i][j] = -1;
				
			price = findMin(m,n,tmp,pass+1) + map[i][j];

			if(price<minPrice) minPrice = price;
		}
	}
	return minPrice;
}
