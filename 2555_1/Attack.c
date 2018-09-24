#include <stdio.h>

int main(void) {
	// your code goes here
	long p;
	int isRun = 1;
	scanf("%ld",&p);
	int p1=p,p2=p;
	int attk;
	int prev[2] = {-1};
	int i=0;
	while(isRun){
		scanf("%d",&attk);
		if(attk%2==0){
			if(prev[0]%2==0&&prev[1]%2==0&&i>=2){
				p1 = p1-3;
			}else{
				p1 = p1-1;
			}
		}else{
			if(prev[0]%2==1&&prev[1]%2==1&&i>=2){
				p2 = p2-3;
			}else{
				p2 = p2-1;
			}
		}
		if(p1<=0||p2<=0) isRun = 0;
		prev[i%2] = attk;
		i++;
	}
	if(p1<p2) {
		printf("0\n%d\n",attk);
	}else{
		printf("1\n%d\n",attk);
	}
	return 0;
}
