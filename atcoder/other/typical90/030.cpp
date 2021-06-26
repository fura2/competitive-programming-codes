#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class linear_sieve{
	vector<int> lpf,p;
public:
	linear_sieve(int n):lpf(n+1){
		for(int i=2;i<=n;i++){
			if(lpf[i]==0){
				lpf[i]=i;
				p.emplace_back(i);
			}
			for(int j=0;j<p.size()&&p[j]<=lpf[i]&&i*p[j]<=n;j++) lpf[i*p[j]]=p[j];
		}
	}

	int solve(int a){
		int res=0,last=0;
		for(;a>1;a/=lpf[a]){
			if(lpf[a]!=last) res++;
			last=lpf[a];
		}
		return res;
	}
};

int main(){
	int n,k; scanf("%d%d",&n,&k);

	linear_sieve S(n);

	int ans=0;
	for(int i=1;i<=n;i++) if(S.solve(i)>=k) ans++;
	printf("%d\n",ans);

	return 0;
}
