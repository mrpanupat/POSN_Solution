#include<stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int calMoney(int person);
main(){
	int n;
	scanf("%d",&n);
	printf("%d",calMoney(n));
}
int calMoney(int person){
	if(person<=0) return 0;
	
	int one = calMoney(person-1)+500;
	int two = calMoney(person-2)+800;
	int five = calMoney(person-5)+1500;
	int fifteen = calMoney(person-15)+3000;
	return MIN(MIN(one,two),MIN(five,fifteen));
}
