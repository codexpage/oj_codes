#include <iostream>
#include <algorithm>
#include <stdio.h>
#define MAXN 20010
using namespace std;


int main(){
	int n;
	int l[MAXN];
	int sum=0;
	scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&l[i]);
		}
		int i=0;
		while(i<n-1){
			sort(l+i,l+n);
			sum+=l[i]+l[i+1];
			//printf("%d:%d+%d\n",i,l[i],l[i+1]);
			l[i+1]=l[i]+l[i+1];
			i++;
		}
		printf("%d\n",sum);
		
	
	return 0;
}