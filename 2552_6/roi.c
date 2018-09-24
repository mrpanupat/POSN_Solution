#include<stdio.h>
#include<math.h>

main(){
	int c;
	scanf("%d",&c);
	
	int i,j;
	int price = 100;
	double min_profit=5000000;
	int min_salePrice,min_print;
	int d;
	double numSale;
	double cost;
	double income;
	double profit;
	for(i=1000;i<=15000;i=i+500){
		cost = price*i+c;
		for(j=74;j<=144;j++){
			d = j - 100;
			numSale=((100-(0.8569*exp(0.09*d)))*i)/100;
			income = numSale*j;
			profit = income-cost;
			
			if(profit>=0&&profit<min_profit){
				min_profit = profit;
				min_salePrice = j;
				min_print = i;
			}
		}
		price--;
	}
	printf("%d\n%d\n%.2lf",min_print,min_salePrice,min_profit);
}
