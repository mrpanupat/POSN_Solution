#include<stdio.h>

main(){
	char key[4];
	gets(key);
	int wheelsKey1,wheelsKey2,wheelsKey3;
	int wheel1[9],wheel2[9],wheel3[9];
	wheelsKey1 = key[0]-'0';
	wheelsKey2 = key[1]-'0';
	wheelsKey3 = key[2]-'0';
	int i,j;
	for(i=0;i<9;i++){
		wheel1[i] = wheelsKey1++;
		wheel2[i] = wheelsKey2++;
		wheel3[i] = wheelsKey3++;
		
		if(wheelsKey1==10) wheelsKey1=1;
		if(wheelsKey2==10) wheelsKey2=1;
		if(wheelsKey3==10) wheelsKey3=1;
	}
	//for(i=0;i<9;i++){
	//	printf("%d\t%d\t%d\n",wheel1[i],wheel2[i],wheel3[i]);
	//}
	char data[256]={0};
	gets(data);
	int output;
	i=0;
	while(data[i]!=0){
		output = wheel3[wheel2[wheel1[data[i]-'0'-1]-1]-1];
		printf("%d",output);
		
		for(j=0;j<9;j++){
			wheel1[j] = wheel1[j] + wheelsKey1;
			wheel2[j] = wheel2[j] - 1;
			wheel3[j] = wheel3[j] + wheelsKey3;
			
			if(wheel1[j]>=10) wheel1[j] = wheel1[j]%10 + 1;
			if(wheel2[j]<=0) wheel2[j] = 9;
			if(wheel3[j]>=10) wheel3[j] = wheel3[j]%10 + 1;
			
			//printf("%d\t%d\t%d\n",wheel1[j],wheel2[j],wheel3[j]);
		}
		i++;
	}
}
