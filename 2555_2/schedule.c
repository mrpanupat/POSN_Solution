#include<stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct Times {
	int date;
	int hour;
}Time;

int maxTime;
Time minTime;
Time findMinDate(int j[],int jLeft,int k[],int kLeft);
Time getMin(Time time1,Time time2);
Time addHour(Time time,int hour);
main(){
	int task;
	scanf("%d",&maxTime);
	scanf("%d",&task);
	
	int j[task];
	int k[task];
	int *minDate;
	int i;
	for(i=0;i<task;i++){
		scanf("%d",&j[i]);
	}
	for(i=0;i<task;i++){
		scanf("%d",&k[i]);
	}
	Time x = findMinDate(j,task,k,task);
	printf("%d\n%d",x.date,x.hour);
}
Time findMinDate(int j[],int jLeft,int k[],int kLeft){
	//printf("Loop\n");
	if(jLeft == 0){
		Time time;
		time.date=0;
		time.hour=0;
		int i;
		for(i=0;i<kLeft;i++){
			time = addHour(time,k[i]);
		}
		//printf("Base case1:date=%d hour=%d\n",time.date,time.hour);
		return time;
	}
	if(kLeft == 0){
		Time time;
		time.date=0;
		time.hour=0;
		int i;
		for(i=0;i<jLeft;i++){
			time = addHour(time,j[i]);
		}
		//printf("Base case2:date=%d hour=%d\n",time.date,time.hour);
		return time;
	}
	
	Time selectJ = findMinDate(j,jLeft-1,k,kLeft);
	selectJ = addHour(selectJ,j[jLeft-1]);
	Time selectK = findMinDate(j,jLeft,k,kLeft-1);
	selectK = addHour(selectK,k[kLeft-1]);
	Time x = getMin(selectJ,selectK);
	//printf("date=%d hour=%d\n",x.date,x.hour);
	return x;
}
Time getMin(Time time1,Time time2){
	
	if(time1.date>time2.date){
		return time2;
	}else if(time1.date==time2.date&&time1.hour>time2.hour){
		return time2;
	}else{
		return time1;
	}
}
Time addHour(Time time,int hour){
	if(time.date==0&&time.hour==0){
		time.date = 1;
		time.hour = hour;
	}else if(time.hour+hour<maxTime){
		time.hour = time.hour + hour;
	}else if(time.hour+hour==maxTime){
		time.hour = maxTime;
	}else if(time.hour+hour>maxTime){
		time.date = time.date + 1;
		time.hour = hour;
	}
	return time;
}
