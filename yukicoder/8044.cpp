#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
vector<pair<T,int>> run_length_encoding(const vector<T>& a){
	vector<pair<T,int>> res;
	int n=a.size(),pre=0;
	rep(i,n) if(i==n-1 || a[i]!=a[i+1]) res.emplace_back(a[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]), b[i]=a[i]%2;

	int pos=0;
	for(auto p:run_length_encoding(b)){
		if(p.first==1 && p.second>=m){
			lint sum=0;
			rep(i,p.second) sum+=a[pos+i];
			printf("%lld\n",sum);
		}
		pos+=p.second;
	}

	return 0;
}
