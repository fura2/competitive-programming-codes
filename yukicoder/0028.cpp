#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

map<long long,int> prime_factorize(long long a){
	map<long long,int> res;
	if(a%2==0){
		int cnt=0;
		do{ cnt++; a/=2; }while(a%2==0);
		res.emplace(2,cnt);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		int cnt=0;
		do{ cnt++; a/=p; }while(a%p==0);
		res.emplace(p,cnt);
	}
	if(a>1) res.emplace(a,1);
	return res;
}

void solve(){
	int seed,n,k,base; scanf("%d%d%d%d",&seed,&n,&k,&base);

	int a[10001];
	a[0]=seed;
	rep(i,n) a[i+1]=1+(1LL*a[i]*a[i]+a[i]*12345LL)%100000009;

	int ans=INF;
	for(auto q:prime_factorize(base)){
		int p=q.first;

		int hist[30]={};
		rep(i,n+1){
			int cnt=0;
			while(a[i]%p==0) a[i]/=p, cnt++;
			hist[cnt]++;
		}

		int sum=0,rest=k;
		rep(x,30){
			if(rest>hist[x]){
				sum+=hist[x]*x;
				rest-=hist[x];
			}
			else{
				sum+=rest*x;
				break;
			}
		}
		ans=min(ans,sum/q.second);
	}
	printf("%d\n",ans);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
