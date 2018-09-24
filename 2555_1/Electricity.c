#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int n;
int k;

int OPT(int arr[],int current,int diff);
int main()
{
	
	scanf("%d",&n);
	int arr[n];
    scanf("%d",&k);
    int i;
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    int result = OPT(arr,0,0);
    printf("%d\n",result);
}

int OPT(int arr[],int current,int diff){
    if(current == 0) return OPT(arr,current+1,1)+arr[current];
    if((current) == n-1) {
        return arr[current];
    }
    if(diff >= k) {
        int val = OPT(arr,current+1,0)+arr[current];
        return val;
    }
    return MIN( OPT(arr,current+1,1)+arr[current] , OPT(arr,current+1,diff+1) );
}