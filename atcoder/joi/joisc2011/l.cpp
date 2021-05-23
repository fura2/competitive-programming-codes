// Day 4: IOI

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k,n,m; scanf("%d%d%d",&k,&n,&m);
	vector<int> p(k);
	rep(i,k) scanf("%d",&p[i]);

	auto a=p;
	sort(a.begin(),a.end());

	auto b=a;
	rep(i,k) b[i]+=100*(n-m);

	vector<int> ans1,ans2;
	rep(i,k){
		int num=b.end()-upper_bound(b.begin(),b.end(),p[i]);
		if(m<n) num--;
		if(12*num<k){
			ans1.emplace_back(i);
		}

		num=a.end()-upper_bound(a.begin(),a.end(),p[i]+100*(n-m));
		if(12*num<k){
			ans2.emplace_back(i);
		}
	}

	rep(i,ans1.size()) printf("%d\n",ans1[i]+1);
	puts("--------");
	rep(i,ans2.size()) printf("%d\n",ans2[i]+1);

	return 0;
}
