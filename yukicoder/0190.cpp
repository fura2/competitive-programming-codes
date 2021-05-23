#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve1(vector<int> a){
	int n=a.size();
	sort(a.rbegin(),a.rend());

	int res=0,idx=n-1;
	rep(i,n){
		while(idx>i && a[i]+a[idx]<=0){
			idx--;
		}
		if(idx>i && a[i]+a[idx]>0){
			res++;
			idx--;
		}
	}
	return res;
}

int solve2(vector<int> a){
	int n=a.size();
	map<int,int> f;
	rep(i,n) ++f[a[i]];

	int res=0;
	for(auto it=f.begin();it!=f.end();++it){
		auto [x,c]=*it;
		if(x>0) break;
		if(x==0){
			res+=c/2;
		}
		else if(f.count(-x)>0) {
			res+=min(c,f[-x]);
		}
	}
	return res;
}

int main(){
	int n; scanf("%d",&n); n*=2;
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	rep(i,n) a[i]*=-1;
	printf("%d ",solve1(a));
	rep(i,n) a[i]*=-1;
	printf("%d %d\n",solve1(a),solve2(a));

	return 0;
}
