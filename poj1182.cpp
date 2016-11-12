#include <iostream>
#include <algorithm>
#include <stdio.h>
#define MAXN 50010
using namespace std;
int N,K;
int T[MAXN],X[MAXN],Y[MAXN];
int FA[MAXN];
int ranking[MAXN];

void init(){
	for(int i=0;i<MAXN;i++){
		FA[i]=i;
		ranking[i]=0;
	}
}

int find(int x){
	if(FA[x]==x) return x;
	else return FA[x]=find(FA[x]);
}

void merge(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa==fb) return;

	if(ranking[fa]<ranking[fb]){
		FA[fa]=fb;
	}
	else{
		FA[fb]=fa;
		if (ranking[a]==ranking[b]) ranking[fa]++;
	}

}

bool same(int a,int b){
	return find(a)==find(b);
}

int main(){
	scanf("%d %d",&N,&K);
	for(int i=0;i<K;i++){
		scanf("%d %d %d",&T[i],&X[i],&Y[i]);
		X[i]--;
		Y[i]--;
	}
	int count=0;
	int eat[MAXN],eaten[MAXN];
	memset(eat,-1,sizeof(eat));
	memset(eaten,-1,sizeof(eaten));
	init();
	
	for(int i=0;i<K;i++){
		int t=T[i];
		int x=X[i];
		int y=Y[i];

		if(x<0||x>=N||y<0||y>=N){
			count++;
			printf("%d out bound\n",i);
			continue;
		}

		if(t==1){
			if(!same(x,y)){
				merge(x,y);
			}
		}
		else{
			if(same(x,y)){
				printf("%d eat self\n",i);
				count++;
				continue;
			}
			else{
				if(eat[FA[x]]==-1 && eaten[FA[y]]==-1){
					eat[FA[x]]=FA[y];
					eaten[FA[y]]=FA[x];
					printf("%d new: eat[%d] is %d ,eaten[%d] is %d \n",i,x,FA[y],y,FA[x]);
				}
				else if(eat[FA[x]]==FA[y] && eaten[FA[y]]==FA[x]){
					continue;
				}
				else{
					printf("%d contradiction: eat[%d] is%d eaten[%d] is %d,new: eat[%d] is %d ,eaten[%d] is %d \n",i,x,eat[FA[x]],y,eaten[FA[y]],x,FA[y],y,FA[x]);
					count++;
					continue;
				}
			}
		}
	}

	printf("%d\n",count);
	return 0;
}