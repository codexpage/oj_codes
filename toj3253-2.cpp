#include <iostream>
#include <algorithm>
#include <stdio.h>
#define MAXN 20010
#define ll long long
using namespace std;


int main(){
	ll n;
	ll l[MAXN];
	ll sum=0;
	scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&l[i]);
		}
		int i=0;
		while(i<n-1){
			int min1,min2;
			min1=i;min2=i+1;
			if(l[min1]>l[min2]) swap(min1,min2);
			for(int j=i;j<n;j++){
				if(l[min1]>l[j]){
					min2=min1;
					min1=j;
				}
				else if(l[min2]>l[j]&&j!=min1){
					min2=j;
				}
			}
			// for(int j=0;j<n;j++) printf(" %d ",l[j]);
			// printf("\n");
			sum+=l[min1]+l[min2];
			// printf("%d:%d+%d\n",i,l[min1],l[min2]);
			l[min2]=l[min1]+l[min2];
			swap(l[min1],l[i]);
			
			i++;
		}
		printf("%d\n",sum);
		
	
	return 0;
}