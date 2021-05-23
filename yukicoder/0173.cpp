#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n,p[2]; scanf("%d 0.%d 0.%d",&n,&p[0],&p[1]);
	int a[2][20];
	rep(i,2){
		rep(j,n) scanf("%d",&a[i][j]);
		sort(a[i],a[i]+n);
	}

	int cnt=0;
	rep(_,1000000){
		int score=0;
		bool used[2][20]={};
		rep(t,n){
			int idx[2];
			rep(i,2){
				if(t==n-1 || rng()%1000<p[i]){
					for(idx[i]=0;used[i][idx[i]];idx[i]++);
				}
				else{
					int k=rng()%(n-t-1)+1;
					for(idx[i]=n-1;;idx[i]--){
						if(!used[i][idx[i]]) k--;
						if(k==0) break;
					}
				}
				used[i][idx[i]]=true;
			}
			if(a[0][idx[0]]>a[1][idx[1]]) score+=a[0][idx[0]]+a[1][idx[1]];
			else                          score-=a[0][idx[0]]+a[1][idx[1]];
		}
		if(score>0) cnt++;
	}
	printf("%.9f\n",cnt/1e6);

	return 0;
}
