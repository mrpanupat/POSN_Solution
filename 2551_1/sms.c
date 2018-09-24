#include<stdio.h>

int adjustTimes(int,int);
main(){
	char button[10][4]={0};
	button[2][0]='A';
	button[2][1]='B';
	button[2][2]='C';
	
	button[3][0]='D';
	button[3][1]='E';
	button[3][2]='F';
	
	button[4][0]='G';
	button[4][1]='H';
	button[4][2]='I';
	
	button[5][0]='J';
	button[5][1]='K';
	button[5][2]='L';
	
	button[6][0]='M';
	button[6][1]='N';
	button[6][2]='O';
	
	button[7][0]='P';
	button[7][1]='Q';
	button[7][2]='R';
	button[7][3]='S';
	
	button[8][0]='T';
	button[8][1]='U';
	button[8][2]='V';
	
	button[9][0]='W';
	button[9][1]='X';
	button[9][2]='Y';
	button[9][3]='Z';
	
	int n,i;
	scanf("%d",&n);
	int current,times;
	scanf("%d %d",&current,&times);
	int index=0;
	char str[81];
	times = adjustTimes(current,times);
	str[index++] = button[current][times];
	int h,v;
	for(i=0;i<n-1;i++){
		scanf("%d %d %d",&h,&v,&times);
		current = current + v*3 + h; 
		if(current==1){
			index = index - times;
			if(index<0) index = 0;
			str[index] = 0;
		}else{
			times = adjustTimes(current,times);
			str[index++] = button[current][times];
		}
	}
	if(str[0]==0) printf("null");
	else printf("%s",str);
}
int adjustTimes(int current,int times){
	times--;
	if((current>=2&&current<=6)||current==8){
		return times%3;
	}else{
		return times%4;
	}
}
