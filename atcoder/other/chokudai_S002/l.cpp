#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
vector<T> longest_increasing_subsequence(const vector<T> &a){
	vector<T> lis;
	for(const auto& x:a){
		auto it=lower_bound(lis.begin(),lis.end(),x);
		if(it!=lis.end()) *it=x;
		else lis.emplace_back(x);
	}
	return lis;
}

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> p(n);
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		p[i]={a,b};
	}

	sort(p.begin(),p.end(),[](const auto& x,const auto& y){
		if(x.first!=y.first) return x.first<y.first;
		else                 return x.second>y.second;
	});

	vector<int> b(n);
	rep(i,n) b[i]=p[i].second;
	printf("%ld\n",longest_increasing_subsequence(b).size());

	return 0;
}
