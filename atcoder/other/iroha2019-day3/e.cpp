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
	int n; scanf("%d",&n);
	vector<char> a(n);
	rep(i,n) scanf(" %c",&a[i]);

	auto R=run_length_encoding(a);

	int ans=0;
	rep(i,int(R.size())-1){
		if(R[i].first=='/' && R[i+1].first=='\\' && R[i].second==R[i+1].second) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
