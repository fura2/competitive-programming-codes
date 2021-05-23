#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
vector<pair<T,int>> run_length_encoding(const vector<T>& a){
	vector<pair<T,int>> res;
	int n=a.size(),pre=0;
	rep(i,n) if(i==n-1 || a[i]!=a[i+1]) res.emplace_back(a[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	auto R=run_length_encoding(a);

	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		int cnt=0;
		for(auto p:R) cnt+=p.second/(mi+1);
		if(cnt<=k) hi=mi;
		else       lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
