#include <iostream>
#include <algorithm>
#include <stdio.h>
#define MAXN 1010
using namespace std;


int main(){
	int r,n;
	int x[MAXN];
	while(scanf("%d %d",&r,&n)&&!(r==-1&&n==-1)){
		for(int i=0;i<n;i++){
			scanf("%d",&x[i]);
		}
		sort(x,x+n);
		// for(int i=0;i<n;i++){
		// 	printf(" %d ",x[i]);
		// }
		int i=0;
		int count=0;
		while(i<n){
			int s=x[i];
			i++;
			while(i<n&&x[i]<=s+r) i++;
			int mid=x[i-1];//中间点是x-1
			count++;
			while(i<n&&x[i]<=mid+r) i++;

		}
		printf("%d\n",count);
	} 
	return 0;
}