#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	auto f=[](int x){
		vector<int> res(4);
		while(x%2==0) res[0]++, x/=2;
		while(x%3==0) res[1]++, x/=3;
		while(x%5==0) res[2]++, x/=5;
		while(x%7==0) res[3]++, x/=7;
		return res;
	};

	auto tar=f(x);
	while(x%2==0) x/=2;
	while(x%3==0) x/=3;
	while(x%5==0) x/=5;
	while(x%7==0) x/=7;
	if(x!=1){
		puts(":(");
		return 0;
	}

	vector<int> cur(4);
	set<vector<int>> S;
	rep(i,n+1){
		vector<int> v(4);
		rep(j,4) v[j]=cur[j]-tar[j];
		if(S.count(v)>0){
			puts("Yay!");
			return 0;
		}
		S.emplace(cur);

		if(i<n){
			auto w=f(a[i]);
			rep(j,4) cur[j]+=w[j];
		}
	}
	puts(":(");

	return 0;
}
