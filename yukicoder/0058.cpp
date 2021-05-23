#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int cnt=0;
	rep(_,1e7){
		int sum=0;
		rep(i,n){
			sum+=rng()%6+1;
			if(i<k) sum-=rng()%3+4;
			else    sum-=rng()%6+1;
		}
		if(sum<0) cnt++;
	}
	printf("%.9f\n",cnt/1e7);
	return 0;
}
