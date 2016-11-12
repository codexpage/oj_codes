#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#define MAXN 10010
using namespace std;

struct s{
	int a;
	int b;
};

bool cmp(struct s left,struct s right){//a小为真
	return left.a<right.a;
}

int main(){
	int L,P,N;
	scanf("%d",&N);
	s pa[MAXN];
	for(int i=0;i<N;i++){
		scanf("%d %d",&pa[i].a,&pa[i].b);
	}
	scanf("%d %d",&L,&P);
	for (int i = 0; i < N; ++i)
	{
		pa[i].a=L-pa[i].a;
	}
	sort(pa,pa+N,cmp);//排序后，按照a从小到大排序
	pa[N].a=L;
	pa[N].b=0;

	// for (int i = 0; i < N; ++i)
	// {
	// 	printf(" %d ",pa[i].a);
	// }
	// 	for (int i = 0; i < N; ++i)
	// {
	// 	printf(" %d ",pa[i].b);
	// }
	int count=0,pos=0,tank=P;
	priority_queue<int> que;

	for(int i=0;i<N+1;i++){
		int d = pa[i].a-pos;
		while(tank-d<0){
			if(que.empty()){
				printf("%d\n",-1);
				return 0;
			}
			tank+=que.top();
			que.pop();
			count++;
		}
		tank-=d;
		pos=pa[i].a;
		que.push(pa[i].b);

	}
	printf("%d\n",count);

	return 0;
}