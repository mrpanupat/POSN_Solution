#include<stdio.h>

int k;
void recureResult(int a,int b,int set,char arr[],int size){
    if(size-1>set) return;
    if(a==k||b==k){
        int i=0;
        for(i=0;i<size;i++){
            printf("%c ",arr[i]);
        }
        printf("\n");
        return;
    }
    arr[size] = 'W';
    recureResult(a+1,b,set,arr,size+1);
    arr[size] = 'L';
    recureResult(a,b+1,set,arr,size+1);
}
int main(){
    int a,b;
    scanf("%d",&k);
    scanf("%d",&a);
    scanf("%d",&b);
    int set = 2*k-1;
    char result[set];
    
    recureResult(a,b,set,result,0);
}