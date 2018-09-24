#include<stdio.h>
int state = 1;
char decode(char *line);
main(){
	int n;
	scanf("%d ",&n);
	char line[n][17];
	int i,j;
	for(i=0;i<n;i++){
		gets(line[i]);
	}
	for(i=0;i<n;i++){
		char ans = decode(line[i]);
		if(ans>='A'&&ans<='Z')printf("%c",ans);
	}	
}
char decode(char *line){
	
	char ans=0;
	int i;
	for(i=0;i<16;i=i+2){
		if(line[i]==0||line[i+1]==0){
			ans=0;
			break;
		}
		if(state==1){
			if(line[i]=='0'&&line[i+1]=='0'){
				state = 1;
				ans += 0;
			}else{
				state = 2;
				ans += 1;
			}
		}else if(state==2){
			if(line[i]=='1'&&line[i+1]=='0'){
				state = 3;
				ans += 0;
			}else{
				state = 4;
				ans += 1;
			}
		}else if(state==3){
			if(line[i]=='0'&&line[i+1]=='0'){
				state = 2;
				ans += 1;
			}else{
				state = 1;
				ans += 0;
			}
		}else if(state==4){
			if(line[i]=='1'&&line[i+1]=='0'){
				state = 4;
				ans += 1;
			}else{
				state = 3;
				ans += 0;
			}
		}
		if(i<14) ans = ans << 1;
	}
	return ans;
}
