#include<stdio.h>

main(){
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	int b[n];
	double sum=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i]>a[j]&&b[i]<b[j]) sum += a[i]+a[j];
		}
	}
	printf("%.0lf",sum);
}
