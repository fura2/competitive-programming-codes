#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,a[1000]; cin>>n>>k;
	rep(i,n) cin>>a[i];

	vector<long long> S;
	rep(i,n){
		long long s=0;
		for(int j=i;j<n;j++) s+=a[j], S.emplace_back(s);
	}

	for(int i=40;i>=0;i--){
		int m=S.size();
		vector<long long> T;
		rep(j,m) if(S[j]&(1LL<<i)) T.emplace_back(S[j]);

		if(T.size()>=k) S=T;
		else rep(j,m) S[j]&=~(1LL<<i);
	}
	cout<<S[0]<<endl;

	return 0;
}
