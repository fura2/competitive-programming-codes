#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	int ans=0;
	for(auto d:divisors(a[0])){
		bool ok=true;
		rep(i,n) if(a[i]%d!=0 && b[i]%d!=0) ok=false;
		if(ok) ans=max(ans,int(d));
	}
	for(auto d:divisors(b[0])){
		bool ok=true;
		rep(i,n) if(a[i]%d!=0 && b[i]%d!=0) ok=false;
		if(ok) ans=max(ans,int(d));
	}
	printf("%d\n",ans);

	return 0;
}
